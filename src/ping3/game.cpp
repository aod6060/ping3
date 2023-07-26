#include <ping3/game.hpp>



namespace game {
	
    static state::State _state1;
    static state::State _state2;
    static state::State _state3;


    void init() {
        // Setup States
        state1::setup(&_state1);
        state2::setup(&_state2);
        state3::setup(&_state3);

        state::addState("state1", &_state1);
        state::addState("state2", &_state2);
        state::addState("state3", &_state3);

        state::initialState("state1");

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
