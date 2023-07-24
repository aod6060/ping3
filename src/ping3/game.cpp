#include <ping3/game.hpp>



namespace game {
	


    static float x = 32.0f;
    static float y = 32.0f;

    static float speed = 64.0f;

    input::InputMapping escapeInput;
    input::InputMapping leftInput;
    input::InputMapping rightInput;
    input::InputMapping upInput;
    input::InputMapping downInput;

    sound::SoundFX test;

    void init() {
        escapeInput.input = input::Keyboard::KEYS_ESCAPE;
        escapeInput.isMouse = false;

        leftInput.input = input::Keyboard::KEYS_LEFT;
        leftInput.isMouse = false;

        rightInput.input = input::Keyboard::KEYS_RIGHT;
        rightInput.isMouse = false;

        upInput.input = input::Keyboard::KEYS_UP;
        upInput.isMouse = false;

        downInput.input = input::Keyboard::KEYS_DOWN;
        downInput.isMouse = false;


        sound::initSoundFX(test, "./data/sound/test.wav");
    }

    void handleEvent(SDL_Event* e) {

    }

    void update(float delta) {
        if(input::isInputMappingPressOnce(escapeInput)) {
            //sound::playSoundFX(test);
            app::exit();
        }

        if(input::isInputMappingPress(leftInput)) {
            x -= speed * delta;
        } else if(input::isInputMappingPress(rightInput)) {
            x += speed * delta;
        }

        if(input::isInputMappingPress(upInput)) {
            y -= speed * delta;
        } else if(input::isInputMappingPress(downInput)) {
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
        conf->caption = "Ping3";
        conf->width = 640;
        conf->height = 480;
        conf->initCB = init;
        conf->handleEventCB = handleEvent;
        conf->updateCB = update;
        conf->renderCB = render;
        conf->releaseCB = release;
    }

}
