#include "Lurik.h"

void initialize()
	{	
		int i,j,a = 1;
		i = 0;
		while(i < 6)
			{
				j = 0;
				while( j < 6)
					{
						Dice_Pattern[i][j] = a;
						if(a == 6)
							{
								a = 1;
							}
						else
							{
								a++;
							}
						j++;
					}
				a = Dice_Pattern[i][j-1];
				i++;
			}
		
		i = 0;
		while(i < 4)
			{
				j = 0;
				while(j < 4)
					{
						home[i][j].pion = true;
						home[i][j].type = j;
 						j++;
					}
				ListPlayer[i].Info.chance = 3;
				ListPlayer[i].Info.finish = 0;
				ListPlayer[i].Info.skor = 0;
				i++;
			}
	}

int odd_even( int opt, int value)
	{
		value = value - (value/4) * 3;
		if( opt == 3)
			{
				value = value + (value+2) % 3;
			}
		else
			{
				value = value * 2;
			}
		
		return value;
	}

int shake_dice( int opt, int x, int y, int No_Player)
	{
		int i,j,stop = 0,start=32,bar,isplus,value,lama,no_pcheat,dadu;
		srand(time(NULL));
		lama=rand()%9+1;
		i = rand() % 5;
		j = 0;
		stop = 0;
		drawdice(x, y, 6);
		if(mode==6||No_Player==0){
			start=0;
			gotoxy(x-1,y+7);setcolor(16*8+0);printf("Tekan Spasi");
			gotoxy(x-1,y+8);		printf("untuk Start");
			do
				{
					start = getch();
					if(start==55){
						scanf("%d",&no_pcheat);
						keluarin_pion(no_pcheat);gotoxy(x-1,y+8);
						Node temp;
						temp=ListPlayer[no_pcheat].Pion;
						while(temp->next!=NULL)temp=temp->next;
						scanf("%d",&dadu);
						if(dadu<no_pcheat*14&&no_pcheat>0)dadu+=52;else
						if(dadu>52)dadu=dadu-no_pcheat*6+(no_pcheat*13+1)-1;
						dadu=dadu-(no_pcheat*13+1);
						moving(no_pcheat,temp,dadu);
						gotoxy(0,60);printf("%d",dadu);
					}
				}
			while(start != 32);
		}
		setcolor(16*8+0);
		bar=0;
		//if(mode==7&&No_Player!=0)while(1)printf("1");
		while(start == 32 && stop != 32 && (No_Player==0 || lama!=0))
			{
				Sleep(80);
				value = Dice_Pattern[j][i];
				if( opt > 1)
					{
						value = odd_even(opt, value);
					}
				drawdice(x, y, value);				
				gotoxy(x-1+(bar%10),y+6);setcolor(16*2);printf(" ");setcolor(8);setcolor(16*8+0);
					
				if(bar%10==9){
					gotoxy(x-1,y+6);setcolor(16*8+0);printf("          ");
				}
				if(mode==6||No_Player==0){
					gotoxy(x-1,y+7);setcolor(16*8+0);		printf("Tekan Spasi");
					gotoxy(x-1,y+8);		printf("untuk Stop ");setcolor(16*8+0);
					if (kbhit()) 
						{
							stop=getch();
							return value;
						}
				}
				setcolor(16*8+0);
				if( j == 5)
					{
						j = 0;
					}
				if(mode==7)lama--;
				bar++;
				j++;
			}
		return value;
	}

Lokasi posisi_koordinat(int posisi){
	Lokasi koor;
	if(posisi<6){
		koor.x=posisi;
		koor.y=6;
	}else
	if(posisi<12){
		koor.x=6;
		koor.y=6-(posisi-5);
	}else
	if(posisi==12){
		koor.x=7;
		koor.y=0;
	}else
	if(posisi<19){
		koor.x=8;
		koor.y=posisi-13;
	}else
	if(posisi<25){
		koor.x=9+posisi-19;
		koor.y=6;
	}else
	if(posisi==25){
		koor.x=14;
		koor.y=7;
	}else
	if(posisi<32){
		koor.x=14-(posisi-26);
		koor.y=8;
	}else
	if(posisi<38){
		koor.x=8;
		koor.y=9+posisi-32;
	}else
	if(posisi==38){
		koor.x=7;
		koor.y=14;
	}else
	if(posisi<45){
		koor.x=6;
		koor.y=14-(posisi-39);
	}else
	if(posisi<51){
		koor.x=5-(posisi-45);
		koor.y=8;
	}else
	if(posisi==51){
		koor.x=0;
		koor.y=7;
	}else
	if(posisi<58){
		koor.x=posisi+1-52;
		koor.y=7;
	}else
	if(posisi<64){
		koor.x=7;
		koor.y=1+posisi-58;
	}else
	if(posisi<70){
		koor.x=13-(posisi-64);
		koor.y=7;
	}else
	if(posisi<76){
		koor.x=7;
		koor.y=13-(posisi-70);
	}
	return koor;
}

