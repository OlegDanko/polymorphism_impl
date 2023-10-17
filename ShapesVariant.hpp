#pragma once

#include "BasicShapes.hpp"

#include <variant>
#include <algorithm>

using ShapeVariant_t = std::variant<Circle, AARect>;

template<typename S>
bool collide(const ShapeVariant_t& shape, const S& s) {
    switch(shape.index()) {
    case 0:
        return collide(s, std::get<0>(shape));
    case 1:
        return collide(s, std::get<1>(shape));
    default:
        return {};
    }
}

float area(const ShapeVariant_t& shape);

ShapeVariant_t make_circle_variant(float x, float y, float r);
ShapeVariant_t make_aa_rect_variant(float x0, float y0, float x1, float y1);
