#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::unordered_set<int> collection;
    while (std::cin >> n) {
        if (collection.find(n) != collection.end()) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
        collection.insert(n);
    }


    return 0;
}