int CekHome( int noPlayer)
	{
		int i=0;
		while(i < 4)
			{
				if(home[noPlayer][i].pion == true)
					{
						break;
					}
				else
					{
						i++;
					}
			}
		return home[noPlayer][i].type;
	}

void UserBermain( int noPlayer) {
	int pilihan,dadu = 0,i,option,type,pil,x,y,pencet,korektor=0;
	int warna,Enemy = -1;
	Node Pion = Nil;
	Lokasi Posisi;
	x=91;
	y=46;
	Node P;
	pilihan = 1;
	if(noPlayer == 0){
		warna = 9;
	}
	else if(noPlayer == 1){
		warna = 12;
	}
	else if(noPlayer == 2){
		warna = 14;
	}
	else if(noPlayer == 3){
		warna = 10;
	}
	ClearPilihan(warna);
	if (ListPlayer[noPlayer].Info.chance > 0) {
		gotoxy(91,45);setcolor(16*warna+0);printf("Kesempatan : ");
		gotoxy(91+2,46);printf("Biasa");
		gotoxy(91+2,47);printf("Genap");
		gotoxy(91+2,48);printf("Ganjil");
		pil=y;
		do{
			setcolor(16*warna+0);
			gotoxy(x,y);printf("  Biasa");
			gotoxy(x,y+1);printf("  Genap");
			gotoxy(x,y+2);printf("  Ganjil");
			gotoxy(x,pil);printf("%c",1);
			pencet=getch();
			if(pencet==13 || pencet==32){
				korektor=1;
			}
			if(pencet==80){
				pil+=1;
			}
			if(pencet==72){
				pil=pil-1;
			}
			if(pil<y){
				pil=y+2;
			}
			if(pil>y+2){
				pil=y;
			}
			
	}while(korektor!=1);
		switch(pil){
			case 46:{
				pilihan = 1;
				break;
			}
			case 47:{
				pilihan = 2;
				break;
			}
			case 48:{
				pilihan = 3;
				break;
			}
		}
		if (pilihan > 1) {
			ListPlayer[noPlayer].Info.chance--;
		}
	}
	ClearPilihan(warna);
	dadu=shake_dice(pilihan,94,47,noPlayer);
	Sleep(1000);
	
	if( dadu == 6)
		{
			if(CountNode(ListPlayer[noPlayer].Pion) == 0)
				{
					do{
						type = Print_Pion_Baru_Menu(noPlayer,2);
					}while(home[noPlayer][type].pion == false);
					InsLast(&ListPlayer[noPlayer].Pion,home[noPlayer][type].type,noPlayer*13);
					setHome(type,false,noPlayer);
					P = ListPlayer[noPlayer].Pion;
					Posisi = posisi_koordinat(P->Position);
					Pion = cekfront(noPlayer,P->Position,&Enemy);
					if(Pion != Nil)
						{
							type = DelP(&ListPlayer[Enemy].Pion,Pion->type);
							setHome(type, true, Enemy);
						}
					P->before = P->Position;
					gerak_pion(noPlayer,P->type,Posisi.x*6,Posisi.y*4);
					Print_Awal( noPlayer);
					P->Position++;
				}
			else
				{
					ClearPilihan(warna);
					gotoxy(91,45);setcolor(16*warna+0);printf("1. Tambah Pion");
					gotoxy(91,46);printf("2. Pilih Pion");
					gotoxy(91,47);printf("Pilih 1-2 : ");scanf("%d",&option);
					if( option == 1)
						{
							do{
								type = Print_Pion_Baru_Menu(noPlayer,2);	
							}while(home[noPlayer][type].pion == false);
							InsLast(&ListPlayer[noPlayer].Pion,home[noPlayer][type].type,noPlayer*13);
							setHome(type,false,noPlayer);
							P = ListPlayer[noPlayer].Pion;
							while( P->next != Nil)
								{
									P = P->next;
								}
							Posisi = posisi_koordinat(P->Position);
							P->before = P->Position;
							gerak_pion(noPlayer,P->type,Posisi.x*6,Posisi.y*4);
							Pion = cekfront(noPlayer,P->Position,&Enemy);
							if(Pion != Nil)
								{
									type = DelP(&ListPlayer[Enemy].Pion,Pion->type);
									setHome(type, true, Enemy);
								}
							Print_Awal( noPlayer);
							P->Position++;
						}
					else if(option == 2 && CountNode(ListPlayer[noPlayer].Pion) > 0)
						{
							do{
								type = Print_Pion_Baru_Menu(noPlayer,1);
								P = SearchNode(ListPlayer[noPlayer].Pion,home[noPlayer][type].type);	
							}while(P == Nil);
							
							if(active(P) == true){
								printf("aktif");
								getch();
								ClearPilihan(warna);
								gotoxy(93,45);setcolor(16*warna+0);	printf("Gunakan Skill ??");
								gotoxy(93,47);setcolor(16*warna+0);	printf("[Y/N]");
								gotoxy(91,48);option = getch();
								if(option == 121 || option == 89){
									getch();
									herodoskill(noPlayer,P,&dadu);
								}
							}
							moving(noPlayer,P,dadu);
						}
					
				}
		}
	else if(CountNode(ListPlayer[noPlayer].Pion) > 0)
		{
			do{
				type = Print_Pion_Baru_Menu(noPlayer,1);
				P = SearchNode(ListPlayer[noPlayer].Pion,type);	
			}while(P == Nil);
			if(active(P) == true){
				printf("aktif");
				getch();
				ClearPilihan(warna);
				gotoxy(93,45);setcolor(16*warna+0);	printf("Gunakan Skill ??");
				gotoxy(93,47);setcolor(16*warna+0);	printf("[Y/N]");
				gotoxy(91,48);option = getch();
				if(option == 121 || option == 89){
					herodoskill(noPlayer,P,&dadu);
				}
			}
			moving(noPlayer,P,dadu);
		}
	}
	
