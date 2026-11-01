#include "InputBuffer.hpp"
#include <algorithm>

namespace ibmp {

    void InputBuffer::configure(
        std::uint32_t windowMs,
        std::size_t capacity
    ) {
        m_windowMs = std::clamp(
            windowMs, 0u, 250u
        );

        m_capacity = std::clamp(
            capacity, std::size_t(1), std::size_t(16)
        );

        while (m_queue.size() > m_capacity) {
            m_queue.pop_back();
        }
    }

    bool InputBuffer::enqueue(Press press) {
        if (m_queue.size() >= m_capacity) {
            return false;
        }

        m_queue.push_back(press);
        return true;
    }

    std::optional<Press> InputBuffer::takeFresh(
        std::uint64_t nowMs
    ) {
        if (m_queue.empty()) {
            return std::nullopt;
        }

        auto press = m_queue.front();

        if (nowMs < press.timestampMs) {
            return std::nullopt;
        }

        if (nowMs - press.timestampMs > m_windowMs) {
            m_queue.pop_front();
            return std::nullopt;
        }

        m_queue.pop_front();
        return press;
    }

    void InputBuffer::clear() {
        m_queue.clear();
    }
}
