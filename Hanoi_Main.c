#include "Hanoi_H.h"

void main(void) {
	//n�� ���� �Է�
	int n;
	clock_t time_score;
	while (1) {
		system("cls");
		printf("������������������������������������������\n");
		printf("��Tower of Hanoi�� ���� ���� ȯ�� �մϴ�!��\n");
		printf("������������������������������������������\n");
		printf("�����Ϸ��� ���͸� �����ʽÿ�(������� 0)\n");
		
		n = getchar();
		if (n == '0')
			break;
		else if (n != '\n')
			continue;
		time_score = Hanoi_Main();
		printf("\n\n\n�����մϴ�!\n�ɸ� �ð�: %.2lf��\a", time_score/1000.);
		getchar();
	}
}