#ifndef HANOI_H
#define HANOI_H

#include <stdio.h>
#include <Windows.h>
#include <time.h>

//������� ���� ��ǥ ����
//����!!!!! ���� �� ��ǥ�� �����(15)�� �̿��ϰ� �Ǿ�����! �˻�(��)
#define Aloc 15
#define Bloc 30
#define Cloc 45 

//�ִ� ���� ���� ����!!!!! 1�� �� ũ�� �ؾ���! 
#define MaxDisk 11 //���� 10���� ����!!!
//�ּ� ���� ����
#define MIN_DISK 1

//�ڵ� �ϳ��� ��� �и� ������
#define wait_second 500

//#define print_mecro sleep(wait_second); \
//system("cls"); \
//GPrint_Hanoi(Max, Stack); \
//Move_Disk(Stack, Top, Start, To); 

//UI�� ���� ����!  �׷����� ����!
typedef enum { UI_NUM, UI_GRP }UI;

typedef struct _HANOI {
	int Max;
	int Stack[4][MaxDisk];
	int Top[4];
} HANOI;

//���� ���� �Է¹ޱ�
void Input_Disk(HANOI* Hanoi);
// ���� ����
static void Set_Disk(HANOI* Hanoi);
//���� �ϳ���
clock_t Hanoi_Main();
//���� �ű��
void Move_Disk(HANOI* Hanoi, int n, int m);
//���� ��� ���
void GPrint_Hanoi(int Max, int Stack[4][MaxDisk]);
//���� ���ڷ� ���
void Print_Hanoi(int Max, int Stack[4][MaxDisk]);
//�ð� ��⸦ ���� �Լ�
void sleep(long milli);
//�ڵ� �ϳ���!!! ���� �Ű������� 5��!!!
void Auto_Hanoi(HANOI* Hanoi, int N, int Start, int To, int Via);

void Auto_Stack_Hanoi(HANOI* Hanoi);

#endif //HANOI_H
