#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::string word;
    while (std::getline(std::cin, word)) {
        words.push_back(word);
    }
    std::sort(words.begin(), words.end(), std::greater<std::string>());
    for (const std::string& w: words) {
        std::cout << w << std::endl;
    }
    return 0;
}