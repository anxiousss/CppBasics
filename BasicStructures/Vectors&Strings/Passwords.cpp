#include <iostream>
#include <cctype>
#include <cstring>

bool check_pass(std::string& password) {
    if  ( 8 > password.size() || password.size() > 14) {
        return false;
    }
    bool is_upper = false;
    bool is_lower = false;
    bool is_digit = false;
    bool is_special = false;

    for (const char c: password) {
        if (c < 33 || c > 126) {
            return false;
        }
        if (islower(c)) {
            is_lower = true;
        }
        else if (isupper(c)) {
            is_upper = true;
        }

        else if (isdigit(c)) {
            is_digit = true;
        }
        else {
            is_special = true;
        }
    }

    if (is_special + is_digit + is_lower + is_upper < 3) {
        return false;
    }
    return true;
}

int main(){
    std::string s;
    std::cin >> s;

    if (check_pass(s)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}