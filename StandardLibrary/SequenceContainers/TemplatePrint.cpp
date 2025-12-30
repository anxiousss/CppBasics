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

int main() {
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");  // 1, 2, 3, 4
}