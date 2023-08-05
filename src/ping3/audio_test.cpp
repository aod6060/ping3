#include <ping3/audio_test.hpp>



namespace audio_test {

	SDL_AudioSpec spec;
	SDL_AudioSpec actual;
	SDL_AudioDeviceID dev;

	double _time = 0.0f;

	void init() {
		//SDL_memset(&spec, 0, sizeof(SDL_AudioSpec));
		SDL_zero(spec);

		spec.freq = 44100;
		spec.format = AUDIO_S16SYS;
		spec.channels = 1;
		spec.samples = 256;
		spec.callback = nullptr;

		dev = SDL_OpenAudioDevice(
				nullptr,
				0,
				&spec,
				&actual,
				0);
		if(dev == 0) {
			std::cout << SDL_GetError() << "\n";
		}

		SDL_PauseAudioDevice(dev, 0);

	}

	void handleEvent(SDL_Event* e) {

	}

	void update(float delta) {
		if(input::isKeyPress(input::Keyboard::KEYS_ESCAPE)) {
			app::exit();
		}

		std::cout << SDL_GetQueuedAudioSize(dev) << "\n";
		
		if(SDL_GetQueuedAudioSize(dev) == 0) {

			for(int i = 0; i < actual.samples; i++) {
				int16_t s = sin(440.0 * 2.0 * 3.14 * _time) * 2500;
				SDL_QueueAudio(dev, &s, sizeof(int16_t));
				_time += 1.0 / (double)(actual.samples);

			}

			
		}

	}

	void render() {

	}

	void release() {
		SDL_CloseAudioDevice(dev);
		//SDL_CloseAudio();
	}

	void setup(app::Config* config) {
            config->initCB = init;
            config->handleEventCB = handleEvent;
            config->updateCB = update;
            config->renderCB = render;
            config->releaseCB = release;
	}

}

