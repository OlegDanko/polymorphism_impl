#include <iostream>
#include <chrono>
#include <ShapesMaker.hpp>
#include <ShapesVariant.hpp>

int main() {
    auto start = std::chrono::steady_clock::now();
    auto shapes = make_shapes(100000, make_circle_variant, make_aa_rect_variant);
    auto loop = std::chrono::steady_clock::now();

    for(int i = 0; i < 1000; i++)
    for(auto& s : shapes)
        area(s);

    auto collision = std::chrono::steady_clock::now();

    auto count = shapes.size()/10;
    for (size_t i = 0; i < count; ++i)
    for (size_t j = i + 1; j < count+1; ++j)
        collide(shapes.at(i), shapes.at(j));

    auto done = std::chrono::steady_clock::now();

    std::cout
        << "Init time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(loop - start).count()
        << "\nExec time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(collision - loop).count()
        << "\nCollision time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(done - collision).count()
        << std::endl;

    return 0;
}
