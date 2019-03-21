#include <iostream>
#include <string>

int main() {
    std::string kek;
    std::cin >> kek;

    int length = kek.length();

    bool is_iden = true;
    for (int i = 1; i < length; i++) {
        if (kek[0] != kek[i]) {
            is_iden = false;
            break;
        }
    }
    if (is_iden) {
        std::cout << -1;
    }
    else {
        bool is_pal = true;
        for (int i = 0; i < length / 2 + 1; i++) {
            if (kek[i] != kek[length - 1 - i]) {
                is_pal = false;
            }
        }
        if (is_pal) {
            std::cout << length - 1;
        }
        else {
            std::cout << length;
        }
    }
    return 0;
}