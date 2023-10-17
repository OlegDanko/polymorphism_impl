cmake_minimum_required(VERSION 3.5)

project(polymorphism_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC
    BasicShapes.cpp
    ShapesVirtual.cpp
    ShapesVariant.cpp
    ShapesUnion.cpp
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable(dynamic_polymorphism
    main_virtual.cpp
    ${SRC}
)

add_executable(variant_polymorphism
    main_variant.cpp
    ${SRC}
)

add_executable(union_polymorphism
    main_union.cpp
    ${SRC}
)
