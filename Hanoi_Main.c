#include "Hanoi_H.h"

void main(void) {
	while (1) {
		system("cls");
		printf("%s", "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n"
					 "□Tower of Hanoi에 오신 것을 환영 합니다!□\n"
					 "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n"
					 "시작하려면 엔터를 누르십시오(끝내기는 0)\n");
		
#ifdef USE_getch
		if (getch() == '0')
			break;
#else
		if (getchar() == '0')
			break;
#endif
		printf("\n\n\n축하합니다!\n걸린 시간: %.2lf초\a", Hanoi_Main()/1000.);
		wait_ent;
	}
}