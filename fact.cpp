//20113259 ��ǻ�Ͱ��к� 3�г� �躸��
//�˰����� ���� - �Ǻθ��� �̿��� ���丮�� ���
#include <iostream>
#include <fstream>
using namespace std;

int fact(int n);

int main() {
	ifstream in;
	int testCase;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n = 0;

		in >> n;

		cout << fact(n) << endl;
	}
}

int fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}