#include <ping3/game.hpp>



namespace game {

    int i = 0;

    void init() {

    }

    void update(float delta) {
        
    }

    void render() {

    }

    void release() {

    }

    void setup(app::Config* conf) {
        conf->caption = "Ping3";
        conf->width = 640;
        conf->height = 480;
        conf->initCB = init;
        conf->updateCB = update;
        conf->renderCB = render;
        conf->releaseCB = release;
    }

}