bool active(Node P){
	int random = (rand() % 100) + 1;
//	printf("%d %d",random,P->type);
//	getch();
	bool skillactive = false;
	int type = P->type;
	switch(type+1){
		case 1 :
			//kuda
			if(random<=20){
				skillactive = true;
			}
			break;
		case 2 :
			//banteng
			if(random<=20){
				skillactive = true;
			}
			break;
		case 3 :
			//ksatria
			if(random<=20){
				skillactive = true;
			}
			break;
		case 4 :
			//pemburu
			if(random<=50){
				skillactive = true;
			}
			break;
		case 5 :
			//pengintai
			if(random<=50){
				skillactive = true;
			}
			break;
		case 6 :
			//penyihir
			do{
				type = rand() % 7;
			}while(type!=5);
			if(active(P) == true){
				P->type = (type+1) * 10;
				skillactive = true;
			}
			break;
		case 7 :
			//patih
			if(random<=30){
				skillactive = true;
			}
			break;
	}
	return skillactive;
}

void herodoskill(int noPlayer, Node P, int *add){
	int type = P->type;
	Node Pion = ListPlayer[noPlayer].Pion;
	int pos = P->Position + 1;
	int warna;
	int belok;
	if(type>7){
		type = (type/10);
		P->type = 5;
	}
	switch(type+1){
		case 1 :
			//kuda
			*add = *add * 2;
			break;
		case 2 :
			//banteng
			switch(noPlayer+1){
				case 1 :
					belok = 52;
					break;
				case 2 :
					belok = 13;
					break;
				case 3 :
					belok = 26;
					break;
				case 4 :
					belok = 39;
					break;
			}
			if(pos != belok){
				Node Front = NULL;
				int hisnoplayer;
				while(Front == NULL && pos < 12){
					Front = cekfront(noPlayer,pos,&hisnoplayer);
					pos++;
				}
				if(Front != NULL){
					*add = pos;	
				}
			}
			break;
		case 3 :
			//ksatria
			while(Pion != NULL){
				moving(noPlayer,Pion,3);
				Pion = Pion->next;
			}
			break;
		case 4 :
			//pengintai
			switch(noPlayer+1){
				case 1 :
					belok = 52;
					break;
				case 2 :
					belok = 13;
					break;
				case 3 :
					belok = 26;
					break;
				case 4 :
					belok = 39;
					break;
			}
			if(pos != belok){
				Node Front = NULL;
				int enemy;
				do{
					enemy = noPlayer;
					Front = cekfront(noPlayer,pos,&enemy);
					pos++;
				}while(Front == NULL && pos < 4 && enemy == noPlayer);
				if(Front != NULL && enemy != noPlayer){
					int t = DelP(&ListPlayer[enemy].Pion,Front->type);
					setHome(t, true, enemy);
					Print_Awal(enemy);
				}
			}
			break;
		case 5 :
			//pemburu
			*add = *add + 2;
			break;
		case 6 :
			//penyihir
			break;
		case 7 :
			//patih
			if(noPlayer == 0){
				warna = 9;
			}
			else if(noPlayer == 1){
				warna = 12;
			}
			else if(noPlayer == 2){
				warna = 14;
			}
			else if(noPlayer == 3){
				warna = 10;
			}
			ClearPilihan(warna);
			gotoxy(91,45);setcolor(16*warna+0);printf("Nomor dadu : ");
			scanf("%d",&pos);
			*add = *add + pos;
			break;
	}
}

