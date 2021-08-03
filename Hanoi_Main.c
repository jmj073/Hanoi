#include "Hanoi_H.h"

void main(void) {
	//n은 범용 입력
	int n;
	clock_t time_score;
	while (1) {
		system("cls");
		printf("■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n");
		printf("□Tower of Hanoi에 오신 것을 환영 합니다!□\n");
		printf("■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n");
		printf("시작하려면 엔터를 누르십시오(끝내기는 0)\n");
		
		n = getchar();
		if (n == '0')
			break;
		else if (n != '\n')
			continue;
		time_score = Hanoi_Main();
		printf("\n\n\n축하합니다!\n걸린 시간: %.2lf초\a", time_score/1000.);
		getchar();
	}
}