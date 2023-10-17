cmake_minimum_required(VERSION 3.5)

project(polymorphism_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O2")

set(SRC
    BasicShapes.cpp
)

add_executable(dynamic_polymorphism
    main_virtual.cpp
    ShapesVirtual.cpp
    ${SRC}
)

add_executable(variant_polymorphism
    main_variant.cpp
    ShapesVariant.cpp
    ${SRC}
)

add_executable(union_polymorphism
    main_union.cpp
    ShapesUnion.cpp
    ${SRC}
)
