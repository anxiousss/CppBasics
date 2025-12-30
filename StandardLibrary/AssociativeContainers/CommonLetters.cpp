#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {

    std::string word;
    std::vector<std::set<char>> letters;
    while (std::cin >> word) {
        std::set<char> current;
        for (char c: word) {
            current.insert(c);
        }
        letters.push_back(current);
    }

    std::set<char> temp = letters.front();
    std::set<char> general;
    for (const auto& s: letters) {
        std::set_intersection(temp.begin(), temp.end(), s.begin(), s.end(), std::inserter(general, general.begin()));
        temp = general;
        general.clear();
    }

    for (char c: temp) {
        std::cout << c;
    }

    return 0;
}