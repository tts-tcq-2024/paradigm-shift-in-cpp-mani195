#pragma once

namespace utils
{
    inline bool isInRange(_Float32 actual, _Float32 min, _Float32 max)
    {
        return ((actual >= min) && (actual <= max));
    }
}
