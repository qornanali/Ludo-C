#include "Lurik.h"

int main() {
	int count = 0,type = 0,temp;
	int i;
	system("MODE CON: COLS=108 LINE=62");
	system("cls");
	intro();
	initialize();
	menu();
	menu_permainan();
	count = terbesar;
	printf("%d ",terbesar);
	while(Play() == 1)
		{
			UserBermain(count%4);
			ListPlayer[count%4].Info.skor++;
			count++;
		}
	cek_win();
	printf("aksfbakjsfbjhakshfahvjf");
	return 0;
}
