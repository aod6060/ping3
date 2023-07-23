#include <gcore/sys.hpp>

namespace sound {

    void init() {
        int error = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

        if(error == -1) {
           logger::output(logger::LoggerType::LT_ERROR, [&](std::stringstream& ss) {
                ss << Mix_GetError();
           });
        }
    }

    void update() {
        Mix_PlayingMusic();
        Mix_Playing(-1);
    }

    void release() {
        Mix_CloseAudio();
    }

    void initSoundFX(SoundFX& sfx, std::string path) {
        sfx.wave = Mix_LoadWAV(path.c_str());
        if(sfx.wave == nullptr) {
            logger::output(logger::LoggerType::LT_ERROR, [&](std::stringstream& ss) {
                ss << path << " doesn't exist!";
           });
        }
    }

    void playSoundFX(SoundFX& sfx) {
        int error = Mix_PlayChannel(-1, sfx.wave, 0);
        if(error == -1) {
           logger::output(logger::LoggerType::LT_ERROR, [&](std::stringstream& ss) {
                ss << Mix_GetError();
           });
        }
    }

    void releaseSoundFX(SoundFX& sfx) {
        Mix_FreeChunk(sfx.wave);
    }

    void initMusic(Music& music, std::string path) {
        music.music = Mix_LoadMUS(path.c_str());
        if(music.music == nullptr) {
            logger::output(logger::LoggerType::LT_ERROR, [&](std::stringstream& ss) {
                ss << path << " doesn't exist!";
           });
        }
    }

    void playMusic(Music& music) {
        Mix_PlayMusic(music.music, 0);
    }

    void stopMusic() {
        Mix_HaltMusic();
    }

    void releaseMusic(Music& music) {
        Mix_FreeMusic(music.music);
    }

}