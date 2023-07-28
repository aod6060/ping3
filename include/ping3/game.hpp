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
            PT_MAX_SIZE
        };

        struct Ball;

        struct Paddle {
            glm::vec2 position;
            glm::vec2 size;
            float yvel;
            float speed = 64.0f;
            std::function<void(Paddle*, Ball*, float)> updateCB;
        };

        struct Ball {
            glm::vec2 position;
            float size;
            glm::vec2 vel;
            glm::vec2 speed;
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


        void paddle_update(Paddle* paddle, Ball* ball, float delta);

        // Player 1
        void paddle_update_player1_controlled(Paddle* paddle, Ball* ball, float delta);
        void paddle_update_player1_expert(Paddle* paddle, Ball* ball, float delta);

        // Player 2
        void paddle_update_player2_controlled(Paddle* paddle, Ball* ball, float delta);
        void paddle_update_player2_expert(Paddle* paddle, Ball* ball, float delta);

        // Paddle Render
        void paddle_render(Paddle* paddle);

        // Get Ball based from List
        void paddle_ball_player1(Ball** out, Paddle* player1, std::vector<Ball>& balls);
        void paddle_ball_player2(Ball** out, Paddle* player1, std::vector<Ball>& balls);

        collision::Box paddle_toBox(Paddle* paddle);

        // Ball Code
        void ball_init(Ball* ball);
        void ball_update(Ball* ball, Paddle* player1, Paddle* player2, float delta);
        void ball_render(Ball* ball);

        collision::Box ball_toBox(Ball* ball);
        
    }
}

#endif
