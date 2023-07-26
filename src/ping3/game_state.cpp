#include <ping3/game.hpp>


namespace game {

    namespace game_state {
        static Paddle player1;
        static Paddle player2;

        void init() {
            paddle_init_player1(&player1, PaddleType::PT_CONTROLLED);
            paddle_init_player2(&player2, PaddleType::PT_CONTROLLED);
        }

        void handleEvent(SDL_Event* e) {

        }

        void update(float delta) {
            if(input::isInputMappingPressOnce(config::getConfig()->input.inputMaps["escape"])) {
                app::exit();
            }

            paddle_update(&player1, delta);
            paddle_update(&player2, delta);
        }

        void render() {
            render::clear(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
            render::beginFrame();

            render::setProjection(glm::ortho(0.0f, (float)app::getWidth(), (float)app::getHeight(), 0.0f));
            render::setView(glm::mat4(1.0f));

            // Render Paddles
            paddle_render(&player1);
            paddle_render(&player2);
            
            render::endFrame();
        }

        void release() {

        }

        void setup(state::State* state) {
            state->initCB = init;
            state->handleEventCB = handleEvent;
            state->updateCB = update;
            state->renderCB = render;
            state->releaseCB = release;
        }
    }
}