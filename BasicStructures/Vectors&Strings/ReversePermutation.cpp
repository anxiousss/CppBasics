#include <iostream>
#include <vector>


int main()  {
    size_t n;
    std::cin >> n;

    std::vector<size_t> places(n);
    size_t place;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> place;
        places[place] = i + 1;
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << places[i] << ' ';
    }
    std::cout << std::endl;

}