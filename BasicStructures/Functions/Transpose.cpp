#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    std::vector<std::vector<int>> tr(col, std::vector<int> (row));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tr[j][i] = matrix[i][j];
        }
    }
    return tr;
}