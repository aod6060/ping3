#include <ping3/game.hpp>


namespace game {
    namespace game_state {
        void paddle_init_player1(Paddle* paddle, PaddleType type) {
            paddle->position.x = 8.0f;
            paddle->size.x = 8.0f;
            paddle->size.y = 64.0f;
            paddle->position.y = app::getHeight() / 2.0f - paddle->size.y / 2.0f;
            paddle->yvel = 0.0f;
            paddle->updateCB = paddle_update_player1_controlled;
        }

        void paddle_init_player2(Paddle* paddle, PaddleType type) {
            paddle->position.x = app::getWidth() - 8.0f * 2.0f;
            paddle->size.x = 8.0f;
            paddle->size.y = 64.0f;
            paddle->position.y = app::getHeight() / 2.0f - paddle->size.y / 2.0f;
            paddle->yvel = 0.0f;
            paddle->updateCB = paddle_update_player2_controlled;
        }

        void paddle_update(Paddle* paddle, float delta) {
            paddle->updateCB(paddle, delta);
        }

        // Player 1
        void paddle_update_player1_controlled(Paddle* paddle, float delta) {
            if(input::isInputMappingPress(config::getConfig()->input.inputMaps["player-1-up"])) {
                if(paddle->position.y > 0.0f) {
                    paddle->yvel = -1.0f;
                } else {
                    paddle->yvel = 0.0f;
                }
            } else if(input::isInputMappingPress(config::getConfig()->input.inputMaps["player-1-down"])) {
                if(paddle->position.y + paddle->size.y < app::getHeight()) {
                    paddle->yvel = 1.0f;
                } else {
                    paddle->yvel = 0.0f;
                }
            } else {
                paddle->yvel = 0.0f;
            }

            paddle->position.y += paddle->yvel * paddle->speed * delta;
        }

        // Player 2
        void paddle_update_player2_controlled(Paddle* paddle, float delta) {
            if(input::isInputMappingPress(config::getConfig()->input.inputMaps["player-2-up"])) {
                if(paddle->position.y > 0.0f) {
                    paddle->yvel = -1.0f;
                } else {
                    paddle->yvel = 0.0f;
                }
            } else if(input::isInputMappingPress(config::getConfig()->input.inputMaps["player-2-down"])) {
                if(paddle->position.y + paddle->size.y < app::getHeight()) {
                    paddle->yvel = 1.0f;
                } else {
                    paddle->yvel = 0.0f;
                }
            } else {
                paddle->yvel = 0.0f;
            }

            paddle->position.y += paddle->yvel * paddle->speed * delta;
        }
        
        void paddle_render(Paddle* paddle) {
            render::setModel(
                glm::translate(glm::mat4(1.0f), glm::vec3(paddle->position, 0.0f)) *
                glm::scale(glm::mat4(1.0f), glm::vec3(paddle->size, 0.0f))
            );
            render::render();
        }

    }
}