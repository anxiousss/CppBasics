#include <iostream>
#include <set>
#include <queue>

int main() {
    size_t n, k;
    std::cin >> n >> k;

    if (n == 0 || k == 0 || k > n) {
        return 0;
    }

    std::queue<int> q;
    std::multiset<int> window;
    int element;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> element;
        q.push(element);
        window.insert(element);

        if (i >= k - 1) {
            std::cout << *window.begin() << ' ';
            int front_val = q.front();
            q.pop();
            auto it = window.find(front_val);
            window.erase(it);
        }
    }
    return 0;
}