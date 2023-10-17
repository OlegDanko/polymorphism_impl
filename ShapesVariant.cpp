#include "ShapesVariant.hpp"

float area(const ShapeVariant_t &shape) {
    switch(shape.index()) {
    case 0:
        return area(std::get<0>(shape));
    case 1:
        return area(std::get<1>(shape));
    default:
        return {};
    }
}

ShapeVariant_t make_circle_variant(float x, float y, float r) {
    return {Circle{x, y, r}};
}

ShapeVariant_t make_aa_rect_variant(float x0, float y0, float x1, float y1) {
    auto [x_0, x_1] = std::minmax(x0, x1);
    auto [y_0, y_1] = std::minmax(y0, y1);
    return {AARect{{x0, y0}, {x1, y1}}};
}
