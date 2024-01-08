#include <iostream>
#include <vector>

bool isMagicSquare(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Check if matrix is square
    for (const auto& row : matrix) {
        if (row.size() != n) return false;
    }

    // Calculate the sum of the first row
    int magicSum = 0;
    for (int i = 0; i < n; ++i) {
        magicSum += matrix[0][i];
    }

    // Check each row and column
    for (int i = 0; i < n; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) return false;
    }

    // Check diagonals
    int diagSum1 = 0, diagSum2 = 0;
    for (int i = 0; i < n; ++i) {
        diagSum1 += matrix[i][i];
        diagSum2 += matrix[i][n - 1 - i];
    }
    if (diagSum1 != magicSum || diagSum2 != magicSum) return false;

    return true;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    if (isMagicSquare(matrix)) {
        std::cout << "The matrix is a magic square.\n";
    } else {
        std::cout << "The matrix is not a magic square.\n";
    }

    return 0;
}
