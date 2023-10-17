cmake_minimum_required(VERSION 3.5)

project(variant_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-O0")

set(SRC
    BasicShapes.cpp
    ShapesPolymorphism.cpp
)

add_executable(poly_test
    main_polymorphism.cpp
    ${SRC}
)

add_executable(variant_test
    main_variant.cpp
    ${SRC}
)
