#ifndef GAME_HPP
#define GAME_HPP

#include <gcore/sys.hpp>

namespace game {

    void init();
    void handleEvent(SDL_Event* e);
    void update(float delta);
    void render();
    void release();

    void setup(app::Config* conf);
}

#endif