#include <gcore/sys.hpp>


namespace input {

    static std::vector<InputState> keys;
    static std::vector<InputState> mouseButtons;
    static glm::vec2 mousePosition;
    static glm::vec2 mouseVelocity;

    void init() {
        keys.resize(Keyboard::KEYBOARD_MAX_SIZE);
        mouseButtons.resize(MouseButtons::MBS_MAX_SIZE);

        std::for_each(keys.begin(), keys.end(), [&](InputState& k) {
            k = InputState::IS_RELEASED;
        });

        std::for_each(mouseButtons.begin(), mouseButtons.end(), [&](InputState& is) {
            is = InputState::IS_RELEASED;
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
        } else if(e->type == SDL_MOUSEBUTTONDOWN) {
            if(mouseButtons[e->button.button - 1] == InputState::IS_RELEASED) {
                mouseButtons[e->button.button - 1] = InputState::IS_PRESSED_ONCE;
            }
        } else if(e->type == SDL_MOUSEBUTTONUP) {
            if(mouseButtons[e->button.button - 1] == InputState::IS_PRESSED) {
                mouseButtons[e->button.button - 1] = InputState::IS_RELEASED_ONCE;
            }
        } else if(e->type == SDL_MOUSEMOTION) {
            mousePosition.x = e->motion.x;
            mousePosition.y = e->motion.y;
            mouseVelocity.x = e->motion.xrel;
            mouseVelocity.y = e->motion.yrel;
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

        std::for_each(mouseButtons.begin(), mouseButtons.end(), [&](InputState& is) {
            if(is == InputState::IS_PRESSED_ONCE) {
                is = InputState::IS_PRESSED;
            }
            if(is == InputState::IS_RELEASED_ONCE) {
                is = InputState::IS_RELEASED;
            }
        });

        mouseVelocity.x = 0.0f;
        mouseVelocity.y = 0.0f;
    }

    void release() {
        keys.clear();
        mouseButtons.clear();
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
        return mouseButtons[mb] == InputState::IS_RELEASED;
    }

    bool isMouseButtonPressOnce(const MouseButtons& mb) {
        return mouseButtons[mb] == InputState::IS_PRESSED_ONCE;
    }

    bool isMouseButtonPress(const MouseButtons& mb) {
        return mouseButtons[mb] == InputState::IS_PRESSED;
    }

    bool isMouseButtonReleaseOnce(const MouseButtons& mb) {
        return mouseButtons[mb] == InputState::IS_RELEASED_ONCE;
    }
    
    glm::vec2 toMousePosition() {
        return mousePosition;
    }

    glm::vec2 toMouseVelocity() {
        return mouseVelocity;
    }

    bool isGrab() {
        return SDL_GetRelativeMouseMode() ? true : false;
    }

    void setGrab(bool b) {
        SDL_SetRelativeMouseMode(b ? SDL_TRUE : SDL_FALSE);
    }

    void toggleGrab() {
        setGrab(!isGrab());
    }

    
}