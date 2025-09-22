#include <iostream>
#include "Harl.hpp"
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./harl <level>\n (DEBUG, INFO, WARNING, ERROR)" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(argv[1]);
    return 0;
}
