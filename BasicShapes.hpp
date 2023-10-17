#pragma once
#include <cmath>

template<typename T>
T sqr(const T& val) {
    return val*val;
}
template<typename T>
T dist_sqr(const T& ax, const T& ay, const T& bx, const T& by) {
    return sqr(ax - bx) + sqr(ay - by);
}

struct Point {
    float x, y;
};

float dist_sqr(const Point& a, const Point& b);

struct Circle {
    Point pos;
    float r;
};
float area(const Circle& c);

struct AARect {
    Point pos_bottom_left, pos_top_right;
};
float area(const AARect& r);

bool points_dist_less_than(const Point& a, const Point& b, float d);

bool collide(const Circle& c0, const Circle& c1);

bool collide(const AARect& r0, const AARect& r1);

bool collide(const Circle& c, const AARect& r);

bool collide(const AARect& r, const Circle& c);
