#define _CRT_SECURE_NO_WARNINGS
#include "Hanoi_H.h"

int Max;
int Stack[4][21];
int Top[4];

//���� ���� �Է¹ޱ�
void Input_Disk() {
	int n;
	while (1) {
		printf("��� ������ ����Ͻðڽ��ϱ�? (3~20)\n�Է�:");
		scanf("%d", &n), getchar();
		if (3 <= n && n <= 20)
			break;
		printf("�߸��� ���� �Է��ϼ̽��ϴ�(%d)", n);
		getchar();
		system("cls");
	}
	Max = n;
	Set_Disk();
}

// ���� ����
static void Set_Disk() {
	int i;
	for (i = Max; i > 0; i--)
		Stack[1][++Top[1]] = i;
}

//���� �ϳ���
void Hanoi_Main() {
	int n, m=1, cnt=0;
	while (1) {
		system("cls");
		Print_Hanoi();
		printf("\n\n�ű� Ƚ��:%d\n", cnt);
		printf("�ű� ������ ��ġ�� ������ ���� ��ġ�� �Է��ϼ��� ex)1 2\n�Է�:");
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
			printf("�߸��� ���� �Է��ϼ̽��ϴ�");
			getchar();
			continue;
		}
	}
}

//���� �ű��
void Move_Disk(int n, int m) {
	Stack[m][++Top[m]] = Stack[n][Top[n]];
	Stack[n][Top[n]--] = 0;
}

//�׽�Ʈ �Լ����� ���� ���Ǻ� ������
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