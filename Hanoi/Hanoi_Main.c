#define _CRT_SECURE_NO_WARNINGS
#include "Hanoi_H.h"

void main(void) {
	printf("Tower of Hanoi�� ���� ���� ȯ�� �մϴ�\n");
	printf("�����Ϸ��� ���͸� �����ʽÿ�"), getchar();
	Input_Disk();
	Hanoi_Main();
	printf("\n\n\n�����մϴ�!\a");
	getchar();
}