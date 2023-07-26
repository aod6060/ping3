#include <ping3/game.hpp>



namespace game {

    namespace state3 {
        void init() {

        }

        void handleEvent(SDL_Event* e) {

        }

        void update(float delta) {
            // Previous
            if(input::isInputMappingPressOnce(config::getConfig()->input.inputMaps["left"])) {
                state::changeState("state2");
            }
            // Next
            if(input::isInputMappingPressOnce(config::getConfig()->input.inputMaps["right"])) {
                state::changeState("state1");
            }
        }

        void render() {
            render::clear(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
            render::beginFrame();
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