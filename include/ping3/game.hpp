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


    // State 1
    namespace state1 {
        void init();
        void handleEvent(SDL_Event* e);
        void update(float delta);
        void render();
        void release();

        void setup(state::State* state);
    }

    // State 2
    namespace state2 {
        void init();
        void handleEvent(SDL_Event* e);
        void update(float delta);
        void render();
        void release();

        void setup(state::State* state);
    }

    // State 3
    namespace state3 {
        void init();
        void handleEvent(SDL_Event* e);
        void update(float delta);
        void render();
        void release();

        void setup(state::State* state);
    }
}

#endif