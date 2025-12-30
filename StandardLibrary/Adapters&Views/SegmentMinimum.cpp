#include <iostream>
#include <set>
#include <queue>

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::queue<size_t> q;
    size_t element;
    std::multiset<size_t> window;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> element;
        q.push(element);
        window.insert(element);
        if (i >= k - 1) {
            std::cout << *window.begin() << std::endl;
            window.erase(q.front());
            q.pop();
        }
    }
    return 0;
}