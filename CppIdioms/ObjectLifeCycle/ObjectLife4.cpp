#include "logger.h"
#include <list>

int main() {
    std::list<Logger> list;
    list.emplace_back();
    list.emplace_back();
    list.emplace_back();
    list.erase(std::next(list.begin(), 1));
    list.erase(std::next(list.end(), - 1));
}