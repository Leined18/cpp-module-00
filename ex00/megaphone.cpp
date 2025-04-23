#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        for (char* p = argv[i]; *p; p++) {
            std::cout << static_cast<char>(toupper(*p));
        }
    }
    std::cout << std::endl;
    return 0;
}
