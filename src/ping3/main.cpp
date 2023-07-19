#include <ping3/game.hpp>


int main(int argc, char** argv) {
    app::Config config;

    game::setup(&config);

    app::init(&config);
    app::update();
    app::release();
    

    return 0;
}