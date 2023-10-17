#include <iostream>
#include "ShapesMaker.hpp"
#include "ShapesPolymorphism.hpp"

int main() {
    auto shapes = make_shapes(10000, make_circle, make_aa_square);
    double total_area_diff = 0.0f;

    for (size_t a = 0; a < shapes.size() - 1; ++a) {
        for (size_t b = a + 1; b < shapes.size(); ++b) {
            total_area_diff += std::abs(shapes.at(a)->area() - shapes.at(b)->area());
        }
    }

    return (int)total_area_diff;
}
