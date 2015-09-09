//20113259 ��ǻ�Ͱ��к� 3�г� �躸��
//�˰����� ���� - Driving License
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
using namespace std;

//��Ʈ���� �����Ҵ�
int** matrixAllocation(int m, int n);
//��Ʈ���� �Է�
void matrixInput(ifstream &in, int **mat, int m, int n);
//�������� ����
void drivingLicense(int **m1, int **m2, int m, int n, int l, int g);
//��Ʈ���� �����Ҵ� ��ȯ
void deleteMatrix(int** mat, int m);

//0 ������ 1 �Ʒ�
//drivint[row][col][rotate][direction]
int driving[101][101][201][2];

int main() {
	ifstream in;
	int testCase = 0;

	in.open("input.txt");

	in >> testCase;

	for (int i = 0; i < testCase; i++) {
		int m = 0, n = 0, l = 0, g = 0;
		int rotate = 0;
		int **m1 = NULL;
		int **m2 = NULL;

		in >> m >> n >> l >> g;
		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				for (int z = 0; z < 201; z++) {
					for (int t = 0; t < 2; t++) {
						driving[x][y][z][t] = -1;
					}
				}
			}
		}
		//memset(driving, -1, sizeof(driving));
		driving[0][0][0][0] = driving[0][0][0][1] = 0;

		m1 = matrixAllocation(m, n);
		m2 = matrixAllocation(m, n);

		matrixInput(in, m1, m, n - 1);
		matrixInput(in, m2, m - 1, n);

		drivingLicense(m1, m2, m, n, l, g);

		deleteMatrix(m1, m);
		deleteMatrix(m2, m);
	}
}
int** matrixAllocation(int m, int n) {
	int **mat = NULL;

	mat = new int*[m];
	for (int x = 0; x < m; x++)
		mat[x] = new int[n];

	return mat;
}
void matrixInput(ifstream &in, int **mat, int m, int n) {
	int temp = 0;

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			in >> temp;
			mat[x][y] = temp;
		}
	}
}
void drivingLicense(int **m1, int **m2, int m, int n, int l, int g) {
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			for (int z = 0; z < 201; z++) {
				if (driving[x][y][z][0] != -1) {
					if (x < m - 1) {
						//�̹� ���� ������ ������ �� �� �������� �־��ش�
						if (driving[x + 1][y][z + 1][1] != -1)
							driving[x + 1][y][z + 1][1] = min(driving[x][y][z][0] + m2[x][y], driving[x + 1][y][z + 1][1]);
						//���� ������ ���� ��뷮�� �־��ش�
						else
							driving[x + 1][y][z + 1][1] = driving[x][y][z][0] + m2[x][y];
					}
					if (y < n - 1) {
						if (driving[x][y + 1][z][0] != -1)
							driving[x][y + 1][z][0] = min(driving[x][y][z][0] + m1[x][y], driving[x][y + 1][z][0]);
						else
							driving[x][y + 1][z][0] = driving[x][y][z][0] + m1[x][y];
					}
				}
				if (driving[x][y][z][1] != -1) {
					if (x < m - 1) {
						if (driving[x + 1][y][z][1] != -1)
							driving[x + 1][y][z][1] = min(driving[x][y][z][1] + m2[x][y], driving[x + 1][y][z][1]);
						else
							driving[x + 1][y][z][1] = driving[x][y][z][1] + m2[x][y];
					}
					if (y < n - 1) {
						if (driving[x][y + 1][z + 1][0] != -1)
							driving[x][y + 1][z + 1][0] = min(driving[x][y][z][1] + m1[x][y], driving[x][y + 1][z + 1][0]);
						else
							driving[x][y + 1][z + 1][0] = driving[x][y][z][1] + m1[x][y];
					}
				}
			}
		}
	}
	//����ȭ�� ȸ��Ƚ���� ���Ѵ�
	int best = -1;

	for (int x = 0; x < 201; x++) {
		//-1�� �Ҵ���� ���� ��
		//������������ �ʿ��� ���ָ��纸�� ������ ������ ���̴�
		//x�� ȸ��Ƚ���� ��Ÿ��
		if (driving[m - 1][n - 1][x][0] != -1 && driving[m - 1][n - 1][x][0] <= g ||
			driving[m - 1][n - 1][x][1] != -1 && driving[m - 1][n - 1][x][1] <= g) {
			best = x;
			break;
		}
	}
	if (best == -1)
		cout << -1 << endl;
	else
		cout << (m + n - 2) * l + best << endl;
}
void deleteMatrix(int** mat, int m) {
	for (int x = 0; x < m; x++)
		delete[] mat[x];
	delete[] mat;
}