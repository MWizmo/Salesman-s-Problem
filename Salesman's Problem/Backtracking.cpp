#include "stdafx.h"
#include "Backtracking.h"

void BackTracking_Method(matrix Graph, int n)
{
	int i;
	matrix Copy = Graph;
	vector<int> way;
	vector <bool> flag;
	for (i = 0; i < n; i++)
		flag.push_back(false); 
	way.push_back(0);
	flag[0] = true;
	while (way.size() < n) {
		for (i = 0; i < n; i++)
			Line_Reduction(Graph, n, i);
		for (i = 0; i < n; i++)
			Column_Reduction(Graph, n, i);

		vector<zero_grade> rating = Matrix_Rating(Graph, n);
		for (i = 0; i < rating.size(); i++)
			for (int j = i; j < rating.size(); j++)
				if (rating[j].grade > rating[i].grade)
					swap(rating[i], rating[j]);

		int id = rating[0].i;
		int jd = rating[0].j;
		for (i = 0; i < n; i++)
			Graph[i][jd] = -1;
		for (i = 0; i < n; i++)
			Graph[id][i] = -1;
		if ((flag[id] == false) && (way.size() < n)) {
			way.push_back(id);
			flag[id] = true;
		}
		if ((flag[jd] == false) && (way.size() < n)) {
			way.push_back(jd);
			flag[jd] = true;
		}
	}

	way.push_back(way[0]);
	cout << "Min_way is: ";
	for (i = 0; i < way.size(); i++)
		cout << way[i] + 1 << " ";
	cout << endl;
	Count_Length(Copy, way);
}

void Line_Reduction(matrix &Graph, int n, int i)
{
	int k, min = 10000;
	for (k = 0; k < n; k++) {
		if ((Graph[i][k] < min)&&(Graph[i][k]>-1)) {
			min = Graph[i][k];
		}
	}
	for (k = 0; k < n; k++) {
		if (Graph[i][k]>0) {
			Graph[i][k] -= min;
		}
	}
}

void Column_Reduction(matrix  &Graph, int n, int j)
{
	int k, min = 10000;
	for (k = 0; k < n; k++) {
		if ((Graph[k][j] < min)&&(Graph[k][j]>-1)) {
			min = Graph[k][j];
		}
	}
	for (k = 0; k < n; k++) {
		if (Graph[k][j]>0) {
			Graph[k][j] -= min;
		}
	}
}

vector <zero_grade> Matrix_Rating(matrix Graph, int n) {
	int i, j;
	vector <zero_grade> rating;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (Graph[i][j] == 0) {
				zero_grade new_zero;
				new_zero.i = i;
				new_zero.j = j;
				int k, min_i = 99999, min_j = 99999;
				for (k = 0; k < n; k++)
					if ((Graph[i][k]>-1) && (Graph[i][k] < min_i)&&(k!=j))
						min_i = Graph[i][k];
				for (k = 0; k < n; k++)
					if ((Graph[k][j]>-1) && (Graph[k][j] < min_j)&&(k!=i))
						min_j = Graph[k][j];
				new_zero.grade = min_i + min_j;
				rating.push_back(new_zero);
			}
	return rating;
}

void Count_Length(matrix Graph, vector<int> route) {
	int i, length = 0; 
	for (i = 1; i < route.size(); i++) {
		length += Graph[route[i-1]][route[i]];
	}
	cout << "Length is " << length << endl;
}
