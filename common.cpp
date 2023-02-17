#include <vector>
#include "common.h"

std::vector<int> interpolate(int i0, float d0, int i1, float d1)
{
    if (i0 == i1) {  // ex: vertical line
        return std::vector<int>(1, d0);
    }

    std::vector<int> values;
    const float a = (d1 - d0) / (i1 - i0);  // calculate a(essentially slope)
    float d = d0;
    for (int i = i0; i < i1; i++) {
        values.push_back(d);
        d += a;
    }

    return values;
}
