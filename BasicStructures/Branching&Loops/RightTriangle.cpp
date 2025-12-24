#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (!(a + b > c && a + c > b && b + c > a)) {
        std::cout << "UNDEFINED" << std::endl;
    }
    else {
        int max = -1;
        for (int el: {a, b ,c}) {
            if (max < el) {
                max = el;
            }
        }

        if ((max == c && a * a + b * b == c * c) || (max == b && a * a + c * c == b * b) || (max == a && b * b + c * c == a * a)) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }

    }
    return 0;
}