#pragma once

#include <vector>
#include <cstdint>

namespace ibmp {

struct ReplayFrame {
    std::uint64_t frame;
    int button;
    bool pressed;
    bool player2;
};

class Replay {
public:
    void clear() noexcept;
    void add(std::uint64_t frame, int button, bool pressed, bool player2);
    void shift(std::int64_t frames);

    [[nodiscard]] std::size_t size() const noexcept;
    [[nodiscard]] const std::vector<ReplayFrame>& frames() const noexcept;

private:
    std::vector<ReplayFrame> m_frames;
};

}
