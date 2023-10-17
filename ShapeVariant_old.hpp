#pragma once

#include "BasicShapes.hpp"

#include <variant>
#include <algorithm>

using ShapeVariant_t = std::variant<Circle, AARect>;

#define for_appropriate_index(code, next_code)                  \
if(var.index() == N) {                                          \
    return code;                                                \
} else {                                                        \
    if constexpr (N+1 == std::variant_size_v<typeof(var)>) {    \
        return {};                                              \
    } else {                                                    \
        return next_code;                                       \
    }                                                           \
}

template<size_t N = 0, typename S, typename ...Ts>
bool collide(const std::variant<Ts...>& var, const S& s) {
    for_appropriate_index(
        collide(s, std::get<N>(var)),
        collide<N+1>(var, s))
}

template<size_t N = 0, typename ...Ts>
float area(const std::variant<Ts...>& var) {
    for_appropriate_index(
        area(std::get<N>(var)),
        area<N+1>(var))
}

ShapeVariant_t make_circle_variant(float x, float y, float r) {
    return {Circle{x, y, r}};
}
ShapeVariant_t make_aa_rect_variant(float x0, float y0, float x1, float y1) {
    auto [x_0, x_1] = std::minmax(x0, x1);
    auto [y_0, y_1] = std::minmax(y0, y1);
    return {AARect{{x0, y0}, {x1, y1}}};
}
