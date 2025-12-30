#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    size_t m, n;
    if (!(std::cin >> m >> n)) {
        return 1;
    }

    std::unordered_map<std::string, size_t> frequencies;
    std::string word;

    for (size_t i = 0; i < m; ++i) {
        if (!(std::cin >> word)) {
            break;
        }

        size_t word_size = word.size();
        if (word_size >= n) {
            for (size_t j = 0; j <= word_size - n; ++j) {
                std::string n_gram = word.substr(j, n);
                ++frequencies[n_gram];
            }
        }
    }

    std::vector<std::pair<std::string, size_t>> pairs;
    pairs.reserve(frequencies.size());

    for (const auto& [key, value] : frequencies) {
        pairs.emplace_back(key, value);
    }

    std::sort(pairs.begin(), pairs.end(),
              [](const auto& a, const auto& b) {
                  if (a.second != b.second) {
                      return a.second > b.second;
                  }
                  return a.first < b.first;
              });

    for (const auto& [w, count] : pairs) {
        std::cout << w << " - " << count << std::endl;
    }

    return 0;
}