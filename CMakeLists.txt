cmake_minimum_required(VERSION 3.5)

project(polymorphism_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC
    src/BasicShapes.cpp
    src/ShapesVirtual.cpp
    src/ShapesVariant.cpp
    src/ShapesUnion.cpp
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable(dynamic_polymorphism
    src/main_virtual.cpp
    ${SRC}
)

add_executable(variant_polymorphism
    src/main_variant.cpp
    ${SRC}
)

add_executable(union_polymorphism
    src/main_union.cpp
    ${SRC}
)

target_include_directories(dynamic_polymorphism PRIVATE include/)
target_include_directories(variant_polymorphism PRIVATE include/)
target_include_directories(union_polymorphism PRIVATE include/)
