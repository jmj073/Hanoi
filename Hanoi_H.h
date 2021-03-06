#ifndef HANOI_H
#define HANOI_H

#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define GET_TOP(i) Stack[i][Top[i]]

// getch 사용 여부
#define USE_getch

//힌트 옵션 사용 여부
#define USE_HINT

//■출력을 위한 좌표 설정
//주의!!!!! 축은 세 좌표의 공약수(15)를 이용하게 되어있음! 검색(축)
#define Aloc 15
#define Bloc 30
#define Cloc 45 

//최대 원판 개수 주의!!!!! 1개 더 크개 해야함! 
#define MaxDisk 11 //지금 10개인 거임!!!
//최소 원판 개수
#define MIN_DISK 1

//자동 하노이 대기 밀리 세컨드
#define wait_second 500

// 대기를 위한 매크로
#define wait_ent while(getchar() != '\n')

//UI를 위한 선택!  그래픽의 약자!
typedef enum { UI_NUM, UI_GRP }UI;

typedef struct _HANOI {
	int Max;
	int Stack[4][MaxDisk];
	int Top[4];
} HANOI;

//원판 개수 입력받기
void Input_Disk(HANOI* Hanoi);
// 원판 세팅
static void Set_Disk(HANOI* Hanoi);
//메인 하노이
clock_t Hanoi_Main();
//원판 옮기기
void Move_Disk(HANOI* Hanoi, int n, int m);
//원판 ■로 출력
void GPrint_Hanoi(int Max, int Stack[4][MaxDisk]);
//원판 숫자로 출력
void Print_Hanoi(int Max, int Stack[4][MaxDisk]);
//시간 대기를 위한 함수
void sleep(long milli);
//자동 하노이!!! 무려 매개변수가 5개!!!
void Auto_Hanoi(HANOI* Hanoi, int N, int Start, int To, int Via);

void Auto_Stack_Hanoi(HANOI* Hanoi);

int Hint_Hanoi(HANOI* Hanoi, int auto_list[]);

inline void Set_Auto_List(int Max, int auto_list[]);

inline int Find_Loc(HANOI* Hanoi, int loc1);

#endif //HANOI_H
