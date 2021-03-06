//컴퓨터공학부 3학년 20113259
//알고리즘 과제 - MonotoneWalkway
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

typedef struct position {
    int x, y, n;
} Position;

int compXY(const void *x, const void *y) {
    return ((*(Position *) x).x != (*(Position *) y).x) ?
           (*(Position *) x).x - (*(Position *) y).x :
           (*(Position *) x).y - (*(Position *) y).y;
}

int compN(const void *x, const void *y) {
    return (*(Position *) x).n - (*(Position *) y).n;
}

Position pos[MAX];

int main() {
    int testCase;
	FILE* file;

	file = fopen("input.txt", "r");

	fscanf(file, "%d", &testCase);

    while (testCase--) {
        int cafeNum, cnt, i;

		fscanf(file, "%d", &cafeNum);
        memset(pos, 0, sizeof(Position) * MAX);

        for (i = 0; i < cafeNum; i++)
			fscanf(file, "%d %d", &pos[i].x, &pos[i].y);

        qsort(pos, cafeNum, sizeof(Position), compXY);

        int preY = 0, n = 1, x, y;
        for (i = 0; i < cafeNum; i++) {
            int end = i;
            for (x = i + 1; x <= cafeNum; x++) {
                if (pos[i].x == pos[x].x)
                    end = x;
                else
                    break;
            }
            if (pos[i].y >= preY) {
                for (y = i; y <= end; y++)
                    pos[y].n = n++;
                preY = pos[end].y;
            }
            else {
                for (y = end; y >= i; y--)
                    pos[y].n = n++;
                preY = pos[i].y;
            }
            i = end;
        }

        qsort(pos, cafeNum, sizeof(Position), compN);

		fscanf(file, "%d", &cnt);
        for (i = 0; i < cnt; i++) {
            int cafe;
			fscanf(file, "%d", &cafe);
			printf("%d %d\n", pos[cafe - 1].x, pos[cafe - 1].y);
        }
    }
}