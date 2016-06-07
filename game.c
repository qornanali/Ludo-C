#include "Lurik.h"

boolean active(Node P){
	int random = (rand() % 100) + 1;
	boolean skillactive = false;
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
			if(active(type)){
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

void herodoskill(int noPlayer, Node P, int * add){
	int type = P->type;
	Node Pion = ListPlayer[noPlayer].Pion;
	int pos = P->Position + 1;
	if(type>7){
		type = (type/10);	
		P->type = 5;
	}
	switch(type){
		case 1 :
			//kuda
			*add = *add * 2;
			break;
		case 2 :
			//banteng
			break;
		case 3 :
			//ksatria
			while(Pion != NULL){
				moving(noPlayer,P,3);
				Pion = Pion->next;
			}
			break;
		case 4 :
			//pengintai
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
			pos = 6;
			*add = *add + pos;
			break;
	}
}

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
						home[i][j] = true;
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
		int i,j,stop = 0,start,bar,isplus,value,lama,no_pcheat,dadu;
		srand(time(NULL));
		lama=rand()%9+1;
		i = rand() % 5;
		j = 0;
		stop = 0;
		drawdice(x, y, 6);
		if(mode==6||No_Player==0){
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
					}else
					if(start==56){
						scanf("%d",&dadu);
						return(dadu);
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
				if(home[noPlayer][i] == true)
					{
						break;
					}
				else
					{
						i++;
					}
			}
		return i;
	}

void UserBermain( int noPlayer) {
	int pilihan,dadu = 0,i,option,type,pil,x,y,pencet,korektor=0;
	int warna;
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
	ClearPilihan(90,44,18,16,warna);
	if (ListPlayer[noPlayer].Info.chance > 0) {
		menukesempatan(91,45,warna);
		pil=y;
		do{
			menukesempatan(91,45,warna);
			gotoxy(91,pil);printf("%c",1);
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
	ClearPilihan(90,44,18,16,warna);
	dadu=shake_dice(pilihan,94,47,noPlayer);
	Sleep(1000);
	if( dadu == 6)
		{				
			if(CountNode(ListPlayer[noPlayer].Pion) == 0)
				{
					type = CekHome(noPlayer);
					InsLast(&ListPlayer[noPlayer].Pion,type,noPlayer*13);
					home[noPlayer][type] = false;
					P = ListPlayer[noPlayer].Pion;
				}
			else
				{
					menupion(91,45,warna);
					scanf("%d",&option);
					if( option == 1)
						{
							type = CekHome(noPlayer);	
							InsLast(&ListPlayer[noPlayer].Pion,type,noPlayer*13);
							home[noPlayer][type] = false;
							P = ListPlayer[noPlayer].Pion;
							while( P->next != Nil)
								{
									P = P->next;
								}						
						}
					else if(option == 2 && CountNode(ListPlayer[noPlayer].Pion) > 0)
						{
							type = Print_Pion_Menu(noPlayer);
							P = SearchNode(ListPlayer[noPlayer].Pion,type);
						}
					if(active(P->type)){
						menuskill(91,45,warna);
						scanf("%d",&option);
						if(option==1){
							herodoskill(noPlayer,P,&dadu);
						}
					}		
				}
			if(P != Nil)
				{
					Print_Awal(noPlayer);
					moving(noPlayer,P,dadu);
				}
		}
	else if(CountNode(ListPlayer[noPlayer].Pion) > 0)
		{
			P = ListPlayer[noPlayer].Pion;
			if(CountNode(ListPlayer[noPlayer].Pion) > 1)
				{
					type = Print_Pion_Menu(noPlayer);
					P = SearchNode(ListPlayer[noPlayer].Pion,type);
				}
			Print_Awal(noPlayer);
			if(active(P->type)){
				menuskill(91,45,warna);
				scanf("%d",&option);
				if(option==1){
					herodoskill(noPlayer,P,&dadu);
				}
			}
			moving(noPlayer,P,dadu);
		}
	}

void moving(int noPlayer, Node P ,int dadu )
	{
	Lokasi Posisi;
	Lokasi hapus;
	Node Pion = Nil,Temp = Nil;
	int pindah, awal, akhir,Enemy = -1,type;
	int i,mundur = false;
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
			
			Pion = cekfront(noPlayer,P->Position,&Enemy);
				
			if( Pion != Nil)
				{
					Temp = Pion;
					hapus = posisi_koordinat(P->before);
					clear_kotak(hapus.x*6,hapus.y*4);
				}
			else
				{
					if(Temp != Nil)
						{
							Posisi = posisi_koordinat(Temp->before);
							gerak_pion(Enemy,Temp->type,Posisi.x*6,Posisi.y*4);
							Temp = Nil;
						}
					else
						{
							hapus = posisi_koordinat(P->before);
							clear_kotak(hapus.x*6,hapus.y*4);
						}
				}
			Posisi = posisi_koordinat(P->Position);
			gerak_pion(noPlayer,P->type,Posisi.x*6,Posisi.y*4);
			Sleep(100);
			if(noPlayer > 0 && P->Position == 51)
				{
					P->Position = 0;
					P->before = 51;
				}
			else
				{
					if(P->Position == akhir) {
							mundur = true;	
				 	}
				 	P->before = P->Position;
				 	if(ListPlayer[noPlayer].Pion->Position == pindah) {
						
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
		if(Temp != Nil)
			{
				if(P->Position == Temp->Position)
					{
						type = DelP(&ListPlayer[noPlayer].Pion,Temp->type);
						home[Enemy][type] = true;
						Print_Awal(Enemy);
					}
			}
		mundur = false;
		if (P->Position == akhir) {
			ListPlayer[noPlayer].Info.finish++;
			type = DelP(&ListPlayer[noPlayer].Pion,P->type);
			home[Enemy][type] = true;
			Print_Awal(noPlayer);
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
