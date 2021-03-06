// 20113259 컴퓨터공학부 3학년 김보운
// 알고리즘 과제 - Goldbach’s Conjecture
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

bool primeNumber(int n);
void sum(vector<int> vec, int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n;
		vector<int> vec;

		in >> n;

		for (int x = 2; x < n; x++) {
			if (primeNumber(x))
				vec.push_back(x);
		}
		sum(vec, n);
	}
}

bool primeNumber(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void sum(vector<int> vec, int n) {
	int n1 = 0, n2 = 0, min = 1001;

	for (size_t x = 0; x < vec.size(); x++) {
		for (size_t y = 0; y < vec.size(); y++) {
			if (vec[x] + vec[y] == n) {
				if (vec[x] - vec[y] < min) {
					n1 = vec[x];
					n2 = vec[y];
					min = abs((double)vec[x] - (double)vec[y]);
				}
			}
		}
	}
	cout << n1 << ' ' << n2 << endl;
}