#include <iostream>

using namespace std;

int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int sumInColumnsWithNegative(int** matrix, int rows, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] < 0) {
                sum += matrix[i][j];
                break;  
            }
        }
    }
    return sum;
}

void findSaddlePoints(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int minInRow = matrix[i][0];
        int minCol = 0;

        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                minCol = j;
            }
        }

        bool saddlePoint = true;
        for (int k = 0; k < rows; ++k) {
            if (matrix[k][minCol] > minInRow) {
                saddlePoint = false;
                break;
            }
        }

        if (saddlePoint) {
            setlocale(LC_ALL, "ukr");
            cout << "Сідлова точка: (" << i << ", " << minCol << ")" << endl;
        }
    }
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    setlocale(LC_ALL, "ukr");
    cout << "Введіть кількість рядків та стовпців матриці: ";
    cin >> rows >> cols;

    int** matrix = createMatrix(rows, cols);
    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    setlocale(LC_ALL, "ukr");
    cout << "Ваша матриця:\n";
    printMatrix(matrix, rows, cols);
  
    int sumInColsWithNegatives = sumInColumnsWithNegative(matrix, rows, cols);
    setlocale(LC_ALL, "ukr");
    cout << "Сума елементів в стовпцях з від'ємним елементом: " << sumInColsWithNegatives << endl;
  
    setlocale(LC_ALL, "ukr");
    cout << "Сідлові точки матриці:\n";
    findSaddlePoints(matrix, rows, cols);
  
    deleteMatrix(matrix, rows);

    return 0;
}
