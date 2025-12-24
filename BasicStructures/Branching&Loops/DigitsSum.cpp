#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int total = 0;
    while (n != 0) {
        total += n % 10;
        n /= 10;
    }
    std::cout << total << std::endl;
    return 0;
}