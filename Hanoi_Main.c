#include "Hanoi_H.h"

void main(void) {
	while (1) {
		system("cls");
		printf("%s", "������������������������������������������\n"
					 "��Tower of Hanoi�� ���� ���� ȯ�� �մϴ�!��\n"
					 "������������������������������������������\n"
					 "�����Ϸ��� ���͸� �����ʽÿ�(������� 0)\n");
		
#ifdef USE_getch
		if (getch() == '0')
			break;
#else
		if (getchar() == '0')
			break;
#endif
		printf("\n\n\n�����մϴ�!\n�ɸ� �ð�: %.2lf��\a", Hanoi_Main()/1000.);
		wait_ent;
	}
}