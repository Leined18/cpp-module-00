#include "Account.hpp"

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        for (char* p = argv[i]; *p; p++) {
            cout << static_cast<char>(toupper(*p));
        }
    }
    cout << endl;
    return 0;
}