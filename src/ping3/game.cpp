#include <ping3/game.hpp>



namespace game {
	


    static float x = 32.0f;
    static float y = 32.0f;

    static float speed = 64.0f;

    void init() {
    }

    void update(float delta) {
	if(input::isKeyPress(input::Keyboard::KEYS_LEFT)) {
		x -= speed * delta;
	} else if(input::isKeyPress(input::Keyboard::KEYS_RIGHT)) {
		x += speed * delta;
	}

	if(input::isKeyPress(input::Keyboard::KEYS_UP)) {
		y -= speed * delta;
	} else if(input::isKeyPress(input::Keyboard::KEYS_DOWN)) {
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
