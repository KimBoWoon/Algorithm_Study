//20113259 ��ǻ�Ͱ��к� 3�г� �躸��
//�˰����� ���� - �Ǻθ��� �̿��� �Ǻ���ġ�� ���
#include <iostream>
#include <fstream>
using namespace std;

int fibo(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n;

		in >> n;

		cout << fibo(n) << endl;
	}
}

int fibo(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}