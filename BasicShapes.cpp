#include "BasicShapes.hpp"

float dist_sqr(const Point &a, const Point &b) {
    return dist_sqr(a.x, a.y, b.x, b.y);
}

float area(const Circle &c) { return M_PI*sqr(c.r); }

float area(const AARect &r) {
    return (r.pos_top_right.x - r.pos_bottom_left.x) *
           (r.pos_top_right.y - r.pos_bottom_left.y); }

bool points_dist_less_than(const Point &a, const Point &b, float d) {
    return dist_sqr(a, b) < sqr(d);
}

bool collide(const Circle &c0, const Circle &c1) {
    return points_dist_less_than(c0.pos, c1.pos, c0.r + c1.r);
}

bool collide(const AARect &r0, const AARect &r1) {
    return !(r0.pos_bottom_left.x > r1.pos_top_right.x
             || r1.pos_bottom_left.x > r0.pos_top_right.x
             || r0.pos_bottom_left.y > r1.pos_top_right.y
             || r1.pos_bottom_left.y > r0.pos_top_right.y);
}

bool collide(const Circle &c, const AARect &r) {
    bool left = c.pos.x < r.pos_bottom_left.x;
    bool right = c.pos.x > r.pos_top_right.x;
    bool below = c.pos.y < r.pos_bottom_left.y;
    bool above = c.pos.y > r.pos_bottom_left.y;

    if(left) {
        if(below)
            return points_dist_less_than(c.pos, r.pos_bottom_left, c.r);
        if(above)
            return points_dist_less_than(c.pos, {r.pos_bottom_left.x, r.pos_top_right.y}, c.r);
        return r.pos_bottom_left.x - c.pos.x < c.r;
    }
    if(right) {
        if(below)
            return points_dist_less_than(c.pos, {r.pos_top_right.x, r.pos_bottom_left.y}, c.r);
        if(above)
            return points_dist_less_than(c.pos, r.pos_top_right, c.r);
        return c.pos.x - r.pos_top_right.x < c.r;
    }
    if(below)
        return r.pos_bottom_left.y - c.pos.y < c.r;
    if(above)
        return c.pos.y - r.pos_top_right.y < c.r;

    return true;
}

bool collide(const AARect &r, const Circle &c) {
    return collide(c, r);
}
