#pragma once

#include <cstdint>
#include <deque>
#include <optional>
#include <cstddef>

namespace ibmp {

    struct Press {
        std::uint64_t timestampMs;
        int button;
        bool player2;
    };

    class InputBuffer {
    public:
        void configure(
            std::uint32_t windowMs,
            std::size_t capacity
        );

        bool enqueue(Press press);

        std::optional<Press> takeFresh(
            std::uint64_t nowMs
        );

        void clear();

        std::size_t size() const noexcept {
            return m_queue.size();
        }

    private:
        std::deque<Press> m_queue;
        std::uint32_t m_windowMs = 35;
        std::size_t m_capacity = 4;
    };
}
