#include <gcore/sys.hpp>


namespace config {


    static Config g_config;

    void init() {
    }

    void release() {
    }

    Config* getConfig() {
        return &g_config;
    }
}