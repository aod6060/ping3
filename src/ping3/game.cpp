#include <ping3/game.hpp>



namespace game {

    int i = 0;
    sound::SoundFX testSFX;
    sound::Music testMUS;

    void init() {
        sound::initSoundFX(testSFX, "./data/sound/test.wav");
        sound::initMusic(testMUS, "./data/sound/test_mus.mp3");
    }

    void update(float delta) {

        if(input::isKeyPressOnce(input::Keyboard::KEYS_LEFT)) {
            sound::playSoundFX(testSFX);
        }

        if(input::isKeyPressOnce(input::Keyboard::KEYS_RIGHT)) {
            sound::playMusic(testMUS);
        }

        if(input::isKeyPressOnce(input::Keyboard::KEYS_UP)) {
            sound::stopMusic();
        }
    }

    void render() {

    }

    void release() {
        sound::releaseMusic(testMUS);
        sound::releaseSoundFX(testSFX);
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