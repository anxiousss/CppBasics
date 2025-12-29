#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    if (tokens.empty()) {
        return "";
    }

    if (tokens.size() == 1) {
        return tokens[0];
    }

    std::string s;

    for (const auto& token: tokens) {
        s += token + delimiter;
    }

    s.erase(s.end() - 1);
    return s;
}
