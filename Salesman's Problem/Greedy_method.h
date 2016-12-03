#pragma once
#include "stdafx.h"

struct route {
	vector <int> way;
	int length=0;
};

void Greedy_Algoritm(matrix Graph, int n);
route Find_Shortest_Way(matrix Graph, int n, int start,vector<bool> vec, route &min_route,int &counter);