#include <iostream>
#include <string.h>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int team, game;
		int* score = NULL;
		int* lose = NULL;

		cin >> team >> game;

		score = new int[team];
		memset(score, 0, sizeof(int) * team);
		lose = new int[team];
		memset(lose, 0, sizeof(int) * team);

		for (int i = 0; i < game; i++) {
			int a, b, p, q;
			cin >> a >> b >> p >> q;

			score[a - 1] += p;
			score[b - 1] += q;
			lose[a - 1] += q;
			lose[b - 1] += p;
		}

		int max = INT_MIN, min = INT_MAX;
		double Expectation;
		for (int i = 0; i < team; i++) {
			if (score[i] == 0 && lose[i] == 0)
				Expectation = 0;
			else
				Expectation = (pow(score[i], 2) / (pow(score[i], 2) + pow(lose[i], 2))) * 1000;

			if (max < Expectation)
				max = Expectation;
			else if (min > Expectation)
				min = Expectation;
		}
		cout << max << endl << min << endl;
	}
}