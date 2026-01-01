#include <iostream>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int> pq;
    std::string command;

    while (std::cin >> command) {
        if (command == "CLEAR") {
            while (!pq.empty()) {
                pq.pop();
            }
        } else if (command == "ADD") {
            int value;
            std::cin >> value;
            pq.push(value);
        } else if (command == "EXTRACT") {
            if (pq.empty()) {
                std::cout << "CANNOT" << std::endl;
            } else {
                std::cout << pq.top() << std::endl;
                pq.pop();
            }
        }
    }

    return 0;
}