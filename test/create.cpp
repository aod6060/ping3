#include <iostream>
#include <fstream>
#include <string>
#include <functional>


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

int main(int argc, char** argv) {
    std::ofstream out("output.txt");
    if(out.is_open()) {

        out << "static std::map<std::string, int> keys;" << "\n";
        out << "\n";
        loadFile("./keys_list.txt", [&](std::string line) {
            out << "keys[\""<< line <<"\"] = input::Keyboard::" << line << ";\n";
        });

        out.close();
    }
    return 0;
}