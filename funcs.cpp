#include <funcs.h>

std::string getCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << now->tm_mday << '.'
        << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '.'
        << (now->tm_year + 1900);

    return oss.str();
}
