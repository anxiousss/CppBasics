#include <vector>
#include <iostream>
#include <climits>

std::string CommonPrefix(const std::vector<std::string>& words) {
    if (words.empty())
        return "";

    if (words.size() == 1)
        return words.front();

    std::string prefix;

    size_t words_size = words.size();
    size_t min_size = SSIZE_MAX;
    size_t min_index = 0;

    for (size_t i = 0; i < words_size; ++i) {
        size_t size = words[i].size();
        if (min_size >= size) {
            min_size = size;
            min_index = i;
        }
    }

    for (size_t i = 0; i < min_size; ++i) {
       prefix += words[min_index][i];
       for (const auto& word: words) {
           if (prefix != word.substr(0, i + 1)) {
               return prefix.substr(0, prefix.size() - 1);
           }
       }
    }

    return prefix;
}

int main() {

    std::cout << CommonPrefix({"apple", "apricot", "application"}) << std::endl;

    return 0;
}