#include <gcore/sys.hpp>



namespace state {

    static std::map<std::string, State*> states;
    static std::string currentName;

    void addState(std::string name, State* state) {
        states[name] = state;
    }

    void changeState(std::string name) {
        release();
        currentName = name;
        init();
    }

    void initialState(std::string name) {
        currentName = name;
    }
    
    void init() {
        if(states[currentName]->initCB) {
            states[currentName]->initCB();
        }
    }

    void handleEvent(SDL_Event* e) {
        if(states[currentName]->handleEventCB) {
            states[currentName]->handleEventCB(e);
        }
    }

    void update(float delta) {
        if(states[currentName]->updateCB) {
            states[currentName]->updateCB(delta);
        }
    }

    void render() {
        if(states[currentName]->renderCB) {
            states[currentName]->renderCB();
        }
    }

    void release() {
        if(states[currentName]->releaseCB) {
            states[currentName]->releaseCB();
        }
    }


}