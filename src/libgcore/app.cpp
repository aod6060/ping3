#include <gcore/sys.hpp>


namespace app {
    

    Config* _conf;
    bool _running = true;

    SDL_Window* _window = nullptr;
    SDL_GLContext _context = nullptr;

    void init(Config* conf) {
        _conf = conf;

        config::init();

        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

        _window = SDL_CreateWindow(
            _conf->caption.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            _conf->width,
            _conf->height,
            SDL_WINDOW_OPENGL
        );

        _context = SDL_GL_CreateContext(_window);
        glewInit();

        logger::init();
        input::init();
        sound::init();
        render::init();

        if(_conf->initCB) {
            _conf->initCB();
        }
    }

    void update() {
        // SDL Event
        SDL_Event e;
        // Timing
        uint32_t preTime = SDL_GetTicks();
        uint32_t currTime = 0;
        float delta = 0.0f;

        while(_running) {

            currTime = SDL_GetTicks();
            delta = (currTime - preTime) / 1000.0f;
            preTime = currTime;

            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT) {
                    _running = false;
                }

                input::handleEvent(&e);

                if(_conf->handleEventCB) {
                    _conf->handleEventCB(&e);
                }
            }

            if(_conf->updateCB) {
                _conf->updateCB(delta);
            }

           input::update();
            
            //sound::update();

            if(_conf->renderCB) {
                _conf->renderCB();
            }

            SDL_GL_SwapWindow(_window);
        }
    }

    void release() {
        if(_conf->releaseCB) {
            _conf->releaseCB();
        }

        render::release();
        sound::release();
        input::release();
        logger::release();
        
        SDL_GL_DeleteContext(_context);
        SDL_DestroyWindow(_window);
        SDL_Quit();

        config::release();
    }
    
    uint32_t getWidth() {
        return _conf->width;
    }

    uint32_t getHeight() {
        return _conf->height;
    }

    void exit() {
        _running = false;
    }

    
}