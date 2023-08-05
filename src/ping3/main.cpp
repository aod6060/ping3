#include <ping3/game.hpp>
#include <ping3/audio_test.hpp>

int main(int argc, char** argv) {
    util::generateRandomSeed();
    
    app::Config config;

    if(argc == 2) {
	    std::string arg = argv[1];
	    if(arg == "audio_test") {
		    audio_test::setup(&config);
	    } else {
		    game::setup(&config);
	    }
    } else {
    	game::setup(&config);
    }

    app::init(&config);
    app::update();
    app::release();
    

    return 0;
}
