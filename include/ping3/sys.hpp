#ifndef SYS_HPP
#define SYS_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <random>
#include <filesystem>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define GLEW_NO_GLU
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>



namespace app {
    struct Config {
        std::string caption;
        uint32_t width;
        uint32_t height;

        std::function<void()> initCB;
        std::function<void(float)> updateCB;
        std::function<void()> renderCB;
        std::function<void()> releaseCB;
    };

    void init(Config* conf);
    void update();
    void release();

    uint32_t getWidth();
    uint32_t getHeight();
    void exit();
    
}

#endif