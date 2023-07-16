#ifndef GAME_HPP
#define GAME_HPP

#include "sys.hpp"

namespace game {

    void init();
    void update(float delta);
    void render();
    void release();

    void setup(app::Config* conf);
}
#endif