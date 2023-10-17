#include <vector>
#include <ranges>

#pragma once

template<typename MK_CIRCLE, typename MK_AASQUARE>
auto make_shapes(size_t n, MK_CIRCLE& fn_circle, MK_AASQUARE& fn_square) {
    std::vector<decltype(fn_circle(0.0f, 0.0f, 0.0f))> vec;
    float x = 0.0f,
        y = 0.0f,
        r = 1.0f,
        x0 = 0.0f,
        y0 = 0.0f,
        x1 = 1.0f,
        y1 = 1.0f;
    for(auto _ : std::views::iota(0ul, n)) {
        vec.push_back(fn_circle(x, y, r));
        x+= 1.0f;
        y+= 1.0f;
        r+= 1.0f;
        vec.push_back(fn_square(x0, y0, x1, y1));
        x0+= 1.0f;
        y0+= 1.0f;
        x0+= 2.0f;
        y0+= 2.0f;
    }
    return vec;
}
