#include <ShapesUnion.hpp>

float area(const ShapeUnion &shape) {
    switch(shape.e_shape) {
    case EShape::CIRCLE:
        return area(shape.shape.circle);
    case EShape::AARECT:
        return area(shape.shape.rect);
    default:
        return {};
    }
}

ShapeUnion make_circle_union(float x, float y, float r) {
    return {.e_shape = EShape::CIRCLE, .shape{.circle = {x, y, r}}};
}

ShapeUnion make_aa_rect_union(float x0, float y0, float x1, float y1) {
    auto [x_0, x_1] = std::minmax(x0, x1);
    auto [y_0, y_1] = std::minmax(y0, y1);
    return {.e_shape = EShape::AARECT, .shape{.rect = {{x0, y0}, {x1, y1}}}};
}
