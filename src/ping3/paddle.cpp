#include <ping3/game.hpp>


namespace game {
    namespace game_state {
        void paddle_init_player1(Paddle* paddle, PaddleType type) {
            paddle->position.x = 8.0f;
            paddle->size.x = 8.0f;
            paddle->size.y = 64.0f;
            paddle->position.y = app::getHeight() / 2.0f - paddle->size.y / 2.0f;
            paddle->yvel = 0.0f;
	    paddle->speed = 256.0f;
            paddle->updateCB = paddle_update_player1_controlled;

            if(type == PaddleType::PT_EXPERT) {
                paddle->updateCB = paddle_update_player1_expert;
            }
        }

        void paddle_init_player2(Paddle* paddle, PaddleType type) {
            paddle->position.x = app::getWidth() - 8.0f * 2.0f;
            paddle->size.x = 8.0f;
            paddle->size.y = 64.0f;
            paddle->position.y = app::getHeight() / 2.0f - paddle->size.y / 2.0f;
            paddle->yvel = 0.0f;
	    paddle->speed = 256.0f;
            paddle->updateCB = paddle_update_player2_controlled;

            if(type == PaddleType::PT_EXPERT) {
                paddle->updateCB = paddle_update_player2_expert;
            }
        }

        void paddle_update(Paddle* paddle, Ball* ball, float delta) {
            paddle->updateCB(paddle, ball, delta);
        }

        // Player 1
        void paddle_update_player1_controlled(Paddle* paddle, Ball* ball, float delta) {
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

        void paddle_update_player1_expert(Paddle* paddle, Ball* ball, float delta) {
            if(ball->position.y + ball->size < paddle->position.y) {
                if(paddle->position.y > 0.0) {
                    paddle->yvel = -1.0f;
                } else {
                    paddle->yvel = 0.0f;
                }
            } else if(ball->position.y > paddle->position.y + paddle->size.y) {
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
        void paddle_update_player2_controlled(Paddle* paddle, Ball* ball, float delta) {
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
        
        void paddle_update_player2_expert(Paddle* paddle, Ball* ball, float delta) {
            if(ball->position.y + ball->size < paddle->position.y) {
                if(paddle->position.y > 0.0) {
                    paddle->yvel = -1.0f;
                } else {
                    paddle->yvel = 0.0f;
                }
            } else if(ball->position.y > paddle->position.y + paddle->size.y) {
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

        void paddle_ball_player1(Ball** out, Paddle* player1, std::vector<Ball>& balls) {
            *out = &balls[0];
            for(int i = 1; i < balls.size(); i++) {
                if((*out)->vel.x < 0) {
                    if(balls[i].vel.x < 0) {

			if((*out)->position.x > balls[i].position.x) {
                            	*out = &balls[i];
                        } else {
                        	continue;
                        }


                    } else {
                        continue;
                    }
                } else {
                    *out = &balls[i];
                }
            }
        }

        void paddle_ball_player2(Ball** out, Paddle* player1, std::vector<Ball>& balls) {
            *out = &balls[0];

            for(int i = 1; i < balls.size(); i++) {
                if((*out)->vel.x > 0.0f) {
                    if(balls[i].vel.x > 0.0f) {
                        if((*out)->position.x < balls[i].position.x) {
                            *out = &balls[i];
                        } else {
                            continue;
                        }
                    } else {
                        continue;
                    }
                } else {
                    *out = &balls[i];
                }
            }
        }

        collision::Box paddle_toBox(Paddle* paddle) {
            collision::Box temp;
            collision::box_init(temp, paddle->position, paddle->size);
            return temp;
        }
    }
}
