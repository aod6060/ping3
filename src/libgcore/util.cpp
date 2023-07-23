#include <gcore/sys.hpp>


namespace util {
    void loadFile(std::string path, std::function<void(std::string)> cb) {
        std::ifstream in(path);
        if(in.is_open()) {
            std::string line;
            while(std::getline(in, line)) {
                cb(line);
            }
            in.close();
        }
    }
}