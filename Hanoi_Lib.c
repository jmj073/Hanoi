#include "Hanoi_H.h"

#define GET_TOP(i) Stack[i][Top[i]]

// getch 사용 여부
#define USE_getch

//원판 개수 입력받기
void Input_Disk(HANOI* Hanoi) {
	int n;
	while (1) {
		printf("몇개의 원판을 사용하시겠습니까? (%d~%d)\n입력:", MIN_DISK, MaxDisk - 1);
		scanf("%d", &n);
		wait_ent;
		if (MIN_DISK <= n && n < MaxDisk)
			break;
		printf("잘못된 값을 입력하셨습니다(%d)\n", n);
		wait_ent;
		system("cls");
	}
	Hanoi->Max = n;
	Set_Disk(Hanoi);
}

// 원판 세팅
static void Set_Disk(HANOI* Hanoi) {
	int i;
	int(*Stack)[MaxDisk] = Hanoi->Stack;
	int* Top = Hanoi->Top;
	for (i = Hanoi->Max; i > 0; i--)
		Stack[1][++Top[1]] = i;
}

//메인 하노이
clock_t Hanoi_Main() {
	HANOI Hanoi = { 0 };
	int Max;
	int(*Stack)[MaxDisk] = Hanoi.Stack;
	int* Top = Hanoi.Top;
	int n, m = 1, cnt = 0, auto_bool;
	UI B_UI;
	clock_t time_score = 0;
	int auto_list[11] = { 0, };

	printf("1.플레이 2.자동\n입력:");
	scanf("%d", &auto_bool);
	wait_ent;

	Input_Disk(&Hanoi);
	Max = Hanoi.Max;

	if (auto_bool == 2) {
		//Auto_Hanoi(&Hanoi, Max, 1, 3, 2);
		Auto_Stack_Hanoi(&Hanoi);
		sleep(wait_second);
		system("cls");
		GPrint_Hanoi(Max, Stack);
		return -3110;
	}

	printf("UI를 고르십시오 1.숫자형태(1) 2.블록형태(■)\n입력:");
	scanf("%d", &n);
	wait_ent;
	B_UI = n == 1 ? UI_NUM : UI_GRP;

	time_score = clock();
	while (1) {
		system("cls");
		if (B_UI == UI_NUM)
			Print_Hanoi(Max, Stack);
		else
			GPrint_Hanoi(Max, Stack);
		printf("\n\n옮긴 횟수:%d\n", cnt);
		if (m != 1 && Top[m] == Max)
			break;
		printf("옮길 원판의 위치와 원판의 최종 위치를 입력하세요 ex)12 (힌트(beta)는 (00))"
			"\n입력:");
#ifdef USE_getch
		n = getch() - '0', m = getch() - '0';
#elif
		scanf("%1d%1d", &n, &m);
		wait_ent;
#endif
		if (!(n || m)) {
			m = Hint_Hanoi(&Hanoi, auto_list);
		}
		else if (1 <= n && n <= 3
			&& 1 <= m && m <= 3
			&& Stack[n][Top[n]]
			&& (!GET_TOP(m) || GET_TOP(n) < GET_TOP(m))) {
			Move_Disk(&Hanoi, n, m);
		}
		else {
			printf("잘못된 값을 입력하셨습니다");
			wait_ent;
			continue;
		}
		cnt++;
		if ((Stack[m][Top[m] - 1] - GET_TOP(m)) % 2 || Top[m] == 1)
			Set_Auto_List(Max, auto_list);
		auto_list[GET_TOP(m)] = GET_TOP(m);
	}
	return clock() - time_score;
}

//원판 옮기기
void Move_Disk(HANOI* Hanoi, int n, int m) {
	int(*Stack)[MaxDisk] = Hanoi->Stack;
	int* Top = Hanoi->Top;
	Stack[m][++Top[m]] = GET_TOP(n);
	Stack[n][Top[n]--] = 0;
}

//원판 ■로 출력
void GPrint_Hanoi(int Max, int Stack[4][MaxDisk]) {
	int i, j;
	printf("\n\n\n\n\n");
	for (i = Max; i > 0; i--) {
		for (j = 1; j <= 55; j++) {
			//축
			if (!(j % 15))
				printf("|");
			else if (Aloc - Stack[1][i] <= j && j <= Aloc + Stack[1][i]
				|| Bloc - Stack[2][i] <= j && j <= Bloc + Stack[2][i]
				|| Cloc - Stack[3][i] <= j && j <= Cloc + Stack[3][i])
				printf("■");
			else
				printf(" ");
		}
		printf("\n");
	}
}

