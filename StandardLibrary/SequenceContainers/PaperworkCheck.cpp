#include <iostream>
#include <deque>

int main() {
    int n;
    std::cin >> n;
    std::deque<std::string> pages;

    for (int i = 0; i < n; ++i) {
        std::string name, side;
        std::cin >> name >> side;
        if (side == "top") {
            pages.push_front(name);
        } else {
            pages.push_back(name);
        }
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int numer;
        std::cin >> numer;
        std::cout << pages[numer - 1] << std::endl;
    }

    return 0;
}