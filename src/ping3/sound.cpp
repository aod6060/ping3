#include <ping3/sys.hpp>

namespace sound {

    void init() {
        int error = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

        if(error == -1) {
            std::cout << "There is an error???" << "\n";
            std::cout << Mix_GetError() << "\n";
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
            std::cout << path << " doesn't exist!" << "\n";
        }
    }

    void playSoundFX(SoundFX& sfx) {
        int error = Mix_PlayChannel(-1, sfx.wave, 0);
        if(error == -1) {
            std::cout << "There is an error???" << "\n";
            std::cout << Mix_GetError() << "\n";
        }
    }

    void releaseSoundFX(SoundFX& sfx) {
        Mix_FreeChunk(sfx.wave);
    }

    void initMusic(Music& music, std::string path) {
        music.music = Mix_LoadMUS(path.c_str());
        if(music.music == nullptr) {
            std::cout << path << " doesn't exist!" << "\n";
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