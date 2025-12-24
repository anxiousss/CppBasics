#include <iostream>
#include <cmath>

int main() {
    int c1, r1, c2, r2;

    std::cin >> c1 >> r1 >> c2 >> r2;
    if ((abs(c1 - c2) == abs(r1 - r2)) || ((abs(c1 - c1) <= 1 && abs(r1 - r2) <= 1)) ||
        ((c1 == c2 && r1 != r2) || (r1 == r2 && c1 != c2))) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}