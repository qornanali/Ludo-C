#include "Lurik.h"

int main() {
	srand(time(NULL));
	int count = 0,type = 0,temp;
	int i;
	system("MODE CON: COLS=108 LINE=62");
	system("cls");
	intro();
	initialize();
	menu();
	menu_permainan();
	count = terbesar;
	//printf("%d ",terbesar);
	while(Play() == 1)
		{	//gotoxy(0,60);printf("chance p1: %d",ListPlayer[count%4].Info.chance);
			//gotoxy(0,60);printf("%",);
			if(mode==6){
				UserBermain(count%4);
				ListPlayer[count%4].Info.skor++;
			}else{
				if(count%4==0){
					UserBermain(count%4);
					ListPlayer[count%4].Info.skor++;
				}
				else{
					comp_turn(count%4);
					ListPlayer[count%4].Info.skor++;
				}
			}
			count++;
		}
	cek_win();
	printf("aksfbakjsfbjhakshfahvjf");
	return 0;
}
