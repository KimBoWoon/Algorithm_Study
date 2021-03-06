// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - 방의 크기 구하기
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;

int roomSize(char **matrix, int x, int y, int row, int col);

int main() {
	ifstream in;
	int testCase = 0;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int row = 0, col = 0, size = 0;
		char **matrix = NULL;
		vector<int> v;

		in >> col >> row;
		
		matrix = new char*[row];
		memset(matrix, 0, sizeof(char*) * row);
		for (int x = 0; x < row; x++) {
			matrix[x] = new char[col];
			memset(matrix[x], 0, sizeof(char) * col);
		}

		for (int x = 0; x < row; x++) {
			for (int y = 0; y < col; y++) {
				in >> matrix[x][y];
			}
		}
		for (int x = 1; x < row; x++) {
			for (int y = 1; y < col; y++) {
				size = roomSize(matrix, x, y, row, col);
				if (size != 0)
					v.push_back(size);
			}
		}
		sort(v.begin(), v.end(), greater<int>());

		cout << v.size() << endl;
		for (int x = 0; x < v.size(); x++)
			cout << v[x] << ' ';
		cout << endl;
	}
}
int roomSize(char **matrix, int x, int y, int row, int col) {
	int count = 0;

	if ((x < row && y < col) || (x > 0 && y > 0)) {
		if (matrix[x][y] == '.') {
			count++;
			matrix[x][y] = 'x';
			if (matrix[x][y + 1] != '+' || matrix[x + 1][y] != '+' || matrix[x][y + 1] != 'x' || matrix[x + 1][y] != 'x' || 
				matrix[x][y - 1] != '+' || matrix[x - 1][y] != '+' || matrix[x][y - 1] != 'x' || matrix[x - 1][y] != 'x') {
				count += roomSize(matrix, x, y + 1, row, col);
				count += roomSize(matrix, x, y - 1, row, col);
				count += roomSize(matrix, x + 1, y, row, col);
				count += roomSize(matrix, x - 1, y, row, col);
			}
		}
	}
	return count;
}