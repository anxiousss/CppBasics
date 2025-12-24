#include <iostream>
#include <iomanip>

void printCalendar(int startDay, int numDays) {
    int day = 1;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i == 0 && j < startDay - 1) {
                std::cout << "   ";
            } else if (day > numDays) {
                std::cout << "   ";
            } else {
                std::cout << std::setw(2) << day << " ";
                ++day;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int startDay, numDays;
    std::cin >> startDay >> numDays;
    printCalendar(startDay, numDays);
    return 0;
}