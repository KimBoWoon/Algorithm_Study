// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - 정렬된 순열 구하기
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int fact(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int size = 0, cnt = 0, f = 0;
		string str = "abcdefghijkl";
		string result = "";
		
		in >> size >> cnt;
		
		for (int f = fact(--size), k = cnt - 1; size >= 1; size--) {
			int select = k / f;
			k %= f;

			result += str[select];
			str.erase(select, 1);
			f /= size;
		}
		cout << result << str[0] << endl;
	}
}

int fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}