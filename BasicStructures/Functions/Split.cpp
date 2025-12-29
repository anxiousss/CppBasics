#include <iostream>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter){
    if (str.empty())
        return {""};

    std::vector<std::string> split_str;

    std::string word;

    for (const auto& c: str) {
        if (c == delimiter) {
            split_str.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    if (str.back() == delimiter)
        split_str.emplace_back("");
    else
        split_str.push_back(word);
    return split_str;
}

int main() {
    auto res = Split("What_is_your_name?", '_');
    for (const auto& s: res) {
        std::cout << s << std::endl;
    }
    return 0;
}