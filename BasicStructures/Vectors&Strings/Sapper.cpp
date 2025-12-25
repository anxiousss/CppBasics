#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    size_t m, n, k;
    std::cin >> m >> n >> k;

    std::vector<std::pair<size_t, size_t>> mines_coords;

    size_t x, y;
    for (size_t i = 0; i < k; ++i) {
        std::cin >> x >> y;
        mines_coords.emplace_back(x, y);
    }

    std::vector<std::vector<char>> field(m + 2, std::vector<char>(n + 2, '0'));

    for (const auto& p: mines_coords) {
        field[p.first][p.second] = '*';
    }

    for (size_t i = 1; i < m + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            if (field[i][j] != '*') {
               std::string value{field[i - 1][j - 1], field[i - 1][j], field[i - 1][j + 1], field[i][j - 1],
                                 field[i][j + 1], field[i + 1][j - 1], field[i + 1][j], field[i + 1][j + 1]};
               field[i][j] = std::count(value.begin(), value.end(), '*') + '0';
            }
        }
    }

    for (size_t i = 1; i < m + 1 ; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}