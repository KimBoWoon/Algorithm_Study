//컴퓨터공학부 3학년 20113259 
//알고리즘 과제 - MergingFiles 
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define MIN(x, y) (x > y) ? (y) : (x)

int mergeMatrix[501][501] = { 0 };
int file[501] = { 0 };
int sum[501] = { 0 };

int main() {
	int testCase;
	ifstream cin("input.txt");

	cin >> testCase;

	while (testCase--) {
		int size;

		cin >> size;

		memset(file, 0, sizeof(int) * 501);
		memset(sum, 0, sizeof(int) * 501);

		for (int i = 0; i < size; i++) {
			cin >> file[i];
			sum[i + 1] = sum[i] + file[i];
		}

		for (int x = 1; x < size; x++) {
			for (int y = 1; y <= size - x; y++) {
				int j = y + x;
				mergeMatrix[y][j] = 2147483647;
				for (int k = y; k < j; k++)
					mergeMatrix[y][j] = MIN(mergeMatrix[y][j], mergeMatrix[y][k] + mergeMatrix[k + 1][j] + sum[j] - sum[y - 1]);
			}
		}
		cout << mergeMatrix[1][size] << endl;
	}
	return 0;
}