//원판 숫자로 출력
void Print_Hanoi(int Max, int Stack[4][MaxDisk]) {
	int i, j;
	for (i = Max; i > 0; i--) {
		for (j = 1; j <= 3; j++)
			printf("%d\t\t", Stack[j][i]);
		printf("\n");
	}
}

//시간 대기를 위한 함수
void sleep(long milli) {
	clock_t end, current = clock();
	for (end = current + milli; current < end; current = clock());
}

//자동 하노이!!!
void Auto_Hanoi(HANOI* Hanoi, int N, int Start, int To, int Via) {
	if (N == 1) {
		sleep(wait_second);
		system("cls");
		GPrint_Hanoi(Hanoi->Max, Hanoi->Stack);
		Move_Disk(Hanoi, Start, To);
	}
	else {
		Auto_Hanoi(Hanoi, N - 1, Start, Via, To);
		sleep(wait_second);
		system("cls");
		GPrint_Hanoi(Hanoi->Max, Hanoi->Stack);
		Move_Disk(Hanoi, Start, To);
		Auto_Hanoi(Hanoi, N - 1, Via, To, Start);
	}
}

void Auto_Stack_Hanoi(HANOI* Hanoi) {
	int N = Hanoi->Max, STop = 0;
	int* Top = Hanoi->Top;
	char Stack[1024][2];
	const char s1[6] = { 13, 12, 21, 23, 32, 31 };
	char Node = 0;

	while (1) {
		while (N > 1) {
			Stack[STop][0] = Node;
			Stack[STop++][1] = N--;
			Node += ((Node % 2) ? -1 : 1);
		}
		sleep(wait_second);
		system("cls");
		GPrint_Hanoi(Hanoi->Max, Hanoi->Stack);
		Move_Disk(Hanoi, s1[Node] / 10, s1[Node] % 10);
		if (!STop)
			break;
		Node = Stack[--STop][0];
		N = Stack[STop][1] - 1;
		sleep(wait_second);
		system("cls");
		GPrint_Hanoi(Hanoi->Max, Hanoi->Stack);
		Move_Disk(Hanoi, s1[Node] / 10, s1[Node] % 10);
		Node += ((Node / 3) ? -3 : 3);
	}
}

int Hint_Hanoi(HANOI* Hanoi, int auto_list[]) {
	int(*Stack)[MaxDisk] = Hanoi->Stack;
	int* Top = Hanoi->Top;
	int keep[3] = { 0 };
	int i, j;
	// 움직일 판 결정
	for (i = 1; i <= 3; i++) {
		if (Top[i] > 1 && !((Stack[i][Top[i] - 1] - GET_TOP(i)) % 2)) {
			keep[1] = i;
			keep[2] = 6 - (Find_Loc(Hanoi, i) + i);
			break;
		}
		if (!auto_list[GET_TOP(i)] && GET_TOP(i)) {
			if (~(j = Find_Loc(Hanoi, i)) && keep[0] < GET_TOP(i)) {
				keep[0] = GET_TOP(i);
				keep[1] = i;
				keep[2] = j;
			}
		}
	}
	Move_Disk(Hanoi, keep[1], keep[2]);
	return keep[2];
}

inline void Set_Auto_List(int Max, int auto_list[]) {
	for (; Max > 0; Max--) {
		(auto_list[Max] > 0) ? auto_list[Max]-- : 0;
	}
}

inline int Find_Loc(HANOI* Hanoi, int loc1) {
	int(*Stack)[MaxDisk] = Hanoi->Stack;
	int* Top = Hanoi->Top;
	int i, dfrt, loc2 = -1, size = -1;
	for (i = 1; i <= 3; i++) {
		if (loc1 == i)
			continue;
		if (!GET_TOP(i) || (dfrt = GET_TOP(i) - GET_TOP(loc1)) > 0 && (dfrt & 1)) {
			if (size < GET_TOP(i)) {
				size = GET_TOP(i);
				loc2 = i;
			}
		}
	}
	return loc2;
}