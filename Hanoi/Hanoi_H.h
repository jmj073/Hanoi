#ifndef HANOI_H
#define HANOI_H

#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <Windows.h>

//�׽�Ʈ �Լ����� ���� ���Ǻ� ������
#define TEST

extern int Max;
extern int Stack[4][21];
extern int Top[4];

//���� ���� �Է¹ޱ�
void Input_Disk();
// ���� ����
static void Set_Disk();
//���� �ϳ���
void Hanoi_Main();
//���� �ű��
void Move_Disk(int n, int m);

//�׽�Ʈ �Լ����� ���� ���Ǻ� ������
#ifdef TEST

void Print_Hanoi();

#endif //TEST


#endif //HANOI_H
