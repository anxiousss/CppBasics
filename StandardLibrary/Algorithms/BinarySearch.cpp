#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::cin.ignore();

    std::vector<int> arr1, arr2;

    int number;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> number;
        arr1.push_back(number);
    }

    std::cin.ignore();
    for (size_t i = 0; i < k; ++i) {
        std::cin >> number;
        arr2.push_back(number);
    }
    std::cout << '\n';

    for (size_t i = 0; i < k; ++i) {
        auto less_it = std::lower_bound(arr1.begin(), arr1.end(), arr2[i]);
        auto greater_it = std::upper_bound(arr1.begin(), arr1.end(), arr2[i]);
        if (less_it == arr1.begin() || greater_it == arr1.begin()){
            std::cout << arr1[0] << std::endl;
            continue;
        } else if (*less_it == arr2[i]) {
            std::cout << arr2[i] << std::endl;
        } else {
            if (abs(*std::prev(less_it) - arr2[i]) > abs(*greater_it - arr2[i])) {
                std::cout << *greater_it << std::endl;
            } else {
                std::cout << *std::prev(less_it) << std::endl;
            }
        }
    }

    return 0;
}