#include <iostream>
#include <vector>


template <typename T>
void Print(const T& container, const std::string& delimeter) {
    auto iter = container.begin();
    for (const auto& el: container) {
        std::advance(iter, 1);
        if (iter == container.end()) {
            std::cout << el << std::endl;
            return;
        }
        std::cout << el << delimeter;
    }
}
