// Exercise 4: Two-Dimensional Arrays - Matrix Operations
// Implement a program that performs operations on 2D arrays:

// Requirements:

// Create two 3x3 matrices (two-dimensional arrays) of integers
// Implement functions that:
// inputMatrix() - accepts a 2D array and populates it with user input
// displayMatrix() - displays a 2D array in table format
// addMatrices() - adds two matrices and stores result in a third matrix
// findRowSum() - calculates and returns the sum of a specified row
// findColumnSum() - calculates and returns the sum of a specified column
// Use nested loops to process rows and columns
// Pass the 2D arrays to functions correctly
// Test your program by:

// Creating and displaying both matrices
// Adding them together and displaying the result
// Calculating and displaying sums for each row and column

#include <iostream>
using namespace std;
const int SIZE = 3;

void inputMatrix(int matrix[SIZE][SIZE], int size) {
    cout << "Enter elements of the matrix (" << size << "x" << size << "):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void addMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void findRowSum(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
    }
}

void findColumnSum(int matrix[SIZE][SIZE], int size) {
    for (int j = 0; j < size; j++) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j << ": " << sum << endl;
    }
}

void sum2Numbers(int a, int b, int &sum) {
    sum = a + b;
    cout << "Sum is: " << sum << endl;
}

int main(){
    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int result[SIZE][SIZE];
    int sum = 0;

    // Function to input matrix
    inputMatrix(matrix1, SIZE);
    inputMatrix(matrix2, SIZE);

    // Function to display matrix
    cout << "Matrix 1:" << endl;
    displayMatrix(matrix1, SIZE);
    cout << "Matrix 2:" << endl;
    displayMatrix(matrix2, SIZE);

    // Adding two matrices
    addMatrices(matrix1, matrix2, result, SIZE);

    sum2Numbers(3, 5, sum); // Example call to sum2Numbers
    cout << "Sum after function call in main: " << sum << endl; // sum remains unchanged

    // Displaying the result
    cout << "Resultant Matrix (Sum):" << endl;
    displayMatrix(result, SIZE);

    // Calculating and displaying row sums
    findRowSum(matrix1, SIZE);
    findRowSum(matrix2, SIZE);
    findRowSum(result, SIZE);

    // Calculating and displaying column sums
    findColumnSum(matrix1, SIZE);
    findColumnSum(matrix2, SIZE);
    findColumnSum(result, SIZE);

    return 0;
}