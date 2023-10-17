#include <ShapesVirtual.hpp>
#include <iostream>

CircleShape::CircleShape(const Circle &circle) : shape(circle) {}

float CircleShape::area() const {
    return ::area(shape);
}

AARectShape::AARectShape(AARect rect) : shape(rect) {}

float AARectShape::area() const {
    return ::area(shape);
}

std::unique_ptr<IGeneralShape> make_circle(float x, float y, float r) {
    return std::make_unique<CircleShape>(Circle{x, y, r});
}

std::unique_ptr<IGeneralShape> make_aa_square(float x0, float y0, float x1, float y1) {
    auto [x_0, x_1] = std::minmax(x0, x1);
    auto [y_0, y_1] = std::minmax(y0, y1);
    return std::make_unique<AARectShape>(AARect{{x_0, y_0}, {x_1, y_1}});
}
