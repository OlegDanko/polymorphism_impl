#include <iostream>
#include <chrono>
#include "ShapesMaker.hpp"
#include "ShapesVirtual.hpp"

int main() {
    auto start = std::chrono::steady_clock::now();
    auto shapes = make_shapes(1000000, make_circle, make_aa_square);
    auto loop = std::chrono::steady_clock::now();

    for(int i = 0; i < 100; i++)
    for(auto& s : shapes)
        s->area();

    auto done = std::chrono::steady_clock::now();

    std::cout
        << "Init time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(loop - start).count()
        << "\nExec time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(done - loop).count()
        << std::endl;

    return 0;
}
