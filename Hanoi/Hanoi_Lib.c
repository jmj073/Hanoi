#define _CRT_SECURE_NO_WARNINGS
#include "Hanoi_H.h"

int Max;
int Stack[4][21];
int Top[4];

//원판 개수 입력받기
void Input_Disk() {
	int n;
	while (1) {
		printf("몇개의 원판을 사용하시겠습니까? (3~20)\n입력:");
		scanf("%d", &n), getchar();
		if (3 <= n && n <= 20)
			break;
		printf("잘못된 값을 입력하셨습니다(%d)", n);
		getchar();
		system("cls");
	}
	Max = n;
	Set_Disk();
}

// 원판 세팅
static void Set_Disk() {
	int i;
	for (i = Max; i > 0; i--)
		Stack[1][++Top[1]] = i;
}

//메인 하노이
void Hanoi_Main() {
	int n, m=1, cnt=0;
	while (1) {
		system("cls");
		Print_Hanoi();
		printf("\n\n옮긴 횟수:%d\n", cnt);
		printf("옮길 원판의 위치와 원판의 최종 위치를 입력하세요 ex)1 2\n입력:");
		if (m != 1 && Top[m] == Max)
			break;
		scanf("%d %d", &n, &m), getchar();
		if (1 <= n && n <= 3 && 1 <= m && m <= 3 &&
			Stack[n][Top[n]] &&
			(!Stack[m][Top[m]] || Stack[n][Top[n]] < Stack[m][Top[m]])) {
			Move_Disk(n, m);
			cnt++;
		}
		else {
			printf("잘못된 값을 입력하셨습니다");
			getchar();
			continue;
		}
	}
}

//원판 옮기기
void Move_Disk(int n, int m) {
	Stack[m][++Top[m]] = Stack[n][Top[n]];
	Stack[n][Top[n]--] = 0;
}

//테스트 함수들을 위한 조건부 컴파일
#ifdef TEST

void Print_Hanoi() {
	int i, j;
	for (i = Max; i > 0; i--) {
		for (j = 1; j <= 3; j++)
			printf("%d\t", Stack[j][i]);
		printf("\n");
	}
}

#endif //TEST