#include <bakery.h>


string getCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    ostringstream oss;
    oss << setfill('0') << setw(2) << now->tm_mday << '.'
        << setfill('0') << setw(2) << (now->tm_mon + 1) << '.'
        << (now->tm_year + 1900);

    return oss.str();
}



