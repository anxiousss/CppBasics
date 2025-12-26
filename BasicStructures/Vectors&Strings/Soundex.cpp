#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string word;
    std::vector<std::string> replaces = {"aehiouwy", "bfpv", "cgjkqsxz", "dt", "l", "mn", "r"};
    std::cin >> word;

    size_t word_size = word.size();
    std::string code;
    code.push_back(word[0]);}

    for (size_t i = 1; i < word_size; ++i) {
        char c = std::tolower(word[i]);
        bool found = false;

        for (size_t j = 1; j < 7; ++j) {
            const auto& s = replaces[j];
            if (s.find(c) != std::string::npos) {
                code.push_back(static_cast<char>(j + '0'));
                found = true;
                break;
            }
        }
        if (!found)
            code.push_back('0');
    }

    code.erase(std::remove(code.begin(), code.end(), '0'), code.end());

    if (code.size() != 1) {
        auto it = code.begin() + 1;
        while (it + 1 != code.end()) {
            if (*it == *(it + 1)) {
                code.erase(it + 1);
            } else {
                ++it;
            }
        }
    }

    if (code.size() > 4)
        code = code.substr(0, 4);
    else if (code.size() < 4)
        code.append(4 - code.size(), '0');

    std::cout << code << std::endl;


    return 0;
}