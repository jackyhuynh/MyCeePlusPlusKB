// Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void matrixprint(vector < vector <float> > &inputmatrix);
vector < vector < float> > blur(vector < vector <float> > &grid, float &blurring);
void normalize(vector< vector <float> > &grid);
vector< vector <float> > move(int dy, int dx, vector < vector <float> > beliefs,
	float blurring);

int main() {
	vector < vector <float> > twodvector;
	vector < vector <float> > grid = {
		{0.00 , 0.00 , 0.00},
		{0.00,  1.00 , 0.00},
		{0.00 , 0.00  ,0.00}
	};
	float value = (float)0.12;
	twodvector = blur(grid, value);
	matrixprint(twodvector);

	return 0;
}

void normalize(vector< vector <float> > &grid) {

	int height = grid.size();
	int width = grid[0].size();
	float total = 0;
	for (int i = 0; i < height; i++) {
		total += (float)accumulate(grid[i].begin(), grid[i].end(), 0);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[i][j]=(float)grid[i][j] / (float)total;
		}
	}
}




void matrixprint(vector < vector <float> > &inputmatrix) {

	for (int row = 0; unsigned(row) < inputmatrix.size(); row++) {
		for (int column = 0; unsigned(column) < inputmatrix[row].size(); column++) {
			cout << inputmatrix[row][column] << " ";
		}
		cout << endl;

	}
}



vector< vector <float> > sense(char color,
	vector< vector <char> > grid,
	vector< vector <float> > beliefs,
	float p_hit,
	float p_miss)
{
	vector< vector <float> > newGrid;
	int height = beliefs.size(); // get number of row
	int width = beliefs[0].size(); // get number of columns
	// your code here
	vector< vector <float> > newBeliefs(height, 
		vector <float> (width, (1/((float)height*(float)width))));
	
	for (int i = 0; i < height; ++i) {
		vector<float> new_row;
		new_row.clear();
		for (int j = 0; j < width; ++j ) {
			bool hit = (color == grid[i][j]);
			new_row.push_back(newBeliefs[i][j] * (hit * p_hit + (1 - hit) * p_miss));
		}
		newGrid.push_back(new_row);
	}

	normalize(newGrid);
	return newGrid;
}


vector < vector <float> > blur(vector < vector < float> > &grid, float &blurring) {
	int height = grid.size();
	int width = grid[0].size();

	// Create window vector
	static float center = 1 - blurring;
	static float corner = blurring / 12;
	static float adjacent = blurring / 6;

	static float window[3][3] = {
		{corner, adjacent,corner},
		{adjacent, center, adjacent},
		{corner, adjacent,corner} };

	// Range vector
	static int range[3] = {-1,0,1};

	// Create vector float hold zero number
	vector < vector <float> > newGrid(height, vector <float>(width, 0.0));

	for (int i = 0; (i) < height; i++) {
		for (int j = 0; (j) < width; j++) {
			float val = grid[i][j];
			for (int dx : range) {
				for (int dy : range) {
					float multiplier = window[dx + 1][dy + 1];
					int new_i = (i + dy + height) % height;
					int new_j = (j + dx + width) % width;
					newGrid[new_i][new_j] += val * multiplier;
				}
			}
		}
	}
	return newGrid;
}




vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	// your code here
	int height = grid.size();
	int width = grid[0].size();
	
	float belief_per_cell = 1 / (float) height * width;

	vector< vector <float> > newGrid(height, vector <float>(width, belief_per_cell));

	return newGrid;
}

vector< vector <float> > move(int dy, int dx,
	vector < vector <float> > beliefs,
	float blurring)
{
	int height = beliefs.size();
	int width = beliefs[0].size();

	vector < vector <float> > newGrid (height, vector <float>(width, 0.0));


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			float cell = beliefs[i][j];
			int new_i = (i + dy) % height;
			int new_j = (j + dx) % width;
			newGrid[new_i][new_j] = cell;
		}
	}

	
	return blur(newGrid, blurring);
}

