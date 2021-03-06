// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - Ducci Sequence 
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int size = 0, cnt = 0;
		vector<int> before;
		vector<int> after;

		in >> size;

		before.resize(size);
		after.resize(size);

		for (size_t x = 0; x < size; x++) {
			in >> before[x];
			after[x] = before[x];
		}

		for (int y = 0;; y++) {
			for (size_t x = 0; x < size; x++) {
				if (x == size - 1)
					after[x] = abs((double)before[x] - (double)before[0]);
				else
					after[x] = abs((double)before[x] - (double)before[x + 1]);
			}
			for (size_t x = 0; x < size; x++) {
				if (after[x] == 0)
					cnt++;
			}

			if (after.size() == cnt) {
				cout << "ZERO" << endl;
				break;
			}
			else
				cnt = 0;

			for (size_t x = 0; x < size; x++) {
				before[x] = after[x];
			}
			if (y > 1000) {
				cout << "LOOP" << endl;
				break;
			}
		}
	}
}