void setHome(int type, int state, int noPlayer)
	{
		int i;
		for(i = 0; i < 4; i++)
			{
				if( home[noPlayer][i].type == type)
					{
						home[noPlayer][i].pion 	= state;
						break;
					}
			}
	}

void moving(int noPlayer, Node P ,int dadu )
	{
	Lokasi Posisi;
	Lokasi hapus;
	Node Pion = Nil,Temp = Nil;
	int pindah, awal, akhir,Enemy = -1,type, EnemyTemp = -1;
	int i,mundur = false;
	int EnemyStep = 0;
	i = 0;
	switch(noPlayer)
		{
			case 0 :
					pindah = 51;
					awal = 51;
					akhir = 57;
				break;
			case 1:
					pindah = 12;
					awal = 57;
					akhir = 63;
				break;
			case 2:
					pindah = 25;
					awal = 63;
					akhir = 69;
				break;
			case 3:
					pindah = 38;
					awal = 69;
					akhir = 75;
				break;
		}
	while(i < dadu)
		{	
			//pengecekan jika ada pion di depannya
			
		 	hapus = posisi_koordinat(P->before);
			clear_kotak(hapus.x*6,hapus.y*4);
			if(Temp != Nil && Temp->before == P->before)
				{
					Posisi = posisi_koordinat(Temp->before);
					gerak_pion(EnemyTemp,Temp->type,Posisi.x*6,Posisi.y*4);
				}
			
			Pion = cekfront(noPlayer,P->Position,&Enemy);
			if(Pion != Nil)
				{
					Temp = Pion;
					EnemyTemp = Enemy;
				}
			
			Posisi = posisi_koordinat(P->Position);
			gerak_pion(noPlayer,P->type,Posisi.x*6,Posisi.y*4);
			
			Sleep(100);
			
		 	P->before = P->Position;
		 	
		 	if( noPlayer > 0 && P->Position == 51)
		 		{
		 			P->Position = 0;
					P->before = 51;
				}
			else
				{
		 			if(P->Position == akhir)
						{
							mundur = true;	
						}
				 	if(ListPlayer[noPlayer].Pion->Position == pindah)
					 	{
							ListPlayer[noPlayer].Pion->Position = awal;
						}
					
					if( mundur == true)
						{
							P->Position--;
						}
					else
						{
							P->Position++;
						}
				}
			i++;
		}
	
	mundur = false;
	if(Temp != Nil)
		{
			if(P->before == Temp->before)
				{
					type = DelP(&ListPlayer[Enemy].Pion,Temp->type);
					setHome(type, true, Enemy);
					Print_Awal(Enemy);
				}
		}
	if (P->before == akhir) {
		ListPlayer[noPlayer].Info.finish++;
		hapus = posisi_koordinat(P->before);
		clear_kotak(hapus.x*6,hapus.y*4);
		type = DelP(&ListPlayer[noPlayer].Pion,P->type);
	}
			
	}

int Play()
	{
		int i,j;
		if((ListPlayer[0].Info.finish < 4) && (ListPlayer[1].Info.finish < 4) && (ListPlayer[2].Info.finish < 4) && (ListPlayer[3].Info.finish < 4))
			{
				return 1;
			}
		else
			{
				return 0;
			}
	}
	
Node cekfront(int mynoplayer, int posisi, int *hisnoplayer){
	int belok,depan,posisidepan;
	switch(mynoplayer){
		case 0 :
			belok = 51;
			depan = 52;
			break;
		case 1 :
			belok = 12; 
			depan = 58;
			break;
		case 2 :
			belok = 25;
			depan = 63;
			break;
		case 3 :
			belok = 38;
			depan = 69;
			break;
	}
	posisidepan = posisi;
		if(posisi==belok){
			posisidepan = depan;
		}else
		if(posisi==51){
			posisidepan = 0;
		}else{
			posisidepan++;	
		}
	int i,j,found;
	found = false;
	i = 0;
	Node Pion;
	while( i < 4 && found == false)
		{
			
			Pion = ListPlayer[i].Pion;
			if(Pion != Nil)
				{
					while(Pion != Nil && found == false)
						{
							if( Pion->Position == posisidepan)
								{
									found = true;
								}
							else
								{
									Pion = Pion->next;
								}
						}
				}
			i++;
		}
	if(found == true)
		{
			*hisnoplayer = i-1;
			return (Pion);
		}
	else
		{
			return (Nil);
		}
}
