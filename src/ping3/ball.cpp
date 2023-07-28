#include <ping3/game.hpp>


namespace game {
    namespace game_state {
        
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
            /*
            ball->speed.x += util::getRandom(-9, 9);
            ball->speed.y += util::getRandom(-9, 9);
            */
        }

        void ball_init(Ball* ball) {
            ball->size = 16.0f;
            _ball_reset(ball);
        }

        void ball_update(Ball* ball,  Paddle* player1, Paddle* player2, float delta) {
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
