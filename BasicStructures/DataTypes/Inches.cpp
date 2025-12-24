#include <iostream>

int main() {
    double cm;
    const double transition = 2.54;
    std::cin >> cm;
    std::cout << cm / transition << std::endl;
    return 0;
}