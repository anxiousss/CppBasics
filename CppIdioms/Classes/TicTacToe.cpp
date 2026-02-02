#include <iostream>
#include <vector>


class TicTacToe {
public:
    const size_t N;  // размер игрового поля
    const size_t K;  // сколько фишек нужно поставить в ряд, чтобы выиграть


private:
    int currentPlayer;
    std::vector<std::vector<int>> Table;

public:
    TicTacToe(size_t n, size_t k): N(n), K(k), currentPlayer(1) {
        Table = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return currentPlayer;
    }

    bool Set(size_t i, size_t j) {
        Table[i][j] = currentPlayer;
        currentPlayer = currentPlayer % 2 + 1;
        bool wins = CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
        return wins;
    }

private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= j && Table[i][j - d1] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (j + d2 < N && Table[i][j + d2] == Table[i][j]) {
            ++d2;
        }

        return d1 + d2 > K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= i && Table[i - d1][j] == Table[i][j]) {
            ++d1;
        }

        size_t d2 = 0;
        while (i + d2 < N && Table[i + d2][j] == Table[i][j]) {
            ++d2;
        }

        return d1 + d2  > K;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        int row = i, column = j;
        while (row != 0 && column > 0) {
            --row;
            --column;
        }
        size_t cells = 0;
        int state = Table[i][j];
        while (column < static_cast<int>(N) && row < static_cast<int>(N)) {
            if (Table[row][column] == state)
                ++cells;
            else
                cells = 0;
            ++row;
            ++column;
        }
        return K <= cells;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        int row = i, column = j;
        while (row != 0 && column + 1 < static_cast<int>(N)) {
            --row;
            ++column;
        }
        size_t cells = 0;
        int state = Table[i][j];
        while (column > -1 && row < static_cast<int>(N)) {
            if (Table[row][column] == state)
                ++cells;
            else
                cells = 0;
            ++row;
            --column;
        }
        return K <= cells;
    }
};

std::ostream& operator << (std::ostream& out, TicTacToe& field) {
    for (size_t i = 0; i < field.N; ++i) {
        for (size_t j = 0; j < field.N; ++j) {
            switch (field(i, j)) {
                case 0:
                    out << '.';
                    break;
                case 1:
                    out << 'X';
                    break;
                case 2:
                    out << 'O';
                    break;
            }
        }
        out << "\n";
    }
    return out;
}


int main() {
    size_t n, m;
    std::cin >> n >> m;
    TicTacToe game(n, m);
    size_t x, y;
    while (std::cin >> x >> y) {
        int curPlayer = game.GetCurrentPlayer();
        if (game.Set(x, y)) {
            std::cout << "Player #" << curPlayer << " wins!\n";
        }
        std::cout << game << std::endl;
    }
    std::cout << game;
}