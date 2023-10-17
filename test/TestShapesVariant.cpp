#include <boost/test/unit_test.hpp>
#include <ShapesVariant.hpp>

BOOST_AUTO_TEST_SUITE(ShapesVariantTests)

BOOST_AUTO_TEST_CASE(VariantCircleArea) {
    BOOST_CHECK_EQUAL(area(ShapeVariant_t{Circle{{0, 0}, 10}}), 100.0f*M_PIf);
}
//ShapeVariant_t
BOOST_AUTO_TEST_CASE(VariantRectArea) {
    BOOST_CHECK_EQUAL(area(ShapeVariant_t{AARect{{10, 20}, {30, 60}}}), 20.0f*40.0f);
}

BOOST_AUTO_TEST_CASE(VariantCircleCircleCollision) {
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                        ShapeVariant_t{Circle{{0, 0}, 2}}));
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 1}},
                        ShapeVariant_t{Circle{{0, 0}, 2}}));
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                        ShapeVariant_t{Circle{{0, 0}, 1}}));

    BOOST_CHECK(!collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                         ShapeVariant_t{Circle{{3, 3}, 2}}));
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                        ShapeVariant_t{Circle{{3, 3}, 2.25f}}));

    BOOST_CHECK(!collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                         ShapeVariant_t{Circle{{-3, 3}, 2}}));
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                        ShapeVariant_t{Circle{{-3, 3}, 2.25f}}));

    BOOST_CHECK(!collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                         ShapeVariant_t{Circle{{3, -3}, 2}}));
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                        ShapeVariant_t{Circle{{3, -3}, 2.25f}}));

    BOOST_CHECK(!collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                         ShapeVariant_t{Circle{{-3, -3}, 2}}));
    BOOST_CHECK(collide(ShapeVariant_t{Circle{{0, 0}, 2}},
                        ShapeVariant_t{Circle{{-3, -3}, 2.25f}}));
}

BOOST_AUTO_TEST_CASE(VariantRectRectCollision) {
    //inside
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{1, 1}, {2, 2}}}));
    //wall
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{-1, 1}, {1, 2}}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{2, 1}, {4, 2}}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{1, -1}, {2, 1}}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{1, 2}, {2, 4}}}));
    //outside wall
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{1, -2}, {2, -1}}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{4, 1}, {5, 2}}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{1, 4}, {2, 5}}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{-2, 1}, {-1, 2}}}));
    //corner
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{-1, -1}, {1, 1}}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{2, -1}, {4, 1}}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{-1, 2}, {1, 4}}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                        ShapeVariant_t{AARect{{2, 2}, {4, 4}}}));
    //outside corner
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{-2, -2}, {-1, -1}}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{4, -2}, {5, -1}}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{-2, 4}, {-1, 5}}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{0, 0}, {3, 3}}},
                         ShapeVariant_t{AARect{{4, 4}, {4, 5}}}));
}

BOOST_AUTO_TEST_CASE(VariantRectCircleCollision) {
    //inside
    BOOST_CHECK(collide(AARect{{-2, -2}, {2, 2}}, Circle{{0, 0}, 1}));
    //outside
    BOOST_CHECK(collide(AARect{{-2, -2}, {2, 2}}, Circle{{0, 0}, 2}));
    //wall
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{0, -3}, 1.5f}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{0, 3}, 1.5f}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{-3, 0}, 1.5f}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{3, 0}, 1.5f}}));
    //outside wall
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{0, -3}, 0.5f}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{0, 3}, 0.5f}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{-3, 0}, 0.5f}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{3, 0}, 0.5f}}));
    //corner
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{-3, -3}, 2.0f}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{3, -3}, 2.0f}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{-3, 3}, 2.0f}}));
    BOOST_CHECK(collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                        ShapeVariant_t{Circle{{3, 3}, 2.0f}}));
    //outside corner
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{-3, -3}, 1.0f}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{3, -3}, 1.0f}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{-3, 3}, 1.0f}}));
    BOOST_CHECK(!collide(ShapeVariant_t{AARect{{-2, -2}, {2, 2}}},
                         ShapeVariant_t{Circle{{3, 3}, 1.0f}}));
}

BOOST_AUTO_TEST_SUITE_END()
