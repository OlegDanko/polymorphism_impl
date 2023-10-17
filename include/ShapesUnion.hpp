#pragma once

#include <BasicShapes.hpp>
#include <algorithm>

enum class EShape {
    CIRCLE,
    AARECT
};

struct ShapeUnion {
    EShape e_shape;
    union {
        AARect rect;
        Circle circle;
    } shape;
};

template<typename S>
bool collide(const ShapeUnion& shape, const S& s) {
    switch(shape.e_shape) {
    case EShape::CIRCLE:
        return collide(s, shape.shape.circle);
    case EShape::AARECT:
        return collide(s, shape.shape.rect);
    default:
        return {};
    }
}

float area(const ShapeUnion& shape);

ShapeUnion make_circle_union(float x, float y, float r);
ShapeUnion make_aa_rect_union(float x0, float y0, float x1, float y1);
