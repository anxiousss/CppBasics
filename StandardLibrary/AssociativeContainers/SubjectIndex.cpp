#include <iostream>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::map<int, std::set<std::string>> dict;
    std::string word; int page;
    while (std::cin >> word >> page) {
        dict[page].insert(word);
    }

    for (const auto& el: dict) {
        std::cout << el.first << ' ';
        for (const std::string& w: el.second) {
            std::cout << w << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}