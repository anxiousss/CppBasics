#include <iostream>
#include <vector>
#include <utility>
#include <climits>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    std::pair<size_t, size_t> max_ind;
    int max_el = INT_MIN;
    size_t row = matrix.size();
    size_t col = matrix[0].size();
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            if (max_el < matrix[i][j]) {
                max_el = matrix[i][j];
                max_ind.first = i; max_ind.second = j;
            }
        }
    }
    return max_ind;
}