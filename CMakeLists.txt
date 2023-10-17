cmake_minimum_required(VERSION 3.5)

project(variant_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O2")

set(SRC
    BasicShapes.cpp
)

add_executable(virtual_test
    main_virtual.cpp
    ShapesVirtual.cpp
    ${SRC}
)

add_executable(variant_test
    main_variant.cpp
    ShapesVariant.cpp
    ${SRC}
)

add_executable(union_test
    main_union.cpp
    ShapesUnion.cpp
    ${SRC}
)
