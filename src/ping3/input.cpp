#include <ping3/sys.hpp>


namespace input {

    static std::vector<InputState> keys;
    static std::vector<InputState> mouseButtons;
    static glm::vec2 mousePosition;
    static glm::vec2 mouseVelocity;
    
    void init() {
        keys.resize(Keyboard::KEYBOARD_MAX_SIZE);

        std::for_each(keys.begin(), keys.end(), [&](InputState& k) {
            k = InputState::IS_RELEASED;
        });

    }

    void handleEvent(SDL_Event* e) {
        if(e->type == SDL_KEYDOWN) {
            if(keys[e->key.keysym.scancode] == InputState::IS_RELEASED) {
                keys[e->key.keysym.scancode] = InputState::IS_PRESSED_ONCE;
            }
        } else if(e->type == SDL_KEYUP) {
            if(keys[e->key.keysym.scancode] == InputState::IS_PRESSED) {
                keys[e->key.keysym.scancode] = InputState::IS_RELEASED_ONCE;
            }
        }
    }

    void update() {
        std::for_each(keys.begin(), keys.end(), [&](InputState& is) {
            if(is == InputState::IS_PRESSED_ONCE) {
                is = InputState::IS_PRESSED;
            }
            if(is == InputState::IS_RELEASED_ONCE) {
                is = InputState::IS_RELEASED;
            }
        });
    }

    void release() {
        keys.clear();
    }
    
    // Keyboards
    bool isKeyRelease(const Keyboard& k) {
        return keys[k] == InputState::IS_RELEASED;
    }

    bool isKeyPressOnce(const Keyboard& k) {
        return keys[k] == InputState::IS_PRESSED_ONCE;
    }

    bool isKeyPress(const Keyboard& k) {
        return keys[k] == InputState::IS_PRESSED;
    }

    bool isKeyReleaseOnce(const Keyboard& k) {
        return keys[k] == InputState::IS_RELEASED_ONCE;
    }

    // Mouse
    bool isMouseButtonRelease(const MouseButtons& mb) {

    }

    bool isMouseButtonPressOnce(const MouseButtons& mb) {

    }

    bool isMouseButtonPress(const MouseButtons& mb) {

    }

    bool isMouseButtonReleaseOnce(const MouseButtons& mb) {

    }
    
    glm::vec2 toMousePosition() {

    }

    glm::vec2 toMouseVelocity() {

    }

    bool isGrab() {

    }

    void setGrab(bool b) {

    }

    void toggleGrab() {

    }

    
}