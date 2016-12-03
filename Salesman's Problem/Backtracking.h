#pragma once
#include "stdafx.h"

struct zero_grade {
	int i, j, grade;
};

void BackTracking_Method(matrix Graph, int n);
void Line_Reduction(matrix &Graph, int n, int i);
void Column_Reduction(matrix &Graph, int n, int j);
vector <zero_grade> Matrix_Rating(matrix Graph, int n);
void Count_Length(matrix Graph, vector<int> route);