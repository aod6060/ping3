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

    void loadStream(std::string path, std::function<void(std::ifstream& in)> cb) {
        std::ifstream in(path);
        if(in.is_open()) {
            cb(in);
            in.close();
        }
    }

    void writeStream(std::string path, std::function<void(std::ofstream& out)> cb) {
        std::ofstream out(path);
        if(out.is_open()) {
            cb(out);
            out.close();
        }
    }

    static std::mt19937 _rand;
    void generateRandomSeed() {
        _rand = std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());
    }

    uint32_t getRandom() {
        return _rand();
    }

    uint32_t getRandom(int max) {
        return getRandom() % max;
    }

    uint32_t getRandom(int min, int max) {
        return (getRandom() % (max - min)) + min;
    }

}