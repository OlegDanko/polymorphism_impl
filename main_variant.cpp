#include <iostream>
#include "ShapesMaker.hpp"
#include "ShapesVariant.hpp"

int main() {
    auto shapes = make_shapes(10000, make_circle_variant, make_aa_rect_variant);
    double total_area_diff = 0.0f;

    for (size_t a = 0; a < shapes.size() - 1; ++a) {
        for (size_t b = a + 1; b < shapes.size(); ++b) {
            total_area_diff += std::abs(area(shapes.at(a)) - area(shapes.at(b)));
        }
    }

//    std::cout << total_area_diff << std::endl;

    return (int)total_area_diff;
}
