#define _CRT_SECURE_NO_WARNINGS
#include "Hanoi_H.h"

void main(void) {
	printf("Tower of Hanoi에 오신 것을 환영 합니다\n");
	printf("시작하려면 엔터를 누르십시오"), getchar();
	Input_Disk();
	Hanoi_Main();
	printf("\n\n\n축하합니다!\a");
	getchar();
}