#include <ping3/game.hpp>



namespace game {
	


    static float x = 32.0f;
    static float y = 32.0f;

    static float speed = 64.0f;
    
    sound::SoundFX test;

    void init() {
        sound::initSoundFX(test, "./data/sound/test.wav");
    }

    void handleEvent(SDL_Event* e) {

    }

    void update(float delta) {
        if(input::isInputMappingPressOnce(config::getConfig()->input.inputMaps["escape"])) {
            //sound::playSoundFX(test);
            app::exit();
        }

        if(input::isInputMappingPress(config::getConfig()->input.inputMaps["left"])) {
            x -= speed * delta;
        } else if(input::isInputMappingPress(config::getConfig()->input.inputMaps["right"])) {
            x += speed * delta;
        }

        if(input::isInputMappingPress(config::getConfig()->input.inputMaps["up"])) {
            y -= speed * delta;
        } else if(input::isInputMappingPress(config::getConfig()->input.inputMaps["down"])) {
            y += speed * delta;
        }
    }

    void render() {
        render::clear(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        render::beginFrame();
	
        render::setProjection(glm::ortho(0.0f, (float)app::getWidth(), (float)app::getHeight(), 0.0f));
        render::setView(glm::mat4(1.0f));
        render::setModel(
            glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f)) *
            glm::scale(glm::mat4(1.0f), glm::vec3(32.0f, 48.0f, 0.0f))		
        );

	    render::render();
	
        render::endFrame();
    }

    void release() {
        sound::releaseSoundFX(test);
    }

    void setup(app::Config* conf) {
        conf->initCB = init;
        conf->handleEventCB = handleEvent;
        conf->updateCB = update;
        conf->renderCB = render;
        conf->releaseCB = release;
    }

}
