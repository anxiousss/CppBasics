#include <iostream>
#include <deque>
#include <utility>

void MakeTrain() {
    std::deque<int> train;
    std::pair<std::string, int> p;

    while (std::cin >> p.first >> p.second) {
        if (p.first == "+left") {
            train.push_front(p.second);
        } else if (p.first == "+right") {
            train.push_back(p.second);
        } else if (p.first == "-left") {
            while (p.second != 0 && !train.empty()) {
                train.pop_front();
                --p.second;
            }
        } else if (p.first == "-right") {
            while (p.second != 0 && !train.empty()) {
                train.pop_back();
                --p.second;
            }
        }
    }

    for (int w: train) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
}
