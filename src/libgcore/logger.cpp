#include <gcore/sys.hpp>


namespace logger {

    static std::ofstream out;
    static bool dev_mode = true;

    void init() {
        out.open("logger.txt");
    }

    void release() {
        out.close();
    }

    void output(LoggerType type, std::function<void(std::stringstream&)> cb) {
        if(dev_mode) {
            std::stringstream ss;
            cb(ss);
            std::cout << "[" << loggerTypeString(type) << "] -> " << ss.str() << "\n";
            out << "[" << loggerTypeString(type) << "] -> " << ss.str() << "\n";
        }
    }

    std::string loggerTypeString(const LoggerType& type) {
        std::string str = "none";

        switch(type) {
            case LoggerType::LT_INFO:
                str = "info";
                break;
            case LoggerType::LT_WARNING:
                str = "warning";
                break;
            case LoggerType::LT_ERROR:
                str = "error";
                break;
        }

        return str;
    }
    
}