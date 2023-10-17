cmake_minimum_required(VERSION 3.5)

project(polymorphism_impl_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB TEST_SRC
    ${SRC}
    TestBasicShapes.cpp
    TestShapesVariant.cpp
)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
add_executable(polymorphism_impl_test
    main.cpp
    ${TEST_SRC}
)
target_link_libraries(polymorphism_impl_test Boost::unit_test_framework)
target_include_directories(polymorphism_impl_test PRIVATE ../include/)
