#include "Replay.hpp"

#include <algorithm>

namespace ibmp {

void Replay::clear() noexcept {
    m_frames.clear();
}

void Replay::add(std::uint64_t frame, int button, bool pressed, bool player2) {
    m_frames.push_back({frame, button, pressed, player2});
}

void Replay::shift(std::int64_t frames) {
    for (auto& event : m_frames) {
        if (frames < 0 && static_cast<std::uint64_t>(-frames) > event.frame) {
            event.frame = 0;
        } else {
            event.frame = static_cast<std::uint64_t>(
                static_cast<std::int64_t>(event.frame) + frames
            );
        }
    }

    std::sort(m_frames.begin(), m_frames.end(), [](const ReplayFrame& a, const ReplayFrame& b) {
        return a.frame < b.frame;
    });
}

std::size_t Replay::size() const noexcept {
    return m_frames.size();
}

const std::vector<ReplayFrame>& Replay::frames() const noexcept {
    return m_frames;
}

}
