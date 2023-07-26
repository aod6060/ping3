#include <gcore/sys.hpp>


namespace config {

    const static std::string CONF_TYPE = "config";
    const static int CONF_VERSION = 1;

    static Config g_config;

    static std::map<std::string, int> keys;
    static std::map<std::string, int> mouseButtons;

    static void reset();

    static int convertStringToInput(std::string input, bool isMouse);

    void init() {
        // Keyboard
        keys["KEYS_UNKNOWN"] = input::Keyboard::KEYS_UNKNOWN;
        keys["KEYS_A"] = input::Keyboard::KEYS_A;
        keys["KEYS_B"] = input::Keyboard::KEYS_B;
        keys["KEYS_C"] = input::Keyboard::KEYS_C;
        keys["KEYS_D"] = input::Keyboard::KEYS_D;
        keys["KEYS_E"] = input::Keyboard::KEYS_E;
        keys["KEYS_F"] = input::Keyboard::KEYS_F;
        keys["KEYS_G"] = input::Keyboard::KEYS_G;
        keys["KEYS_H"] = input::Keyboard::KEYS_H;
        keys["KEYS_I"] = input::Keyboard::KEYS_I;
        keys["KEYS_J"] = input::Keyboard::KEYS_J;
        keys["KEYS_K"] = input::Keyboard::KEYS_K;
        keys["KEYS_L"] = input::Keyboard::KEYS_L;
        keys["KEYS_M"] = input::Keyboard::KEYS_M;
        keys["KEYS_N"] = input::Keyboard::KEYS_N;
        keys["KEYS_O"] = input::Keyboard::KEYS_O;
        keys["KEYS_P"] = input::Keyboard::KEYS_P;
        keys["KEYS_Q"] = input::Keyboard::KEYS_Q;
        keys["KEYS_R"] = input::Keyboard::KEYS_R;
        keys["KEYS_S"] = input::Keyboard::KEYS_S;
        keys["KEYS_T"] = input::Keyboard::KEYS_T;
        keys["KEYS_U"] = input::Keyboard::KEYS_U;
        keys["KEYS_V"] = input::Keyboard::KEYS_V;
        keys["KEYS_W"] = input::Keyboard::KEYS_W;
        keys["KEYS_X"] = input::Keyboard::KEYS_X;
        keys["KEYS_Y"] = input::Keyboard::KEYS_Y;
        keys["KEYS_Z"] = input::Keyboard::KEYS_Z;
        keys["KEYS_1"] = input::Keyboard::KEYS_1;
        keys["KEYS_2"] = input::Keyboard::KEYS_2;
        keys["KEYS_3"] = input::Keyboard::KEYS_3;
        keys["KEYS_4"] = input::Keyboard::KEYS_4;
        keys["KEYS_5"] = input::Keyboard::KEYS_5;
        keys["KEYS_6"] = input::Keyboard::KEYS_6;
        keys["KEYS_7"] = input::Keyboard::KEYS_7;
        keys["KEYS_8"] = input::Keyboard::KEYS_8;
        keys["KEYS_9"] = input::Keyboard::KEYS_9;
        keys["KEYS_0"] = input::Keyboard::KEYS_0;
        keys["KEYS_RETURN"] = input::Keyboard::KEYS_RETURN;
        keys["KEYS_ESCAPE"] = input::Keyboard::KEYS_ESCAPE;
        keys["KEYS_BACKSPACE"] = input::Keyboard::KEYS_BACKSPACE;
        keys["KEYS_TAB"] = input::Keyboard::KEYS_TAB;
        keys["KEYS_SPACE"] = input::Keyboard::KEYS_SPACE;
        keys["KEYS_MINUS"] = input::Keyboard::KEYS_MINUS;
        keys["KEYS_EQUALS"] = input::Keyboard::KEYS_EQUALS;
        keys["KEYS_LEFTBRACKET"] = input::Keyboard::KEYS_LEFTBRACKET;
        keys["KEYS_RIGHTBRACKET"] = input::Keyboard::KEYS_RIGHTBRACKET;
        keys["KEYS_BACKSLASH"] = input::Keyboard::KEYS_BACKSLASH;
        keys["KEYS_NONUSHASH"] = input::Keyboard::KEYS_NONUSHASH;
        keys["KEYS_SEMICOLON"] = input::Keyboard::KEYS_SEMICOLON;
        keys["KEYS_APOSTROPHE"] = input::Keyboard::KEYS_APOSTROPHE;
        keys["KEYS_GRAVE"] = input::Keyboard::KEYS_GRAVE;
        keys["KEYS_COMMA"] = input::Keyboard::KEYS_COMMA;
        keys["KEYS_PERIOD"] = input::Keyboard::KEYS_PERIOD;
        keys["KEYS_SLASH"] = input::Keyboard::KEYS_SLASH;
        keys["KEYS_CAPSLOCK"] = input::Keyboard::KEYS_CAPSLOCK;
        keys["KEYS_F1"] = input::Keyboard::KEYS_F1;
        keys["KEYS_F2"] = input::Keyboard::KEYS_F2;
        keys["KEYS_F3"] = input::Keyboard::KEYS_F3;
        keys["KEYS_F4"] = input::Keyboard::KEYS_F4;
        keys["KEYS_F5"] = input::Keyboard::KEYS_F5;
        keys["KEYS_F6"] = input::Keyboard::KEYS_F6;
        keys["KEYS_F7"] = input::Keyboard::KEYS_F7;
        keys["KEYS_F8"] = input::Keyboard::KEYS_F8;
        keys["KEYS_F9"] = input::Keyboard::KEYS_F9;
        keys["KEYS_F10"] = input::Keyboard::KEYS_F10;
        keys["KEYS_F11"] = input::Keyboard::KEYS_F11;
        keys["KEYS_F12"] = input::Keyboard::KEYS_F12;
        keys["KEYS_PRINTSCREEN"] = input::Keyboard::KEYS_PRINTSCREEN;
        keys["KEYS_SCROLLLOCK"] = input::Keyboard::KEYS_SCROLLLOCK;
        keys["KEYS_PAUSE"] = input::Keyboard::KEYS_PAUSE;
        keys["KEYS_INSERT"] = input::Keyboard::KEYS_INSERT;
        keys["KEYS_HOME"] = input::Keyboard::KEYS_HOME;
        keys["KEYS_PAGEUP"] = input::Keyboard::KEYS_PAGEUP;
        keys["KEYS_DELETE"] = input::Keyboard::KEYS_DELETE;
        keys["KEYS_END"] = input::Keyboard::KEYS_END;
        keys["KEYS_PAGEDOWN"] = input::Keyboard::KEYS_PAGEDOWN;
        keys["KEYS_RIGHT"] = input::Keyboard::KEYS_RIGHT;
        keys["KEYS_LEFT"] = input::Keyboard::KEYS_LEFT;
        keys["KEYS_DOWN"] = input::Keyboard::KEYS_DOWN;
        keys["KEYS_UP"] = input::Keyboard::KEYS_UP;
        keys["KEYS_NUMLOCKCLEAR"] = input::Keyboard::KEYS_NUMLOCKCLEAR;
        keys["KEYS_KP_DIVIDE"] = input::Keyboard::KEYS_KP_DIVIDE;
        keys["KEYS_KP_MULTIPLY"] = input::Keyboard::KEYS_KP_MULTIPLY;
        keys["KEYS_KP_MINUS"] = input::Keyboard::KEYS_KP_MINUS;
        keys["KEYS_KP_PLUS"] = input::Keyboard::KEYS_KP_PLUS;
        keys["KEYS_KP_ENTER"] = input::Keyboard::KEYS_KP_ENTER;
        keys["KEYS_KP_1"] = input::Keyboard::KEYS_KP_1;
        keys["KEYS_KP_2"] = input::Keyboard::KEYS_KP_2;
        keys["KEYS_KP_3"] = input::Keyboard::KEYS_KP_3;
        keys["KEYS_KP_4"] = input::Keyboard::KEYS_KP_4;
        keys["KEYS_KP_5"] = input::Keyboard::KEYS_KP_5;
        keys["KEYS_KP_6"] = input::Keyboard::KEYS_KP_6;
        keys["KEYS_KP_7"] = input::Keyboard::KEYS_KP_7;
        keys["KEYS_KP_8"] = input::Keyboard::KEYS_KP_8;
        keys["KEYS_KP_9"] = input::Keyboard::KEYS_KP_9;
        keys["KEYS_KP_0"] = input::Keyboard::KEYS_KP_0;
        keys["KEYS_KP_PERIOD"] = input::Keyboard::KEYS_KP_PERIOD;
        keys["KEYS_NONUSBACKSLASH"] = input::Keyboard::KEYS_NONUSBACKSLASH;
        keys["KEYS_APPLICATION"] = input::Keyboard::KEYS_APPLICATION;
        keys["KEYS_POWER"] = input::Keyboard::KEYS_POWER;
        keys["KEYS_KP_EQUALS"] = input::Keyboard::KEYS_KP_EQUALS;
        keys["KEYS_F13"] = input::Keyboard::KEYS_F13;
        keys["KEYS_F14"] = input::Keyboard::KEYS_F14;
        keys["KEYS_F15"] = input::Keyboard::KEYS_F15;
        keys["KEYS_F16"] = input::Keyboard::KEYS_F16;
        keys["KEYS_F17"] = input::Keyboard::KEYS_F17;
        keys["KEYS_F18"] = input::Keyboard::KEYS_F18;
        keys["KEYS_F19"] = input::Keyboard::KEYS_F19;
        keys["KEYS_F20"] = input::Keyboard::KEYS_F20;
        keys["KEYS_F21"] = input::Keyboard::KEYS_F21;
        keys["KEYS_F22"] = input::Keyboard::KEYS_F22;
        keys["KEYS_F23"] = input::Keyboard::KEYS_F23;
        keys["KEYS_F24"] = input::Keyboard::KEYS_F24;
        keys["KEYS_EXECUTE"] = input::Keyboard::KEYS_EXECUTE;
        keys["KEYS_HELP"] = input::Keyboard::KEYS_HELP;
        keys["KEYS_MENU"] = input::Keyboard::KEYS_MENU;
        keys["KEYS_SELECT"] = input::Keyboard::KEYS_SELECT;
        keys["KEYS_STOP"] = input::Keyboard::KEYS_STOP;
        keys["KEYS_AGAIN"] = input::Keyboard::KEYS_AGAIN;
        keys["KEYS_UNDO"] = input::Keyboard::KEYS_UNDO;
        keys["KEYS_CUT"] = input::Keyboard::KEYS_CUT;
        keys["KEYS_COPY"] = input::Keyboard::KEYS_COPY;
        keys["KEYS_PASTE"] = input::Keyboard::KEYS_PASTE;
        keys["KEYS_FIND"] = input::Keyboard::KEYS_FIND;
        keys["KEYS_MUTE"] = input::Keyboard::KEYS_MUTE;
        keys["KEYS_VOLUMEUP"] = input::Keyboard::KEYS_VOLUMEUP;
        keys["KEYS_VOLUMEDOWN"] = input::Keyboard::KEYS_VOLUMEDOWN;
        keys["KEYS_KP_COMM"] = input::Keyboard::KEYS_KP_COMMA;
        keys["KEYS_KP_EQUALSAS400"] = input::Keyboard::KEYS_KP_EQUALSAS400;
        keys["KEYS_INTERNATIONAL1"] = input::Keyboard::KEYS_INTERNATIONAL1;
        keys["KEYS_INTERNATIONAL2"] = input::Keyboard::KEYS_INTERNATIONAL2;
        keys["KEYS_INTERNATIONAL3"] = input::Keyboard::KEYS_INTERNATIONAL3;
        keys["KEYS_INTERNATIONAL4"] = input::Keyboard::KEYS_INTERNATIONAL4;
        keys["KEYS_INTERNATIONAL5"] = input::Keyboard::KEYS_INTERNATIONAL5;
        keys["KEYS_INTERNATIONAL6"] = input::Keyboard::KEYS_INTERNATIONAL6;
        keys["KEYS_INTERNATIONAL7"] = input::Keyboard::KEYS_INTERNATIONAL7;
        keys["KEYS_INTERNATIONAL8"] = input::Keyboard::KEYS_INTERNATIONAL8;
        keys["KEYS_INTERNATIONAL9"] = input::Keyboard::KEYS_INTERNATIONAL9;
        keys["KEYS_LANG1"] = input::Keyboard::KEYS_LANG1;
        keys["KEYS_LANG2"] = input::Keyboard::KEYS_LANG2;
        keys["KEYS_LANG3 "] = input::Keyboard::KEYS_LANG3 ;
        keys["KEYS_LANG4 "] = input::Keyboard::KEYS_LANG4 ;
        keys["KEYS_LANG5"] = input::Keyboard::KEYS_LANG5;
        keys["KEYS_LANG6"] = input::Keyboard::KEYS_LANG6;
        keys["KEYS_LANG7 "] = input::Keyboard::KEYS_LANG7 ;
        keys["KEYS_LANG8"] = input::Keyboard::KEYS_LANG8;
        keys["KEYS_LANG9"] = input::Keyboard::KEYS_LANG9;
        keys["KEYS_ALTERASE"] = input::Keyboard::KEYS_ALTERASE;
        keys["KEYS_SYSREQ"] = input::Keyboard::KEYS_SYSREQ;
        keys["KEYS_CANCEL"] = input::Keyboard::KEYS_CANCEL;
        keys["KEYS_CLEAR"] = input::Keyboard::KEYS_CLEAR;
        keys["KEYS_PRIOR"] = input::Keyboard::KEYS_PRIOR;
        keys["KEYS_RETURN2"] = input::Keyboard::KEYS_RETURN2;
        keys["KEYS_SEPARATOR"] = input::Keyboard::KEYS_SEPARATOR;
        keys["KEYS_OUT"] = input::Keyboard::KEYS_OUT;
        keys["KEYS_OPER"] = input::Keyboard::KEYS_OPER;
        keys["KEYS_CLEARAGAIN"] = input::Keyboard::KEYS_CLEARAGAIN;
        keys["KEYS_CRSEL"] = input::Keyboard::KEYS_CRSEL;
        keys["KEYS_EXSEL"] = input::Keyboard::KEYS_EXSEL;
        keys["KEYS_KP_00"] = input::Keyboard::KEYS_KP_00;
        keys["KEYS_KP_000"] = input::Keyboard::KEYS_KP_000;
        keys["KEYS_THOUSANDSSEPARATOR"] = input::Keyboard::KEYS_THOUSANDSSEPARATOR;
        keys["KEYS_DECIMALSEPARATOR"] = input::Keyboard::KEYS_DECIMALSEPARATOR;
        keys["KEYS_CURRENCYUNIT"] = input::Keyboard::KEYS_CURRENCYUNIT;
        keys["KEYS_CURRENCYSUBUNIT"] = input::Keyboard::KEYS_CURRENCYSUBUNIT;
        keys["KEYS_KP_LEFTPAREN"] = input::Keyboard::KEYS_KP_LEFTPAREN;
        keys["KEYS_KP_RIGHTPAREN"] = input::Keyboard::KEYS_KP_RIGHTPAREN;
        keys["KEYS_KP_LEFTBRACE"] = input::Keyboard::KEYS_KP_LEFTBRACE;
        keys["KEYS_KP_RIGHTBRACE"] = input::Keyboard::KEYS_KP_RIGHTBRACE;
        keys["KEYS_KP_TAB"] = input::Keyboard::KEYS_KP_TAB;
        keys["KEYS_KP_BACKSPACE"] = input::Keyboard::KEYS_KP_BACKSPACE;
        keys["KEYS_KP_A"] = input::Keyboard::KEYS_KP_A;
        keys["KEYS_KP_B"] = input::Keyboard::KEYS_KP_B;
        keys["KEYS_KP_C"] = input::Keyboard::KEYS_KP_C;
        keys["KEYS_KP_D"] = input::Keyboard::KEYS_KP_D;
        keys["KEYS_KP_E"] = input::Keyboard::KEYS_KP_E;
        keys["KEYS_KP_F"] = input::Keyboard::KEYS_KP_F;
        keys["KEYS_KP_XOR"] = input::Keyboard::KEYS_KP_XOR;
        keys["KEYS_KP_POWER"] = input::Keyboard::KEYS_KP_POWER;
        keys["KEYS_KP_PERCENT"] = input::Keyboard::KEYS_KP_PERCENT;
        keys["KEYS_KP_LESS"] = input::Keyboard::KEYS_KP_LESS;
        keys["KEYS_KP_GREATER"] = input::Keyboard::KEYS_KP_GREATER;
        keys["KEYS_KP_AMPERSAND"] = input::Keyboard::KEYS_KP_AMPERSAND;
        keys["KEYS_KP_DBLAMPERSAND"] = input::Keyboard::KEYS_KP_DBLAMPERSAND;
        keys["KEYS_KP_VERTICALBAR"] = input::Keyboard::KEYS_KP_VERTICALBAR;
        keys["KEYS_KP_DBLVERTICALBAR"] = input::Keyboard::KEYS_KP_DBLVERTICALBAR;
        keys["KEYS_KP_COLON"] = input::Keyboard::KEYS_KP_COLON;
        keys["KEYS_KP_HASH"] = input::Keyboard::KEYS_KP_HASH;
        keys["KEYS_KP_SPACE"] = input::Keyboard::KEYS_KP_SPACE;
        keys["KEYS_KP_AT"] = input::Keyboard::KEYS_KP_AT;
        keys["KEYS_KP_EXCLAM"] = input::Keyboard::KEYS_KP_EXCLAM;
        keys["KEYS_KP_MEMSTORE"] = input::Keyboard::KEYS_KP_MEMSTORE;
        keys["KEYS_KP_MEMRECALL"] = input::Keyboard::KEYS_KP_MEMRECALL;
        keys["KEYS_KP_MEMCLEAR"] = input::Keyboard::KEYS_KP_MEMCLEAR;
        keys["KEYS_KP_MEMADD"] = input::Keyboard::KEYS_KP_MEMADD;
        keys["KEYS_KP_MEMSUBTRACT"] = input::Keyboard::KEYS_KP_MEMSUBTRACT;
        keys["KEYS_KP_MEMMULTIPLY"] = input::Keyboard::KEYS_KP_MEMMULTIPLY;
        keys["KEYS_KP_MEMDIVIDE"] = input::Keyboard::KEYS_KP_MEMDIVIDE;
        keys["KEYS_KP_PLUSMINUS"] = input::Keyboard::KEYS_KP_PLUSMINUS;
        keys["KEYS_KP_CLEAR"] = input::Keyboard::KEYS_KP_CLEAR;
        keys["KEYS_KP_CLEARENTRY"] = input::Keyboard::KEYS_KP_CLEARENTRY;
        keys["KEYS_KP_BINARY"] = input::Keyboard::KEYS_KP_BINARY;
        keys["KEYS_KP_OCTAL"] = input::Keyboard::KEYS_KP_OCTAL;
        keys["KEYS_KP_DECIMAL"] = input::Keyboard::KEYS_KP_DECIMAL;
        keys["KEYS_KP_HEXADECIMAL"] = input::Keyboard::KEYS_KP_HEXADECIMAL;
        keys["KEYS_LCTRL"] = input::Keyboard::KEYS_LCTRL;
        keys["KEYS_LSHIFT"] = input::Keyboard::KEYS_LSHIFT;
        keys["KEYS_LALT"] = input::Keyboard::KEYS_LALT;
        keys["KEYS_LGUI"] = input::Keyboard::KEYS_LGUI;
        keys["KEYS_RCTRL"] = input::Keyboard::KEYS_RCTRL;
        keys["KEYS_RSHIFT"] = input::Keyboard::KEYS_RSHIFT;
        keys["KEYS_RALT"] = input::Keyboard::KEYS_RALT;
        keys["KEYS_RGUI"] = input::Keyboard::KEYS_RGUI;
        keys["KEYS_MODE"] = input::Keyboard::KEYS_MODE;
        keys["KEYS_AUDIONEXT"] = input::Keyboard::KEYS_AUDIONEXT;
        keys["KEYS_AUDIOPREV"] = input::Keyboard::KEYS_AUDIOPREV;
        keys["KEYS_AUDIOSTOP"] = input::Keyboard::KEYS_AUDIOSTOP;
        keys["KEYS_AUDIOPLAY"] = input::Keyboard::KEYS_AUDIOPLAY;
        keys["KEYS_AUDIOMUTE"] = input::Keyboard::KEYS_AUDIOMUTE;
        keys["KEYS_MEDIASELECT"] = input::Keyboard::KEYS_MEDIASELECT;
        keys["KEYS_WWW"] = input::Keyboard::KEYS_WWW;
        keys["KEYS_MAIL"] = input::Keyboard::KEYS_MAIL;
        keys["KEYS_CALCULATOR"] = input::Keyboard::KEYS_CALCULATOR;
        keys["KEYS_COMPUTER"] = input::Keyboard::KEYS_COMPUTER;
        keys["KEYS_AC_SEARCH"] = input::Keyboard::KEYS_AC_SEARCH;
        keys["KEYS_AC_HOME"] = input::Keyboard::KEYS_AC_HOME;
        keys["KEYS_AC_BACK"] = input::Keyboard::KEYS_AC_BACK;
        keys["KEYS_AC_FORWARD"] = input::Keyboard::KEYS_AC_FORWARD;
        keys["KEYS_AC_STOP"] = input::Keyboard::KEYS_AC_STOP;
        keys["KEYS_AC_REFRESH"] = input::Keyboard::KEYS_AC_REFRESH;
        keys["KEYS_AC_BOOKMARKS"] = input::Keyboard::KEYS_AC_BOOKMARKS;
        keys["KEYS_BRIGHTNESSDOWN"] = input::Keyboard::KEYS_BRIGHTNESSDOWN;
        keys["KEYS_BRIGHTNESSUP"] = input::Keyboard::KEYS_BRIGHTNESSUP;
        keys["KEYS_DISPLAYSWITCH"] = input::Keyboard::KEYS_DISPLAYSWITCH;
        keys["KEYS_KBDILLUMTOGGLE"] = input::Keyboard::KEYS_KBDILLUMTOGGLE;
        keys["KEYS_KBDILLUMDOWN"] = input::Keyboard::KEYS_KBDILLUMDOWN;
        keys["KEYS_KBDILLUMUP"] = input::Keyboard::KEYS_KBDILLUMUP;
        keys["KEYS_EJECT"] = input::Keyboard::KEYS_EJECT;
        keys["KEYS_SLEEP"] = input::Keyboard::KEYS_SLEEP;
        keys["KEYS_APP1"] = input::Keyboard::KEYS_APP1;
        keys["KEYS_APP2"] = input::Keyboard::KEYS_APP2;
        keys["KEYS_AUDIOREWIND"] = input::Keyboard::KEYS_AUDIOREWIND;
        keys["KEYS_AUDIOFASTFORWARD"] = input::Keyboard::KEYS_AUDIOFASTFORWARD;
        keys["KEYS_SOFTLEFT"] = input::Keyboard::KEYS_SOFTLEFT;
        keys["KEYS_SOFTRIGHT"] = input::Keyboard::KEYS_SOFTRIGHT;
        keys["KEYS_CALL"] = input::Keyboard::KEYS_CALL;
        keys["KEYS_ENDCALL"] = input::Keyboard::KEYS_ENDCALL;

        // MouseButtons
        /*
        MBS_LEFT = 0,
        MBS_CENTER,
        MBS_RIGHT,
        */
        mouseButtons["MBS_LEFT"] = input::MouseButtons::MBS_LEFT;
        mouseButtons["MBS_CENTER"] = input::MouseButtons::MBS_CENTER;
        mouseButtons["MBS_RIGHT"] = input::MouseButtons::MBS_RIGHT;

        util::loadStream("./data/config.json", [&](std::ifstream& in) {
            Json::Value root;
            in >> root;

            std::string type = root["type"].asString();
            int version = root["version"].asInt();

            if(CONF_TYPE != type) {
                logger::output(logger::LoggerType::LT_WARNING, [&](std::stringstream& ss) {
                    ss << "config.json doesn't have type: config will try to load.";
                });
            }

            if(CONF_VERSION != version) {
                logger::output(logger::LoggerType::LT_WARNING, [&](std::stringstream& ss) {
                    ss << "config.json is the wrong version. Will try to load!";
                });
            }


            // App
            Json::Value _app = root["app"];
            g_config.app.caption = _app["caption"].asString();
            g_config.app.width = _app["width"].asInt();
            g_config.app.height = _app["height"].asInt();
            g_config.app.fullscreen = _app["fullscreen"].asBool();

            // Input
            Json::Value _input = root["input"];
            for(int i = 0; i < _input["input-maps"].size(); i++) {
                Json::Value inputMap = _input["input-maps"][i];
                g_config.input.inputMaps[inputMap["name"].asString()].isMouse = inputMap["is-mouse"].asBool();
                g_config.input.inputMaps[inputMap["name"].asString()].input = convertStringToInput(
                    inputMap["input"].asString(),
                    g_config.input.inputMaps[inputMap["name"].asString()].isMouse
                );
            }

            // Render
            Json::Value _render = root["render"];
            // Will Add Stuff here soon

            // Sound
            Json::Value _sound = root["sound"];
            g_config.sound.musicVolume = _sound["music-volume"].asFloat();
            g_config.sound.soundFXVolume = _sound["sound-fx-volume"].asFloat();

        });
    }

    void release() {
        reset();
    }

    Config* getConfig() {
        return &g_config;
    }

    static void reset() {
        g_config.app.caption = "";
        g_config.app.fullscreen = false;
        g_config.app.width = 1;
        g_config.app.height = 1;

        g_config.input.inputMaps.clear();

        g_config.sound.musicVolume = 0.0f;
        g_config.sound.soundFXVolume = 0.0f;
    }

    static int convertStringToInput(std::string input, bool isMouse) {
        if(isMouse) {
            return mouseButtons[input];
        } else {
            return keys[input];
        }
    }

}