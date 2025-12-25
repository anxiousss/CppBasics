#include <iostream>
#include <string>
#include <algorithm>

bool Is_palindrome(std::string str) {

    int p = 0;
    for (char c: str) {
        if (c != ' ') {
            str[p] = c;
            ++p;
        }
    }

    str = str.substr(0, p);
    int len = str.size();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) {return false;}
    }
    return true;
}


int main() {
    std::string str;
    std::getline(std::cin, str);

    if (Is_palindrome(str)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}