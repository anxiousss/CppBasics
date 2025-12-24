#include <iostream>
#include <cmath>

long double member(int n) {
    return powl(-1, n + 1) / n;
}

int main() {
    int n;
    std::cin >> n;
    long double total = 0;
    for (int i = 1; i < n + 1; ++i) {
        total += member(i);
    }

    std::cout << total << std::endl;
    return 0;
}