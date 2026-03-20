#include <iostream>
#include <vector>

template <typename T>
class Table {
public:
    size_t n_rows, n_columns;
    std::vector<std::vector<T>> table;
    Table(size_t rows, size_t columns);

    void resize(size_t new_rows, size_t new_columns);
    std::pair<size_t, size_t> size() const;

    const std::vector<T>& operator[](size_t index) const;
    std::vector<T>& operator[](size_t index);

};

template<typename T>
std::pair<size_t, size_t> Table<T>::size() const {
    return {n_rows, n_columns};
}

template<typename T>
void Table<T>::resize(size_t new_rows, size_t new_columns) {
    table.resize(new_rows);
    for (size_t i = 0; i < new_rows; ++i) {
        table[i].resize(new_columns);
    }
    n_rows = new_rows; n_columns = new_columns;
}

template<typename T>
std::vector<T> &Table<T>::operator[](size_t index) {
    return table[index];
}

template<typename T>
const std::vector<T>& Table<T>::operator[](size_t index) const {
    return table[index];
}

template<typename T>
Table<T>::Table(size_t rows, size_t columns): n_rows(rows), n_columns(columns) {
    table = std::vector<std::vector<T>>(rows, std::vector<T>(columns));
}

template<typename T>
void print(const Table<T>& table) {
    for (size_t i = 0; i < table.n_rows; ++i) {
        for (size_t j = 0; j < table.n_columns; ++j) {
            std::cout << table[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Table<int> table(2, 3);
    table[0][0] = 1;
    std::cout << table.size().first << ' ' << table.size().second << std::endl;

    print(table);
    table.resize(2 ,2);
    print(table);
    std::cout << table.size().first << ' ' << table.size().second << std::endl;
}