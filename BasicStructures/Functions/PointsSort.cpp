#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return std::hypot(a.first, a.second) < std::hypot(b.first, b.second);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    std::sort(points.begin(), points.end(), cmp);

    for (const std::pair<int, int>& p: points) {
        std::cout << p.first << ' ' << p.second << std::endl;
    }
    return 0;
}