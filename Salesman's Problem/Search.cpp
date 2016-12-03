#include "stdafx.h"
#include "Search.h"
#include "Greedy_method.h"

void Local_Search(matrix Graph, int n,int depth)
{
	int i, j, counter = 0;
	route min_route;
	vector <bool> Was_Visited;
	for (i = 0; i < n; i++) 
		Was_Visited.push_back(false);

	counter += n + 1;
	min_route = Find_Shortest_Way(Graph, n, 0, Was_Visited, min_route,counter);
	min_route.way.push_back(0);
	min_route.length += Graph[min_route.way[n - 1]][0];
	counter += 8;

	vector<int>Available_Variants;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (i != j) {
				Available_Variants.push_back(i);
				Available_Variants.push_back(j);
				counter += 8;
			}
	counter += 3;
	int cur = 0;

	while(cur<Available_Variants.size()){
		counter += 3;
		vector <bool> Is_Visited;
		for (i = 0; i < n; i++)
			Is_Visited.push_back(false);
		counter += n + 1;

				matrix Graph2 = Graph;
				if ((cur + depth*depth) <= Available_Variants.size()) {
					counter += 6;
					for (i = 0; i < depth; i++)
					{
						counter += 17;
						Graph2[Available_Variants[cur]][Available_Variants[cur + 1]] = -1;
						Graph2[Available_Variants[cur + 1]][Available_Variants[cur]] = -1;
						cur += 2;
					}
				}
				else break;
					route cur_route;
					cur_route = Find_Shortest_Way(Graph2, n, 0, Is_Visited, cur_route,counter);
					cur_route.way.push_back(0);
					counter++;
					if (Graph2[cur_route.way[cur_route.way.size()-2]][0]>0) {
						counter += 15;
						cur_route.length += Graph2[cur_route.way[cur_route.way.size() - 2]][0];
						if ((cur_route.length < min_route.length) && (cur_route.way.size() == min_route.way.size())) {
							counter += 9;
							min_route = cur_route;
						}
					}
			}
	cout << "Min way is ";
	for (i = 0; i <min_route.way.size(); i++)
		cout << min_route.way[i] + 1 << " ";
	cout << endl << "Length is " << min_route.length << endl;
	//cout << "Counter's time is " << counter / 455546.0 << endl;
}
