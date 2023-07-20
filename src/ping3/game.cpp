#include <ping3/game.hpp>



namespace game {

    void init() {
    }

    void update(float delta) {
    }

    void render() {
        render::clear(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        render::beginFrame();

        render::endFrame();
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