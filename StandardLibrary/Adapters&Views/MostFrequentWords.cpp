#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    size_t k;
    std::cin >> k;
    std::cin.ignore();

    std::unordered_map<std::string, size_t> frequencies;
    std::string proposal;

    while (std::getline(std::cin, proposal)) {
        std::istringstream iss(proposal);
        std::string word;
        while (iss >> word) {
            ++frequencies[word];
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

    size_t output_count = std::min(k, pairs.size());
    for (size_t i = 0; i < output_count; ++i) {
        std::cout << pairs[i].first << "    " << pairs[i].second << std::endl;
    }

    return 0;
}