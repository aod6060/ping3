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


    namespace game_state {

        enum PaddleType {
            PT_CONTROLLED = 0,
            PT_EASY,
            PT_NORMAL,
            PT_HARD,
            PT_EXPERT,
            PT_IMPOSSIBLE,
            PT_MAX_SIZE
        };

        struct Paddle {
            glm::vec2 position;
            glm::vec2 size;
            float yvel;
            float speed = 64.0f;
            std::function<void(Paddle*, float)> updateCB;
        };


        void init();
        void handleEvent(SDL_Event* e);
        void update(float delta);
        void render();
        void release();
        void setup(state::State* state);


        // Paddle Code
        void paddle_init_player1(Paddle* paddle, PaddleType type);
        void paddle_init_player2(Paddle* paddle, PaddleType type);


        void paddle_update(Paddle* paddle, float delta);

        // Player 1
        void paddle_update_player1_controlled(Paddle* paddle, float delta);

        // Player 2
        void paddle_update_player2_controlled(Paddle* paddle, float delta);

        // Paddle Render
        void paddle_render(Paddle* paddle);


        // Ball Code

    }
}

#endif