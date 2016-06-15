#include "Lurik.h"

void prepareplayer(int x, int y, int n){
	int warna,j,b,k;
	system("cls");
	setcolor(16*8+0);
	gotoxy(x,y);
	nplayer  = n;
	char namabot[6][20]={"Suta [BOT]","Ali [BOT]","Dyas [BOT]","Firizki [BOT]","Lulu [BOT]","Rifqi [BOT]"};
	char avainama[6]={"ffffff"};
	int i,dadu,xdadu,no;
	xdadu = 0;
	terbesar = 0;
	for(i = 0;i<nplayer;i++){
		if(i == 0){
			warna = 9;
		}
		else if(i == 1){
			warna = 12;
		}
		else if(i == 2){
			warna = 14;
		}
		else if(i == 3){
			warna = 10;
		}
		setcolor(16*warna+0);
		system("cls");
		gotoxy(x,y);
		if(i==0||mode==6)
		{
			draw_shape(72-2,0,34+2,50,1);
			for(b=73-2;b<=34+72;b++){
				for(k=1;k<=50;k++){
					gotoxy(b,k);setcolor(15*16);printf(" ");
				}
			}
			story(i);
			setcolor(16*warna+0);
			gotoxy(x,y);
			printf("Nama Pemain %d",(i+1));
		}
		else
			{
				printf("Nama BOT %d",(i+1));
			}
		draw_shape(x,y+1,30,1,2);
		gotoxy(x+1,y+2);
		if(mode==6||i==0){
			scanf("%s",&ListPlayer[i].Info.nama);
		dadu = 1;
		dadu = shake_dice(1,x+1,y+5,i);
		if(xdadu<dadu){
			xdadu = dadu;
			terbesar = i;
		}
		for(j = 0;j<4;j++)
			{
				setcolor(16*warna+0);
				gotoxy(x+15,y+4);
				printf("Pilih Pion %d : ",(j+1));
				home[i][j].type = pilih_pion(i);
				Sleep(150);
				pionmu(i);
			}
		Sleep(1000);
		}else{
			srand(time(NULL));
			no=rand()%6;
			while(avainama[no]=='t'){
				srand(time(NULL));
				no=rand()%6;
			}
			strcpy(ListPlayer[i].Info.nama,namabot[no]);
			avainama[no]='t';
			printf("%s",ListPlayer[i].Info.nama);
			for(j = 0;j<4;j++)
			{
				setcolor(16*warna+0);
				gotoxy(x+15,y+4);
				home[i][j].type = home[0][j].type;
				pionmu(i);
			}
		}
	}
}

void swapvalue(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void savehighscore(char nama[], int skor){
	int found = 0;
	FILE *ifp,*ofp;
	
	ifp = fopen("highscore.txt", "r");
	
	if (ifp == NULL) {
  		fprintf(stderr, "Database highscore tidak ditemukan!\n");
  		exit(1);
	}else{
		found = 1;
	}
	
	if(found == 1){
		int i = 0;
		int jml = 0;
		fscanf(ifp, "%d", &jml);
		PlayerInfo ListPlayer[jml+1];
		PlayerInfo mPlayerInfo;
		while (fscanf(ifp, "%s %d", &mPlayerInfo.nama,&mPlayerInfo.skor) != EOF) {
			ListPlayer[i].skor = mPlayerInfo.skor;
			strcpy(ListPlayer[i].nama,mPlayerInfo.nama);
			i++;
		}
		ListPlayer[jml].skor = skor;
		strcpy(ListPlayer[jml].nama,nama);
		fclose(ifp);
		getch();
		ofp = fopen("highscore.txt", "w");
		fprintf(ofp,"%d ",(jml+1));
		for(i = 0; i < jml+1; i++){
			fprintf(ofp,"%s %d ",ListPlayer[i].nama,ListPlayer[i].skor);
		}	
		fclose(ofp);
	}
}

void showhighscore(){
	int x,y,n,jml;
	system("cls");
	x = 1;
	y = 1;
	n = 0;
	int found = 0;
	FILE *ifp,*ofp;
	
	ifp = fopen("highscore.txt", "r");
	
	if (ifp == NULL) {
  		fprintf(stderr, "Database highscore tidak ditemukan!\n");
  		exit(1);
	}else{
		found = 1;
	}
	
	if(found==1){
		PlayerInfo mPlayerInfo;
		fscanf(ifp, "%d", &jml);
		PlayerInfo ListPlayer[jml];
		while (fscanf(ifp, "%s %d", &mPlayerInfo.nama,&mPlayerInfo.skor) != EOF) {
			ListPlayer[n].skor = mPlayerInfo.skor;
			strcpy(ListPlayer[n].nama,mPlayerInfo.nama);
			n++;
		}
		int i,j,k;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(ListPlayer[i].skor>ListPlayer[j].skor){
					swapvalue(&ListPlayer[i].skor,&ListPlayer[j].skor);
					char temp[60];
					strcpy(temp,ListPlayer[i].nama);
					strcpy(ListPlayer[i].nama,ListPlayer[j].nama);
					strcpy(ListPlayer[j].nama,temp);
				}
			}
		}
		fclose(ifp);
		ofp = fopen("highscore.txt", "w");
		fprintf(ofp,"%d ",jml);
		for(n = 0; n < jml; n++){
			fprintf(ofp,"%s %d ",ListPlayer[n].nama,ListPlayer[n].skor);
			gotoxy(x+2,y+n+7);
			printf("%d.\t\t%s",(n+1),ListPlayer[n].nama);
			gotoxy(x+55,y+n+7);
			printf("%d",ListPlayer[n].skor);	
		}	
		fclose(ofp);
	}
	
	if(n==0){
		n++;
		gotoxy(x+1,y+6);
		printf("Belum ada Highscore, mainkan yuk! :)");
	}
	draw_shape(x,y+5,70,n+2,2);
	draw_shape(x,y,70,3,1);
	gotoxy(3,3);
	printf("Peringkat\tNama\t\t\t\t\tSkor");
	system("PAUSE");
}

void cek_win()
		{
			int i;
			for(i = 0; i < 4;i++)
			{
				if(ListPlayer[i].Info.finish == 4)
					{
						savehighscore(ListPlayer[i].Info.nama,ListPlayer[i].Info.skor);
					}
			}
		}
