#include "logger.h"
#include <list>

int main() {
    int n;
    std::cin >> n;

    std::list<Logger> list;
    for (int i = 0; i < n; ++i) {
        list.emplace_back();
    }

}