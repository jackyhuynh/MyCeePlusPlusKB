#include "matrix.h"

Matrix::Matrix() {
    vector <vector <float> > initial_grid(10, vector <float>(5, 0.5));
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();

}

Matrix::Matrix(vector <vector <float> > initial_grid) {
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();
}

void Matrix::setGrid(vector< vector<float> > new_grid) {
    grid = new_grid;
    rows = new_grid.size();
    cols = new_grid[0].size();

}

vector< vector<float> > Matrix::getGrid() {
    return grid;
}

vector<float>::size_type Matrix::getRows() {
    return rows;
}

vector<float>::size_type Matrix::getCols() {
    return cols;
}

Matrix Matrix::matrix_transpose() {
    vector< vector<float> > new_grid;
    vector<float> row;

    for (int i = 0; i < cols; i++) {
        row.clear();

        for (int j = 0; j < rows; j++) {
            row.push_back(grid[j][i]);
        }
        new_grid.push_back(row);
    }

    return Matrix(new_grid);
}

Matrix Matrix::matrix_addition(Matrix other) {

    if ((rows != other.getRows()) || (cols != other.getCols())) {
        throw invalid_argument("matrices are not the same size");
    }

    vector< vector<float> > othergrid = other.getGrid();

    vector< vector<float> > result;

    vector<float> new_row;

    for (int i = 0; i < rows; i++) {
        new_row.clear();
        for (int j = 0; j < cols; j++) {
            new_row.push_back(grid[i][j] + othergrid[i][j]);
        }
        result.push_back(new_row);
    }

    return Matrix(result);
}

void Matrix::matrix_print() {

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
