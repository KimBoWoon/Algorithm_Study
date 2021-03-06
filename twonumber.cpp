//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - Two Number
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	while (testCase--) {
		int size, k, cnt = 0;
		vector<int> vec;

		in >> size >> k;

		for (int i = 0; i < size; i++) {
			int temp;
			in >> temp;
			vec.push_back(temp);
		}

		sort(vec.begin(), vec.end(), less<int>());

		int sum = vec[0] + vec[vec.size() - 1];
		int m = abs((double)k - (double)sum);
		for (int start = 0, end = vec.size() - 1; start < end;) {
			sum = vec[start] + vec[end];

			if (k - sum > 0) {
				start++;
			}
			else if (k - sum <= 0) {
				end--;
			}

			if (m == abs((double)k - (double)sum)) {
				cnt++;
			}
			else if (m > abs((double)k - (double)sum)) {
				m = abs((double)k - (double)sum);
				cnt = 1;
			}
		}
		cout << cnt << endl;
	}
}