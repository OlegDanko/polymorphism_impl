#pragma once

#include "BasicShapes.hpp"

#include <variant>
#include <algorithm>

using ShapeVariant_t = std::variant<Circle, AARect>;

float area(const ShapeVariant_t& shape);

ShapeVariant_t make_circle_variant(float x, float y, float r);
ShapeVariant_t make_aa_rect_variant(float x0, float y0, float x1, float y1);
