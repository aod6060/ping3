#include <ping3/game.hpp>


namespace game {
    namespace game_state {
       
	std::map<BallType, std::function<void(Ball*, Paddle*, Paddle*, float)>> ballAIType = {
		{BallType::BT_NORMAL, ball_update_ai_normal},
		{BallType::BT_CRAZY, ball_update_ai_crazy}	
	};

        void _ball_reset(Ball* ball) {
            ball->position = glm::vec2(
                app::getWidth() / 2.0f - ball->size / 2.0f,
                app::getHeight() / 2.0f - ball->size / 2.0f
            );

            float angle = (float)util::getRandom(90+45, 270-45);

            if(util::getRandom(2) == 1) {
                angle = util::getRandom(90+45 + 180, 270-45 + 180);
            }

            ball->vel = glm::vec2(
                //(util::getRandom(2) == 1) ? -1.0f : 1.0f,
                glm::cos(glm::radians(angle)),
                glm::sin(glm::radians(angle))
                //(util::getRandom(2) == 1) ? -1.0f : 1.0f
            );

            //ball->speed = glm::vec2();
            ball->speed = glm::vec2(32.0f);

	    ball->ballTime = glm::vec2(0.0f);
	    ball->ballSpeedTime = glm::vec2(0.0f);
	    ball->ballTeleportTime = 0.0f;
            /*
            ball->speed.x += util::getRandom(-9, 9);
            ball->speed.y += util::getRandom(-9, 9);
            */
        }

        void ball_init(Ball* ball, BallType ballType) {
            ball->size = 16.0f;
	    ball->updateCB = ballAIType[ballType];
            _ball_reset(ball);
        }

        void ball_update(Ball* ball,  Paddle* player1, Paddle* player2, float delta) {
		ball->updateCB(ball, player1, player2, delta);       
	}


	void ball_update_ai_normal(Ball* ball, Paddle* player1, Paddle* player2, float delta) {
            if(ball->position.y < 0.0f) {
                ball->vel.y = 1;
            } else if(ball->position.y + ball->size > app::getHeight()) {
                ball->vel.y = -1;
            }

            if(ball->position.x + ball->size < 0.0f) {
                _ball_reset(ball);
            } else if(ball->position.x > app::getWidth()) {
                _ball_reset(ball);
            }
	    
	    collision::Box bbox = ball_toBox(ball);
	    collision::Box p1box = paddle_toBox(player1);
	    collision::Box p2box = paddle_toBox(player2);
	    
	    if(collision::box_collision_lt(bbox, p1box)) {
		ball->vel.x = 1.0f;
		ball->speed.x *= 2.0f;
	    }

	    if(collision::box_collision_lt(bbox, p2box)) {
		ball->vel.x = -1.0f;
		ball->speed.x *= 2.0f;
	    }

            ball->position.x += ball->vel.x * ball->speed.x * delta;
            ball->position.y += ball->vel.y * ball->speed.y * delta;
	}

	void ball_update_ai_crazy(Ball* ball, Paddle* player1, Paddle* player2, float delta) {
		//ball->vel.x = (util::getRandom(2) == 1) ? -1.0f : 1.0f;
		//ball->vel.y = (util::getRandom(2) == 1) ? -1.0f : 1.0f;

		//ball->speed.x
		if(ball->ballTime.x <= 0.0f) {
			uint32_t v = util::getRandom(3);

			if(v == 0) {
				ball->vel.x = -1.0f;
			} else if(v == 1) {
				ball->vel.x = 1.0f;
			} else {
				ball->vel.x = 0.0f;
			}

			ball->ballTime.x = util::getRandom(5);
		} else {
			ball->ballTime.x -= delta;
		}

		if(ball->ballTime.y <= 0.0f) {
			uint32_t v = util::getRandom(3);

			if(v == 0) {
				ball->vel.y = -1.0f;
			} else if(v == 1) {
				ball->vel.y = 1.0f;
			} else {
				ball->vel.y = 0.0f;
			}

			ball->ballTime.y = util::getRandom(5);

		} else {
			ball->ballTime.y -= delta;
		}
		
		
		if(ball->ballSpeedTime.x <= 0.0f) {
			ball->speed.x = 32.0f * util::getRandom(5);
			ball->ballSpeedTime.x = util::getRandom(5);

		} else {
			ball->ballSpeedTime.x -= delta;
		}

		if(ball->ballSpeedTime.y <= 0.0f) {
			ball->speed.y = 32.0f * util::getRandom(5);
			ball->ballSpeedTime.x = util::getRandom(5);
		} else {
			ball->ballSpeedTime.y -= delta;
		}
		
		if(ball->ballTeleportTime <= 0.0f) {
			ball->position.x = util::getRandom(app::getWidth() * 0.25f, app::getWidth() * 0.75f);
			ball->position.y = util::getRandom(app::getHeight() * 0.25f, app::getHeight() * 0.75f);
			ball->ballTeleportTime = (util::getRandom(100 - 50)) + 50;
		} else {
			ball->ballTeleportTime -= delta;
		}
		
			
		if(ball->position.y < 0.0f || ball->position.y + ball->size > app::getHeight()) {
			ball->vel.y = -(ball->vel.y * ball->speed.y * delta);
		}

		if(ball->position.x + ball->size < 0.0f || ball->position.x > app::getWidth()) {
			_ball_reset(ball);
		}


	    	collision::Box bbox = ball_toBox(ball);
	    	collision::Box p1box = paddle_toBox(player1);
	    	collision::Box p2box = paddle_toBox(player2);
	    
	    	if(collision::box_collision_lt(bbox, p1box)) {
			ball->vel.x = 1.0f;
	    	}

	    	if(collision::box_collision_lt(bbox, p2box)) {
			ball->vel.x = -1.0f;
	    	}

		
            	ball->position.x += ball->vel.x * ball->speed.x * delta;
            	ball->position.y += ball->vel.y * ball->speed.y * delta;
	}

        void ball_render(Ball* ball) {
            render::setModel(
                glm::translate(glm::mat4(1.0f), glm::vec3(ball->position, 0.0f)) *
                glm::scale(glm::mat4(1.0f), glm::vec3(ball->size, ball->size, 0.0f))
            );
            render::render();
        }

        collision::Box ball_toBox(Ball* ball) {
            collision::Box temp;
            collision::box_init(temp, ball->position, glm::vec2(ball->size, ball->size));
            return temp;
        }
    }
}
