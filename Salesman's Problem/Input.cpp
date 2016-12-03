#include "stdafx.h"
#include "Input.h"

matrix Input_Graph() {
	ifstream File("Input.txt", ios_base::in);
	matrix Input_Matrix;
	int n;
	File >> n;
	for (int i = 0; i < n; i++) {
		vector<int> vec;
		for (int j = 0; j < n; j++) {
			int a;
			File >> a;
			vec.push_back(a);
		}
		Input_Matrix.push_back(vec);
	}
	File.close();
	return Input_Matrix;
}

int Read_n() {
	ifstream File("Input.txt", ios_base::in);
	int n;
	File >> n;
	File.close();
	return n;
}

matrix Creating_Random_Matrix(int n) {
	matrix Graph;
	int i, j;
	for (i = 0; i < n; i++) {
		vector<int> vec;
		for (j = 0; j < n; j++)
			vec.push_back(0);
		Graph.push_back(vec);
	}
	srand(clock());
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if ((i != j) && (Graph[i][j] == 0)) {
				Graph[i][j] = rand() % 20 + 1 ;
				Graph[j][i] = Graph[i][j];
			}
			else if (i == j)
				Graph[i][j] = -1;
	return Graph;
}