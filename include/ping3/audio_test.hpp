#ifndef AUDIO_TEST_HPP
#define AUDIO_TEST_HPP


#include <gcore/sys.hpp>

namespace audio_test {
	void init();
	void handleEvent(SDL_Event* e);
	void update(float delta);
	void render();
	void release();

	void setup(app::Config* config);
	
}

#endif
