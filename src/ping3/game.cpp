#include <ping3/game.hpp>



namespace game {

    static state::State _gameState;

    void init() {
        game_state::setup(&_gameState);

        state::addState("game-state", &_gameState);
        state::initialState("game-state");
        
        state::init();
    }

    void handleEvent(SDL_Event* e) {
        state::handleEvent(e);
    }

    void update(float delta) {
        state::update(delta);
    }

    void render() {
        state::render();
    }

    void release() {
        state::release();
    }

    void setup(app::Config* conf) {
        conf->initCB = init;
        conf->handleEventCB = handleEvent;
        conf->updateCB = update;
        conf->renderCB = render;
        conf->releaseCB = release;
    }

}
