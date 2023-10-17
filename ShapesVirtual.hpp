#pragma once

#include "BasicShapes.hpp"
#include <memory>
#include <algorithm>

struct IGeneralShape {
    virtual ~IGeneralShape() = default;
    virtual float area() const = 0;
};

struct CircleShape : IGeneralShape {
    Circle shape;
    CircleShape(const Circle& circle);
    float area() const override;
};

struct AARectShape : IGeneralShape {
    AARect shape;
    AARectShape(AARect rect);
    float area() const override;
};

std::unique_ptr<IGeneralShape> make_circle(float x, float y, float r);
std::unique_ptr<IGeneralShape> make_aa_square(float x0,
                                              float y0,
                                              float x1,
                                              float y1);
