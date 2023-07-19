#include <ping3/sys.hpp>


namespace collision {

    void box_init(Box& b, const glm::vec2& p, const glm::vec2& s) {
        b.position = p;
        b.size = s;
    }

    // Left Top Midpoint
    float box_left_lt(Box& b) {
        return b.position.x;
    }

    float box_right_lt(Box& b) {
        return b.position.x + b.size.x;
    }

    float box_top_lt(Box& b) {
        return b.position.y;
    }

    float box_bottom_lt(Box& b) {
        return b.size.y;
    }
    
    bool box_collision_lt(Box& a, Box& b) {
        return (
            box_left_lt(a) < box_right_lt(b) &&
            box_right_lt(a) > box_left_lt(b) &&
            box_top_lt(a) < box_bottom_lt(b) &&
            box_bottom_lt(a) > box_top_lt(b)
        );
    }

    // Center Midpoint
    float box_left_center(Box& b) {
        return b.position.x - (b.size.x * 0.5f);
    }

    float box_right_center(Box& b) {
        return b.position.x + (b.size.x * 0.5f);
    }

    float box_top_center(Box& b) {
        return b.position.y - (b.size.y * 0.5f);
    }

    float box_bottom_center(Box& b) {
        return b.position.y + (b.size.y * 0.5f);
    }

    bool box_collision_center(Box& a, Box& b) {        
        return (
            box_left_center(a) < box_right_center(b) &&
            box_right_center(a) > box_left_center(b) &&
            box_top_center(a) < box_bottom_center(b) &&
            box_bottom_center(a) > box_top_center(b)
        );
    }

    bool box_collision(CollisionCheckType checkType, Box& a, Box& b) {
        if(checkType == CollisionCheckType::CCT_LEFT_TOP) {
            return box_collision_lt(a, b);
        } else if(checkType == CollisionCheckType::CCT_CENTER) {
            return box_collision_center(a, b);
        }
        return false;
    }
}