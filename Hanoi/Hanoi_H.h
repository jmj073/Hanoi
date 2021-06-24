#ifndef HANOI_H
#define HANOI_H

#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <Windows.h>

//테스트 함수들을 위한 조건부 컴파일
#define TEST

extern int Max;
extern int Stack[4][21];
extern int Top[4];

//원판 개수 입력받기
void Input_Disk();
// 원판 세팅
static void Set_Disk();
//메인 하노이
void Hanoi_Main();
//원판 옮기기
void Move_Disk(int n, int m);

//테스트 함수들을 위한 조건부 컴파일
#ifdef TEST

void Print_Hanoi();

#endif //TEST


#endif //HANOI_H
