#include "stdafx.h"
#include "Input.h"
#include "Brute_Force_method.h"
#include "Greedy_method.h"
#include "Backtracking.h"
#include "Search.h"

void Print_Matrix(matrix a,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int n;
	setlocale(LC_ALL, "rus");
	for (;;) {
		cout << "¬ведите n >> ";
		cin >> n;
		matrix Graph = Creating_Random_Matrix(n);
	//n = Read_n();
	//matrix Graph = Input_Graph();
		cout << "Matrix:" << endl;
		Print_Matrix(Graph, n);
		float start = clock();
		cout << "#1" << endl;
		Brute_Force(n, Graph);
		//BackTracking_Method(Graph, n);
		cout << "#2" << endl;
		//Greedy_Algoritm(Graph, n);
		for (int i = 1; i < n-1; i++) {
			cout << "\nDepth:" << i << endl;
			Local_Search(Graph, n,i);
		}
		float end = clock();
		//cout << "Time= " << (end - start) / 1000.0 << endl;
		//system("pause");
	}
		
	system("pause");
    return 0;
}

