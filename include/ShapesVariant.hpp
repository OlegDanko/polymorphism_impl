#pragma once

#include <BasicShapes.hpp>
#include <variant>
#include <algorithm>

/**
 * Usage (assuming const ref variant):
 *  template<size_t VariantIndex = 0, typename ...VariantTypes>
 *  ret_t variant_function([... ,] const std::variant<VariantTypes...>& variant [, ...]) {
 *      VARIANT_APPLY(variant,
 *                    VariantIndex,
 *                    value_function([... ,] std::get<VariantIndex>(variant) [, ...]),
 *                    variant_function<VariantIndex+1>([... ,] variant [, ...])
 *  }
 */

#define VARIANT_APPLY(var, N, code, next_code)              \
if constexpr (N+1 == std::variant_size_v<typeof(var)>) {    \
    return code;                                            \
} else {                                                    \
    if(var.index() == N) {                                  \
        return code;                                        \
    } else {                                                \
            return next_code;                               \
    }                                                       \
}

template<size_t N = 0, typename Shape_t, typename ...Shapes_t>
bool collide(const std::variant<Shapes_t...>& var, const Shape_t& s) {
    VARIANT_APPLY(var, N,
                  collide(s, std::get<N>(var)),
                  collide<N+1>(var, s))
}

template<size_t N = 0, typename ...Shapes_t>
float area(const std::variant<Shapes_t...>& var) {
    VARIANT_APPLY(var, N,
                  area(std::get<N>(var)),
                  area<N+1>(var))
}

using ShapeVariant_t = std::variant<Circle, AARect>;

ShapeVariant_t make_circle_variant(float x, float y, float r);
ShapeVariant_t make_aa_rect_variant(float x0, float y0, float x1, float y1);
