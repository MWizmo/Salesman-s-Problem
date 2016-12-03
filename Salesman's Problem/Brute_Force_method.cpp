#include "stdafx.h"
#include "Brute_Force_method.h"

//int counter = 0;

void Brute_Force(int n, matrix Matrix) {
	vector <int> min_way, cur_way;
	int min_length, cur_length;

	for (int i = 0; i < n; i++) {     //Заполнение вектора пути             f=1+3n+
		cur_way.push_back(i + 1);
		//counter += 3;
	}                                        //В нем хранятся посещенные точки     +n*3=1+6n
	cur_way.push_back(cur_way[0]);       //Замыкаем путь,делая цикл           f=3
	//counter++;

	min_way = cur_way; //f=1
	//counter++;
	min_length = Count_Length(Matrix, cur_way, n);  //f=2+12n+1
	Print(Matrix, cur_way, n + 1);
	//F1=6+12n

	while (NextSet(cur_way, n)) {    //Число повторений=n!-1
		cur_way[n] = cur_way[0]; //f=3
		//counter += 3;
		Print(Matrix, cur_way, n + 1);
		cur_length = Count_Length(Matrix, cur_way, n); //f=1+2+12n
		if (cur_length < min_length) {
			min_length = cur_length;
			min_way = cur_way;
			//counter += 3;
		}
	}
	cout << "Min_way is ";
	for (int i = 0; i <= n; i++) {
		cout << min_way[i] << " ";
	}
	cout << endl;
	Print(Matrix, min_way, n + 1);
	cout << "Length is " << min_length << endl;
	//cout << "Counter's time is " << counter / 455546.0 << endl;
}

int Count_Length(matrix Matrix, vector<int> way, int n) {
	int length = 0;
	//counter++;
	for (int i = 0; i < n; i++) {
		length += Matrix[way[i] - 1][way[i + 1] - 1];
		//counter += 9;
	}
	return length;
}

void Vector_Swap(vector<int> &a, int i, int j) {
	int k = a[i];
	a[i] = a[j];
	a[j] = k;
	//counter += 7;
}

bool NextSet(vector <int> &a, int n) {
	int j = n - 2;
	//counter += 2;
	while ((j != -1) && (a[j] >= a[j + 1])) {
		j--;
		//counter += 7;
	}
	if (j == -1) {
		//counter++;
		return false;
	}
	int k = n - 1;
	//counter += 2;
	while (a[j] >= a[k]) {
		k--;
		//counter += 5;
	}
	Vector_Swap(a, j, k);
	int l = j + 1, r = n - 1;
	//counter += 4;
	while (l < r) {
		//counter++;
		Vector_Swap(a, l++, r--);
	}
	return true;
}

void Print(matrix Matrix, vector <int> a, int n) {
	/*static int num = 1;
	cout << "#" << num << ": ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << "Length=" << Count_Length(Matrix, a, n - 1) << endl;
	num++;*/
}