//20113259 컴퓨터공학부 3학년 김보운
//알고리즘 과제 - 유클리드 알고리즘
#include <iostream>
#include <fstream>
using namespace std;

int euclid(int x, int y);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int x = 0, y = 0;

		in >> x >> y;

		cout << euclid(x, y) << endl;
	}
}

int euclid(int x, int y) {
	if (y == 0)
		return x;
	else
		return euclid(y, x % y);
}