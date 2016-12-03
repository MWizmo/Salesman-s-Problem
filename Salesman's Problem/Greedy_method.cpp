#include "stdafx.h"
#include "Greedy_method.h"

int counter2 = 0;

void Greedy_Algoritm(matrix Graph, int n)
{
	int i;
	route min_route;
	vector <bool> Is_Visited;
	for (i = 0; i < n; i++) {
		Is_Visited.push_back(false);
		counter2 += 4;
	}

	min_route = Find_Shortest_Way(Graph, n, 0,Is_Visited,min_route,counter2);
	min_route.way.push_back(0); 
	min_route.length += Graph[min_route.way[n-1]][0];
	counter2 += 10;

	/*for (i = 1; i < n; i++) {
		counter2 += 3;
		route cur_route;
		cur_route = Find_Shortest_Way(Graph, n, i,Is_Visited,cur_route);
		cur_route.way.push_back(i);
		counter2 += 2;
		cur_route.length += Graph[cur_route.way[n-1]][i];
		counter2 += 6;
		if (cur_route.length < min_route.length) {
			min_route = cur_route;
			counter2 += 4;
		}
	}*/
	cout << "Min way is ";
	for (i = 0; i <= n; i++)
		cout << min_route.way[i]+1 << " ";
	cout << endl << "Length is " << min_route.length << endl;
	cout << "Counter's time is " << counter2 / 45445.0 << endl;

}

route Find_Shortest_Way(matrix Graph, int n, int start, vector<bool> vec,route &min_route,int &counter)
{
	min_route.way.push_back(start);
	vec[start] = true;
	int min_road = 100000, next_point = -1;
	counter += 6;

	for (int i = 0; i < n; i++) {
		counter2 += 3;
		if ((Graph[start][i] < min_road) && (vec[i] == false)&&(Graph[start][i]>0)) {
			min_road = Graph[start][i];
			next_point = i;
			counter += 10;
		}
	}
	if (next_point != -1) {
		min_route.length += min_road;
		counter += 4;
		Find_Shortest_Way(Graph, n, next_point, vec,min_route,counter);
	}

	 return min_route;
}
