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
        std::ifstream in(path, std::ios::binary);
        if(in.is_open()) {
            cb(in);
            in.close();
        }
    }

    void writeStream(std::string path, std::function<void(std::ofstream& out)> cb) {
        std::ofstream out(path, std::ios::binary);
        if(out.is_open()) {
            cb(out);
            out.close();
        }
    }

}