#include "Lurik.h"


void gotoxy(int x, int y) //modul untuk memfungsikan fungsi gotoxy
{
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

void draw_shape(int x,int y,int v, int h, int type){
	gotoxy(x,y);
	int garis[6];
	if(type==1){
		garis[0] = duasikukiriatas;
		garis[1] = duasikukananatas;
		garis[2] = duasikukananbawah;
		garis[3] = duasikukiribawah;
		garis[4] = duahor;
		garis[5] = duaver;
	}else{
		garis[0] = sikukiriatas;
		garis[1] = sikukananatas;
		garis[2] = sikukananbawah;
		garis[3] = sikukiribawah;
		garis[4] = hor;
		garis[5] = ver;
	}
	printf("%c",garis[0]);
	int i;
	for(i=0;i<v;i++){
		x++;
		gotoxy(x,y);
		printf("%c",garis[4]);
	} 
	x++;
	printf("%c",garis[1]);
	for(i=0;i<h;i++){
		y++;
		gotoxy(x,y);
		printf("%c",garis[5]);
	} 
	y++;
	gotoxy(x,y);
	printf("%c",garis[2]);
	for(i=0;i<v;i++){
		x--;
		gotoxy(x,y);
		printf("%c",garis[4]);
	} 
	x--;
	gotoxy(x,y);
	printf("%c",garis[3]);
	for(i=0;i<h;i++){
		y--;
		gotoxy(x,y);
		printf("%c",garis[5]);
	}
}	
void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void intro()
	{
		int x, y;
		y=10;
		while(y<=49){
			x=35;
			while(x<=72){
				if(y<=19){
				
					if((y<=14)||((y>=15 && y<=61)&&((x>=(35+30-(y-14)))&&(x<=(35+30-(y-14)+9))))){
						gotoxy(x,y);setcolor(4*16);printf(" ");setcolor(16*0+8);
					}
					else{
						gotoxy(x,y);setcolor(12*16);printf(" ");setcolor(16*0+8);
					}
				}
				else if(y>=20 && y<=29){
					if((x>=(35+30-(y-14)))&&(x<=(35+30-(y-14)+9))){
						gotoxy(x,y);setcolor(6*16);printf(" ");setcolor(16*0+8);
					}
					else{
						gotoxy(x,y);setcolor(14*16);printf(" ");setcolor(16*0+8);
					}
				}
				else if(y>=30 && y<=39){
					if((x>=(35+30-(y-14)))&&(x<=(35+30-(y-14)+9))){
						gotoxy(x,y);setcolor(2*16);printf(" ");setcolor(16*0+8);
					}
					else{
						gotoxy(x,y);setcolor(10*16);printf(" ");setcolor(16*0+8);
					}
				}
				else if(y>=40 && y<=49){
					if(((x>=(35+30-(y-14)))&&(x<=(35+30-(y-14)+9)))||((y>=41 && y<=46)&&((x>=57 && x<=58)||(x>=63 && x<=64)))||(y==43 && (x>=55 && x<=60))||(y==44 && (x>=65 && x<=67))||(y==45 && x==65)||((y>=45 && y<=47)&&(x>=67 && x<=68))||(y==47 && ((x>=58 && x<=61)||(x>=63 && x<=64)))||(y==46 && (x>=60 && x<=61))){
						gotoxy(x,y);setcolor(3*16);printf(" ");setcolor(16*0+8);
					}
					else{
						gotoxy(x,y);setcolor(11*16);printf(" ");setcolor(16*0+8);
					}
				}
				x++;
			}
			y++;
		}
		getch();
	}

void menu() //modul menu
{
	
	int x, y, pil=y+4,cek1=26,cek2=27,pencet,korektor=0,xi,yi,i;
	system("cls");
	y=0;
			while(y<=60){
				x=0;
				while(x<=108){
					if(!((x>=27-2-5 && x<=27-1+66-5)&&(y>=37-1 && y<=37-1+14))){
					
						if((x-y)%5==0){
							gotoxy(x,y);setcolor(9*16);printf(" ");setcolor(16*0+8);
						}
						else if((x-y-1)%5==0){
							gotoxy(x,y);setcolor(10*16);printf(" ");setcolor(16*0+8);
						}
						else if((x-y-2)%5==0){
							gotoxy(x,y);setcolor(14*16);printf(" ");setcolor(16*0+8);
						}
						else if((x-y-3)%5==0){
							gotoxy(x,y);setcolor(12*16);printf(" ");setcolor(16*0+8);
						}
						else{
							gotoxy(x,y);setcolor(0*16);printf(" ");setcolor(16*0+8);
						}
					}
					x++;
				}
				
				y++;
			}
	
	x=31;
	while(x<=75){
		y=6;
		while(y<=20){
			if(((y>=9 && y<=17)&&((x>=33 && x<=34)||(x>=44 && x<=45)||(x>=50 && x<=51)||(x>=55 && x<=56)||(x>=61 && x<=62)||(x>=66 && x<=67)||(x>=72 && x<=73)))||((y==18 && ((x>=33 && x<=40)||(x>=45 && x<=50)||(x>=55 && x<=61)||(x>=67 && x<=72))))||((y==8 && ((x>=33 && x<=34)||(x>=44 && x<=45)||(x>=50 && x<=51)||(x>=55 && x<=61)||(x>=67 && x<=72))))||(y==17 && ((x==46)||(x==49)||(x==60)||(x==68)||(x==71)))||(y==9 &&((x==60)||(x==68)||(x==71)))){
				if(x>=33 && x<=40){
					gotoxy(x,y);setcolor(1);printf(" ");setcolor(16*0+8);
				}
				else if(x>=44 && x<=51){
					gotoxy(x,y);setcolor(2);printf(" ");setcolor(16*0+8);
				}
				else if(x>=55 && x<=62){
					gotoxy(x,y);setcolor(4);printf(" ");setcolor(16*0+8);
				}
				else if(x>=66 && x<=73){
					gotoxy(x,y);setcolor(6);printf(" ");setcolor(16*0+8);
				}
				
			}
			else if(((y>=8 && y<=17)&&((x==32)||(x==35)))||(y==7 && (x>=33 && x<=34))||(y==17 && (x>=36 && x<=40))||(y==18 && (x==32 || x==41))||(y==19 && (x>=33 && x<=40))){
				gotoxy(x,y);setcolor(9);printf("0");setcolor(16*0+8);
			}
			else if(((y>=8 && y<=16)&&(x==43 || x==46 || x==49 || x==52))||(y==7 && ((x>=44 && x<=45)||(x>=50 && x<=51)))||(y==17 && ((x==43 || x==52)||(x>=47 && x<=48)))||(y==18 && (x==44 || x==51))||(y==19 && (x>=45 && x<=50))){
				gotoxy(x,y);setcolor(10);printf("0");setcolor(16*0+8);
			}
			else if(((y>=10 && y<=16)&&(x==54 || x==57 || x==60 || x==63))||((y==7 || y==19) && (x>=55 && x<61))||((y==8 || y==18)&&(x==54 || x==62))||(((x==54 || x==63)||(x>=57 && x<=59))&&(y==17 || y==9))){
				gotoxy(x,y);setcolor(12);printf("0");setcolor(16*0+8);
			}
			else if(((y>=10 && y<=16)&&(x==65 || x==68 || x==71 || x==74))||((y==9 || y==17)&&((x==65 || x==74)||(x>=69 && x<=70)))||((y==8 || y==18)&&(x==66 || x==73))||((y==7 || y==19)&&(x>=67 && x<=72))){
				gotoxy(x,y);setcolor(14);printf("0");setcolor(16*0+8);
			}
			else{
				gotoxy(x,y);setcolor(0);printf(" ");setcolor(16*0+8);
			}
			y++;
		}
		x++;
	}
	int color, chars;
	color=rand()%4;
	if(color==2){
		color = 3;
	}
	chars=rand()%7;
	intro_pion(color,chars,72,14);
	x=27;
	y=37;
	pil=y+4;	
	do{
		draw_shape(x-2-5,y-1,66,14,2);
		gotoxy(x-4,y); 	printf("\t\t\t         MENU\t\t\t            ");
		gotoxy(x-4,y+4); 	printf("\t\t\t         PLAY\t\t\t            ");
		gotoxy(x-4,y+6); 	printf("\t\t\t         HELP\t\t\t            ");
		gotoxy(x-4,y+8); 	printf("\t\t\t       HIGHSCORE\t\t            ");
		gotoxy(x-4,y+10); printf("\t\t\t         ABOUT\t\t\t            ");
		gotoxy(x-4,y+12); printf("\t\t\t         EXIT\t\t\t            ");
		if(pil == y+4){
			gotoxy(x-4,pil); setcolor(16*12+0);printf("\t\t\t         PLAY\t\t\t            ");setcolor(8);
		}
		else if(pil == y+6){
			gotoxy(x-4,pil); setcolor(16*14+0);printf("\t\t\t         HELP\t\t\t            ");setcolor(8);
		}
		else if(pil == y+8){
			gotoxy(x-4,pil); setcolor(16*10+0);printf("\t\t\t       HIGHSCORE\t\t            ");setcolor(8);
		}
		else if(pil == y+10){
			gotoxy(x-4,pil); setcolor(16*9+0);printf("\t\t\t         ABOUT\t\t\t            ");setcolor(8);
		}
		else if (pil == y+12){
			gotoxy(x-4,pil); setcolor(16*13+0);printf("\t\t\t         EXIT\t\t\t            ");setcolor(8);
		}
		pencet=getch();
		if(pencet==13 || pencet==32){
			korektor=1;
		}
		if(pencet==80){
			pil+=2;
		}
		if(pencet==72){
			pil=pil-2;
		}
		if(pil<y+3){
			pil=y+12;
		}
		if(pil>y+13){
			pil=y+4;
		}
		
	}while(korektor!=1);
	
	switch(pil){
		case 51-10:
			mode=gamemode();
//			prepareplayer(3,4,4);
			papan();
			for(i = 0;i < 4;i++)
				{
					Print_Awal(i);
				}
		break;
		case 53-10:
			helpabout(0);
			menu();
		break;
		case 55-10:
			showhighscore();
			menu();
		break;
		case 57-10:
			helpabout(2);
			menu();
		break;	
		case 59-10:
			//exit
		break;
	}
	
}
void papan()
{
	system("cls");

	int b=0,k,bt,kt;
			while(b<=59)
			{
				k=0;
				while(k<=89)
				{
					if((/*kandang biru*/(b<=3 || (b>7 && b<=11) || (b>11 && b<=15) || (b>19 && b<=23)) && k<=35) || (((b>3 && b<=7) || (b>15 && b<=19))&&(k<=5 || (k>11 && k<=23) || k>29 && k<=35))||/*start biru*/((b>=24 && b<=27)&&(k<=5))||/*lurusan biru*/((b>=28 && b<=31)&&(k>=6 && k<=35))||/*finish biru*/((b>=24 && b<=35)&&k==37)||((b>=25 && b<=34)&&k==38)||((b>=26 && b<=33)&&k==39)||((b>=27 && b<=32)&& k==40)||((b>=28 && b<=31)&&k==41)||((b>=24 && b<=35)&& k==36))
					{
						
						/*Pembatas Biru*/
						if(/*start biru*/((k<=5)&&(b==24 || b==27))||/*lurusan biru*/((b==28 || b==31)&&(k>=6 && k<=35))) 
						{
							
							/*Sudut Kiri*/
							if(k==0 || k==6 || k==12 || k==18 || k==24 || k==30)
							{
								
								/*atas*/
								if(b==24 || b==28)
								{
									setcolor(16*9 + 0);printf("%c",218);setcolor(153);
								}
								
								/*bawah*/
								else if(b==27 || b==31)
								{
									setcolor(16*9 + 0);printf("%c",192);setcolor(153);
								}
							}
							
							/*Sudut Kanan*/
							else if(k==5 || k==11 || k==17 || k==23 || k==29 || k==35)
							{
								
								/*atas*/
								if(b==24 || b==28)
								{
									setcolor(16*9 + 0);printf("%c",191);setcolor(153);
								}
								
								/*bawah*/
								else if(b==27 || b==31)
								{
									setcolor(16*9 + 0);printf("%c",217);setcolor(153);
								}
							}
							
							/*batas atas bawah*/
							else
							{
								setcolor(16*9 + 0);printf("%c",196);setcolor(153);
							}
						}
						
						/*batas kiri kanan*/
						else if(((b==29 || b==30)&&(k==6 || k==12 || k==18 || k==24 || k==30 || k==11 || k==17 || k==23 || k==29 || k==35))||((b==25 || b==26)&&(k==0 || k==5)))
						{
							setcolor(16*9 + 0);printf("%c",179);setcolor(153);
						}
						//Logo "Spade"
						else if((b==6 && (k==17 || k==18))||(b==7 && ((k>=16)&&(k<=19)))||(b==8 &&((k>=14)&&(k<=21)))||((b==9 || b==14) && ((k>=13)&&(k<=22)))||(((b>=10)&&(b<=13))&&((k>=12)&&(k<=23)))||((b==15)&&(((k>=14)&&(k<=15))||((k>=20)&&(k<=21))||((k>=17)&&(k<=18))))||((b==16)&&((k==17)||(k==18)))||((b==17)&&((k>=16)&&(k<=19)))||((b==18)&&((k>=15)&&(k<=20)))){
							setcolor(16*1 + 1);printf("%c",179);setcolor(153);
						}
						/*mewarnai*/
						else
						{
							setcolor(153);printf(" ");setcolor(8);	
						}
						
					}
					else if(/*kandang merah*/((k>=54 && k<=89)&&((b<=3)||(b>=8 && b<=15)||(b>=20 && b<=23)))||(((k>=54 && k<=59)||(k>=66 && k<=77)||(k>=84 && k<=89))&&((b>=4 && b<=7)||(b>=16 && b<=19)))||/*start merah*/((b<=3) && (k>=48 && k<=53))||/*lurusan merah*/((b>=4 && b<=23)&&(k>=42 && k<=47))||/*finish merah*/((k>=38 && k<=51)&& b==24)||((k>=39 && k<=50)&& b==25)||((k>=40 && k<=49)&& b==26)||((k>=41 && k<=48)&& b==27)||((k>=42 && k<=47)&& b==28)||((k>=42 && k<=47)&& b==29))
					{
						if((b<=3 && (k==48 || k==53))||((b>=4 && b<=23)&&(k==42 || k==47)))
						{
							
							/*atas*/
							if(b==0 || b==4 || b==8 || b==12 || b==16 || b==20)
							{
								
								/*kiri*/
								if(k==48 || k==42)
								{
									setcolor(16*12 + 0);printf("%c",218);setcolor(8);
								}
								
								/*kanan*/
								else if(k==53 || k==47)
								{
									setcolor(16*12 + 0);printf("%c",191);setcolor(8);
								}
							}
							
							/*bawah*/
							else if(b==3 || b==7 || b==11 || b==15 || b==19 || b==23)
							{
								
								/*kiri*/
								if(k==48 || k==42)
								{
									setcolor(16*12 + 0);printf("%c",192);setcolor(8);
								}
								
								/*kanan*/
								else if(k==53 || k==47)
								{
									setcolor(16*12 + 0);printf("%c",217);setcolor(8);
								}
							}
							
							/*batas kanan & kiri*/
							else
							{
								setcolor(16*12 + 0);printf("%c",179);setcolor(8);	
							}
							
						}
						
						/*batas atas & bawah*/
						else if(((b==7 || b==11 || b==15 || b==19 || b==23 || b==4 || b==8 || b==12 || b==16 || b==20)&&(k>42 && k<47))||((b==0 || b==3)&&(k>48 && k<53)))
						{
							setcolor(16*12 + 0);printf("%c",196);setcolor(8);
						}
						//Logo "Heart"
						else if((b==6 && ((k>=68 && k<=69)||(k>=74 && k<=75)))||((b==7 && ((k>=67 && k<=70)||(k>=73 && k<=76))))||((b>=8 && b<=13)&&(k>=66 && k<=77))||(b==14 && (k>=67 && k<=76))||(b==15 && ((k>=68)&&(k<=75)))||(b==16 && ((k>=70)&&(k<=73)))||(b==17 && (k==71 || k==72))||(((b>=9) && (b<=12))&&((k==65)||(k==78)))){
							setcolor(16*4 + 4);printf(" ");setcolor(8);
						}
						else
						{
							setcolor(204);printf(" ");setcolor(8);
						}
						
					}
					else if(/*kandang kuning*/((k>=54 && k<=89)&&((b>=36 && b<=39)||(b>=44 && b<=51)||(b>=56 && b<=59)))||(((k>=54 && k<=59)||(k>=66 && k<=77)||(k>=84 && k<=89))&&((b>=40 && b<=43)||(b>=52 && b<=55)))||((b>=32 && b<=35)&&(k>=84 && k<=89))||/*lurusan kuning*/((b>=28 && b<=31)&&(k>=54 && k<=83))||/*finish kuning*/(k==53 &&(b>=24 && b<=35))||(k==52 &&(b>=24 && b<=35))||(k==51 &&(b>=25 && b<=34))||(k==50 &&(b>=26 && b<=33))||(k==49 &&(b>=27 && b<=32))||(k==48 &&(b>=28 && b<=31)))
					{
						if(/*start kuning*/((k>=84 && k<=89)&&(b==32 || b==35))||/*lurusan kuning*/((b==28 || b==31)&&(k>=54 && k<=83))) 
						{
							
							/*Sudut Kiri Atas*/
							if((b==32 && k==84)||(b==28 && ((k==78)||(k==72)||(k==66)||(k==60)||(k==54))))
							{
								setcolor(16*14 + 0);printf("%c",218);setcolor(153);
							}
							
							/*Sudut Kiri Bawah*/
							else if((b==35 && k==84)||(b==31 && (k==78 || k==72 || k==66 || k==60 || k==54)))
							{
								setcolor(16*14 + 0);printf("%c",192);setcolor(153);
							}
							
							/*Sudut Kanan Atas*/
							else if((b==32 && k==89)||(b==28 && (k==83 || k==77 || k==71 || k==65 || k==59)))
							{
								setcolor(16*14 + 0);printf("%c",191);setcolor(191);
							}
							
							/*Sudut Kanan Bawah*/
							else if((b==35 && k==89)||(b==31 && (k==77 || k==71 || k==65 || k==59 || k==83)))
							{
								setcolor(16*14 + 0);printf("%c",217);setcolor(191);
							}
							else
							{
								setcolor(16*14 + 0);printf("%c",196);setcolor(153);
							}
						}
						//logo "Diamond"
						else if(/*garis sisi kotak*/(b==29 || b==30)&&(k==54 || k==59 || k==60 || k==65 || k==66 || k==71 || k==72 || k==77 || k==78 || k==83) ||((b==33 || b==34)&&(k==84 || k==89)))
						{
							setcolor(16*14 + 0);printf("%c",179);setcolor(191);
						}
						else if(((k>=71 && k<=72)&&(b==42 || b==54))||((k>=70 && k<=73)&&(b==43 || b==53))||(((k>=69)&&(k<=74))&&(b==44 || b==52))||((k>=68 && k<=75)&&(b==45 || b==51))||((k>=67 && k<=76)&&(b==46 || b==50))||((b>=47 && b<=49)&&(k>=66 && k<=77))){
							setcolor(16*6 + 6);printf(" ");setcolor(191);
						}
						else
						{
							setcolor(14*16+14);printf(" ");setcolor(8);
						}
					}
					else if(/*kandang hijau*/(k<=35 && ((b>=36 && b<=39)||(b>=44 && b<=51)||(b>=56 && b<=59)))||(((k<=5)||(k>=12 && k<=23)||(k>=30 && k<=35))&&((b>=40 && b<=43)||(b>=52 && b<=55)))||((b>=56 && b<=59)&&(k>=36 && k<=41))||/*lurusan hijau*/((b>=36 && b<=55)&&(k>=42 && k<=47))||/*finish hijau*/(b==35 &&(k>=38 && k<=51))||(b==34 &&(k>=39 && k<=50))||(b==33 &&(k>=40 && k<=49))||(b==32 &&(k>=41 && k<=48))||(b==31 &&(k>=42 && k<=47))||(b==30 &&(k>=42 && k<=47)))
					{
						{
						if(/*start hijau*/((b>=56 && b<=59)&&(k==36 || k==41)||/*garis atas hijau*/((k==42 || k==47)&&(b>=36 && b<=55))))
						{
							
							/*Sudut Kiri Atas*/
							if((b==56 && k==36)||(k==42 && ((b==52)||(b==48)||(b==44)||(b==40)||(b==36))))
							{
								setcolor(16*10 + 0);printf("%c",218);setcolor(153);
							}
							
							/*Sudut Kiri Bawah*/
							else if((b==59 && k==36)||(k==42 && ((b==51)||(b==47)||(b==43)||(b==39)||(b==55))))
							{
								setcolor(16*10 + 0);printf("%c",192);setcolor(153);
							}
							
							/*Sudut Kanan Atas*/
							else if((b==56 && k==41)||(k==47 && ((b==52)||(b==48)||(b==44)||(b==40)||(b==36))))
							{
								setcolor(16*10 + 0);printf("%c",191);setcolor(191);
							}
							
							/*Sudut Kanan Bawah*/
							else if((b==59 && k==41)||(k==47 && ((b==51)||(b==47)||(b==43)||(b==39)||(b==55))))
							{
								setcolor(16*10 + 0);printf("%c",217);setcolor(191);
							}
							else
							{
								setcolor(16*10 + 0);printf("%c",179);setcolor(153);
							}
						}
						else if(/*garis lurus kotak*/(k<=46 && k>=43)&&(b==55 || b==52 || b==51 || b==48 || b==47 || b==44 || b==43 || b==40 || b==39 || b==36) ||((b==56 || b==59)&&(k<=40 && k>=37)))
						{
							setcolor(16*10 + 0);printf("%c",196);setcolor(191);
						}
						//Logo "Club"
						else if((b==47 &&(k==12 || k==23))||((b>=42 && b<=53)&& (k>=16 && k<=19))||((b==43 || b==46)&& (k>=15 && k<=20))||((b==44 || b==45)&& (k>=14 && k<=21))||((b>=47 && b<=52) && ((k>=13 && k<=14)||(k>=16 && k<=19)||(k>=21 && k<=22)))||((b>=48 && b<=51)&& (k>=11 && k<=24))||((b==49 || b==50)&& (k==10 || k==25))||(b==54 && (k>=15 && k<=20)))
						{
							setcolor(16*2 + 2);printf(" ");setcolor(191);
						}
						else
						{
							setcolor(16*10 + 10);printf(" ");setcolor(8);	
						}
					}
				}
					else
					{
						
						/*garis siku kiri atas*/
						if((b%4==0)&&(k%6==0))
						{
							setcolor(16*15 + 0);printf("%c",218);setcolor(8);
						}
						
						/*garis siku kanan atas*/
						else if((b%4==0)&&((k+1)%6==0))
						{
							setcolor(16*15 + 0);printf("%c",191);setcolor(8);
						}
						
						/*garis siku kiri bawah*/
						else if(((b+1)%4==0)&&(k%6==0))
						{
							setcolor(16*15 + 0);printf("%c",192);setcolor(8);
						}
						
						/*garis siku kanan bawah*/
						else if(((b+1)%4==0)&&((k+1)%6==0))
						{
							setcolor(16*15 + 0);printf("%c",217);setcolor(8);
						}
						
						/*garis hitam vertikal di kotak putih*/
						else if((k%6==0) || ((k+1)%6==0))
						{
							setcolor(16*15 + 0);printf("%c",179);setcolor(8);
						}
						
						/*garis hitam horizontal di kotak putih*/
						else if((b%4==0) || (b%4==3))
						{
							setcolor(16*15 + 0);printf("%c",196);setcolor(8);
						}
						
						else
						{
							setcolor(16*15+15);printf(" ");setcolor(8);
						}
					}
					k++;
				}
				printf("\n");
				b++;
			}
	
		setcolor(16*1+15);draw_shape(0,0,34,22,1);setcolor(8);
		setcolor(16*4+15);draw_shape(54,0,34,22,1);setcolor(8);
		setcolor(16*2+15);draw_shape(0,36,34,22,1);setcolor(8);
		setcolor(16*6+15);draw_shape(54,36,34,22,1);setcolor(8);
		gotoxy(12,2);setcolor(16*15+0);printf("%s",ListPlayer[0].Info.nama);setcolor(8);
		gotoxy(66,2);setcolor(16*15+0);printf("%s",ListPlayer[1].Info.nama);setcolor(8);
		gotoxy(66,38);setcolor(16*15+0);printf("%s",ListPlayer[2].Info.nama);setcolor(8);
		gotoxy(12,38);setcolor(16*15+0);printf("%s",ListPlayer[3].Info.nama);setcolor(8);
}

void clear_kotak(int x, int y)
{
	int n,i,color;
	if((x==0 && y==24)||(y==28 && (x>=6&&x<=36)))
	{
		color=9;
	}
	else if((x==84 && y==32)||(y==28 && (x>=48&&x<=78)))
	{
		color=14;
	}
	else if((x==48 && y==0)||(x==42 && (y>=4&&y<=24)))
	{
		color=12;
	}
	else if((x==36 && y==56)||(x==42 && (y>=32&&y<=52)))
	{
		color=10;
	}else{
		color=15;
	}
	for(i=x;i<=x+5;i++)
	{
		for(n=y;n<=y+3;n++)
		{
			gotoxy(i,n);setcolor(color*15+color);printf(" ");setcolor(color*16);
		}
	}
	if(!((x==42 && (y==24 || y==32))||(y==28 && (x==36 || x==48)))){
		draw_shape(x,y,4,2,2);	
	}
}

void helpabout(int a)
{
	system("cls");
	FILE *fp;
    char karakter;
    if (a==0){
    	system("color 4F");
    	fp = fopen("help2.txt", "r");
	}else{
		setcolor(16*9+15);
		fp = fopen("about.txt", "r");
	}
    if (fp == NULL) {
        printf("file tidak bisa dibuka !!");
    } else {
        while ((karakter = getc(fp)) != EOF) {
            printf("%c", karakter);
//        	sleep(1);
		}
        fclose(fp);
    }
    printf("\n");
    system("pause");
	setcolor(16*0+7);	
}

void gerak_pion(int player, int hero, int x, int y)
{
	int xt=x+5;
	int yt=y+3;
	int x0=x;
	int y0=y;
	int color,latar;
	if(player == 0){
		color = 1;
	
	}
	else if(player == 1){
		color = 4;
	}
	else if(player == 2){
		color = 6;
	}
	else if(player == 3){
		color = 2;
	}
	if ((x==0 && y==24)||(y==28 &&(x>=6 && x<=36))){
		latar = 9;
	}
	else if((x==48 && y==0)||(x==42 && (y>=4 && y<=24))){
		latar = 12;
	}
	else if((x==84 && y==32)||(y==28 && (x>=48 && x<= 78))){
		latar = 14;
	}
	else if((x==36 && y==56)||(x==42 && (y>=32 && y<=52))){
		latar = 10;
	}
	else{
		latar = 15;
	}
	while(y0<=yt){
		x0=x;
		while(x0<=xt){
			switch(hero)
			{
				case 1://Banteng
					if((((x0 ==x+1)||(x0 ==x+4)) && ((y0 ==y)||(y0 ==y+2)))||(y0 == y+1)){
						gotoxy(x0,y0);setcolor(0);printf(" ");setcolor(8);
					}
					else if(((x0>=x+2)&&(x0<=x+3))&&((y0>=y+2)&&(y0<=y+3))){
						gotoxy(x0,y0);setcolor(16*color + color);printf(" ");setcolor(8);
					}
					else{
						gotoxy(x0,y0);setcolor(16*latar+latar);printf(" ");setcolor(8);
					}
					break;
				case 2://ksatria
//					if((((x0>=x+2)&&(x0<=x+3))&&(y0==y))||(((x0>=x+1)&&(x0<=x+4))&&(y0==y+1))||(((x0>=x)&&(x0<=x+5))&&(y0==y+2))||((y0==y+3)&&((x0==x+1)||(x0==x+4)))){
//						gotoxy(x0,y0);setcolor(16*color + color);printf(" ");setcolor(8);
//					}
//					else{
//						gotoxy(x0,y0);setcolor(16*latar+latar);printf(" ");setcolor(8);
//					}
					if(((x0>x)&&(x0<=x+2))&&((y0>=y+2))){
						gotoxy(x0,y0);setcolor(16*7);printf(" ");setcolor(8);
					}
					else if(((x0<xt)&&(x0>x+2))&&((y0>=y+2))){
						gotoxy(x0,y0);setcolor(16*8);printf(" ");setcolor(8);
					}
					else if((y0==y+1)&&((x0==x+1)||(x0==xt-1))){
						gotoxy(x0,y0);setcolor(16*0);printf(" ");setcolor(8);
					}
					else if((y0==y+1)||(((x0==x+2)||(x0==xt-2)||(x0==x)||(x0==xt)))){
						gotoxy(x0,y0);setcolor(16*color);printf(" ");setcolor(8);
					}
					
					else{
						gotoxy(x0,y0);setcolor(16*latar);printf(" ");setcolor(8);
					}
					break;
				case 3://Pengintai
//					if((((x0==x)||(x0==x+2))&&((y0==y)||(y0==y+1)))||((x0==x+1)&&((y0==y+1)||(y0==y+2)))){
//						gotoxy(x0,y0);setcolor(16*5+5);printf(" ");setcolor(8);
//						gotoxy(x0+3,y+(yt-y0));setcolor(16*color+color);printf(" ");setcolor(8);
//					}
//					else if(((x0==x+1)&&(y0==y))||((y0==y+2)&&((x0==x)||(x0==x+2)))||((y0==y+3)&&((x0>=x)&&(x0<=x+2)))){
//						gotoxy(x0,y0);setcolor(16*latar+latar);printf(" ");setcolor(8);
//						gotoxy(x0+3,y+(yt-y0));setcolor(16*latar+latar);printf(" ");setcolor(8);
//					}								
					if(((x0 == x+2) && (y0 == y))||((x0 == x+1)&&((y0>=y+1)&&(y0<=y+2)))||((y0 == yt)&&(x0<xt))){
						gotoxy(x0,y0);setcolor(16*color);printf(" ");setcolor(8);
					}
					else if(((x0 == x+3)&&(y0 == y))||((x0 == xt-1)&&((y0 >= y+1)&&(y0<=y+2)))||((x0 == xt)&&(y0==yt))){
						if(latar == color+8){
							gotoxy(x0,y0);setcolor(16*(color));printf(" ");setcolor(8);
						}	
						else{
							gotoxy(x0,y0);setcolor(16*(color+8));printf(" ");setcolor(8);	
						}
					}
					else if(((x0==x+2)||(x0==x+3))&&((y0==y+1)||(y0==y+2))){
						gotoxy(x0,y0);setcolor(16*0);printf(" ");setcolor(8);
					}
					else{
						gotoxy(x0,y0);setcolor(16*(latar));printf(" ");setcolor(8);
					}
					break;
				case 4://pemburu
//					if(((y0==y+2)&&((x0>=x+1)&&(x0<=xt-1)))||((y0==yt)&&((x0>=x)&&(x0<=xt)))){
//						gotoxy(x0,y0);setcolor(0);printf(" ");setcolor(8);
//					}
//					else if(((y0==y)&&((x0>=x+2)&&(x0<=xt-1)))||((y0==y+1)&&((x0==x+2)||(x0==xt-1)))){
//						gotoxy(x0,y0);setcolor(16*11+11);printf(" ");setcolor(8);
//					}
//					else if((y0==y+1)&&(x0==x+3)){
//						gotoxy(x0,y0);setcolor(16*color+color);printf(" ");setcolor(8);
//					}
//					else{
//						gotoxy(x0,y0);setcolor(16*latar+latar);printf(" ");setcolor(8);
//					}
					if(((y0==y)&&((x0>x)&&(x0<3+x)))||((y0==y+1)&&((x0==x)||(x0==x+2)||(x0==xt)))||((y0==yt-1)&&(x0==x+1))||((y0==yt)&&((x0!=x+2)&&(x0!=x+3)))){
						gotoxy(x0,y0);setcolor(16*(color));printf(" ");setcolor(8);	
					}
					else if(((y0==y)&&((x0>2+x)&&(x0<xt)))||((y0==y+1)&&(x0==xt-2))||((y0==yt-1)&&(x0==xt-1))){
						if(latar==color+8){
							gotoxy(x0,y0);setcolor(16*(color));printf(" ");setcolor(8);
						}
						else{
							gotoxy(x0,y0);setcolor(16*(color+8));printf(" ");setcolor(8);	
						}
					}
					else if((y0==y+1)&&((x0==x+1)||(x0==xt-1))){
						gotoxy(x0,y0);setcolor(16*(0));printf(" ");setcolor(8);
					}
					else if((y0==yt-1)&&((x0==x+2)||(x0==x+3))){
						gotoxy(x0,y0);setcolor(16*(8));printf(" ");setcolor(8);
					}
					else{
						gotoxy(x0,y0);setcolor(16*(latar));printf(" ");setcolor(8);
					}
					break;
				case 0://kuda
//					if(((y0>=y+1)&&(y0<=yt-1))&&((x0==x+1)||(x0==xt-1))){
//						gotoxy(x0,y0);setcolor(16*latar+latar);printf(" ");setcolor(8);
//					}
//					else{
//						gotoxy(x0,y0);setcolor(16*color+color);printf(" ");setcolor(8);
//					}
					if(((y0 == y)&&((x0>=x+1)&&(x0<=x+3)))||((x0 == x)&&((y0>y)))){
						gotoxy(x0,y0);setcolor(16*color);printf(" ");setcolor(8);	
					}
					else if((((x0 == x+1)||(x0 == x+3))&&(y0>y))||((x0==x+2)&&(y0>1+y))||((x0==xt)&&((y0!=y)&&(y0!=yt)))){
						gotoxy(x0,y0);setcolor(16*7);printf(" ");setcolor(8);
					}
					else if(((x0==xt-1)&&((y0!=y)&&(y0!=yt)))){
						gotoxy(x0,y0);setcolor(16*8);printf(" ");setcolor(8);
					}
					else if((x0==x+2)&&(y0==y+1)){
						gotoxy(x0,y0);setcolor(16*0);printf(" ");setcolor(8);
					}
					else{
						gotoxy(x0,y0);setcolor(16*latar);printf(" ");setcolor(8);
					}
					break;
				case 5://penyihir
					{
						if(((y0==y)&&(x0==x+3))||((y0==y+1)&&(x0==x+2))||((y0==yt-1)&&((x0==x+1)||(x0==x+2)))||((y0==yt)&&((x0<xt-1)))){
							gotoxy(x0,y0);setcolor(16*color);printf(" ");setcolor(8);
						}
						else if(((y0==y)&&(x0==xt-1))||((y0==y+1)&&((x0==xt)||(x0==xt-2)))||((y0==yt-1)&&(x0==xt-2))||((y0==yt)&&(x0==xt-1))){
							gotoxy(x0,y0);setcolor(16*0);printf(" ");setcolor(8);
						}
						else{
							gotoxy(x0,y0);setcolor(16*latar);printf(" ");setcolor(8);
						}
						break;
					}
				case 6://patih
					{
						if(((y0==y+1)&&((x0==x)||(x0==x+2)||(x0==xt)))||((y0==yt-1)&&((x0<x+3)))){
							gotoxy(x0,y0);setcolor(16*7);printf(" ");setcolor(8);
						}
						else if(((y0==y+1)&&(x0==x+3))||((y0==yt-1)&&((x0>x+2)))){
							gotoxy(x0,y0);setcolor(16*8);printf(" ");setcolor(8);
						}
						else if(((y0==yt)&&((x0==x)||(x0==x+1)||(x0==xt)||(x0==xt-1)))){
							gotoxy(x0,y0);setcolor(16*color);printf(" ");setcolor(8);
						}
						else if((y0==yt)&&((x0==x+2)||(x0==x+3))){
							gotoxy(x0,y0);setcolor(16*0);printf(" ");setcolor(8);
						}
						else{
							gotoxy(x0,y0);setcolor(16*latar);printf(" ");setcolor(8);
						}
						break;
					}
			}
			x0++;
		}
		y0++;
	}
}

void intro_pion(int player, int hero, int x, int y){
	int xt = (x+35);
	int yt = (y+23);
	int x0 = x;
	int y0 = y;
	int color, muda;
	if(player == 0){
		color = 1;
	}
	else if(player == 1){
		color = 4;
	}
	else if(player == 2){
		color = 6;
	}
	else if(player == 3){
		color = 2;
	}
	muda = color + 8;
	while(y0<=yt){
		x0=x;
		while(x0<=xt){
			switch(hero)
			{
				case 1://Banteng
					
					break;
				case 2://ksatria
					if(((x0==x+13)&&(y0<=y+5))||((y0==y+2)&&((x0>=x+10)&&(x0<=x+23)))||
					((y0==y+3)&&((x0==x+9)||(x0==x+24)))||((y0==y+4)&&((x0==x+8)||(x0==x+25)||(x0==x+14)))
					||((y0==y+5)&&((x0==x+7)||(x0==x+14)||(x0==x+15)||(x0==x+16)||(x0==x+26)))
					||((y0==y+6)&&((x0==x+7)||(x0==x+14)||(x0==x+15)||(x0==x+26)))
					||((y0==y+7)&&((x0==x+7)||((x0>=x+9)&&(x0<=x+13))||((x0>=x+16)&&(x0<=x+22))
					||(x0==x+26)))||((y0==y+8)&&((x0==x+7)||(x0==x+10)||(x0==x+14)||(x0==x+15)||(x0==x+21)||(x0==x+26)))
					||((y0==y+9)&&((x0==x+7)||(x0==x+11)||(x0==x+14)||(x0==x+20)||(x0==x+25)||(x0==x+26)))
					||((y0==y+10)&&((x0==x+8)||((x0>=x+12)&&(x0<=x+19))||(x0==x+25)))
					||((y0==y+11)&&((x0==x+7)||(x0==x+11)||(x0==x+13)||(x0==x+15)||(x0==x+17)||(x0==x+20)||(x0==x+26)))
					||((y0==y+12)&&((x0>=x+6)&&(x0<=x+27)))||((y0==y+13)&&(((x0>=x+7)&&(x0<=x+9))||((x0>=x+22)&&(x0<=x+26))))
					||((y0==y+14)&&((x0==x+7)||(x0==x+8)||(x0==x+10)||((x0>=x+23)&&(x0<=x+26))))
					||((y0==y+15)&&((x0==x+7)||(x0==x+10)||(x0==x+24)||(x0==x+26)))
					||((y0==y+16)&&((x0==x+7)||(x0==x+8)||(x0==x+10)||((x0>=x+24)&&(x0<=x+27))))
					||((y0==y+17)&&((x0==x+6)||(x0==x+7)||(x0==x+10)||(x0==x+24)||(x0==x+27)))
					||((y0==y+18)&&((x0==x+10)||(x0==x+11)||(x0==x+13)||(x0==x+20)||(x0==x+22)||(x0==x+23)||(x0==x+25)))
					||((y0==y+19)&&((x0==x+9)||((x0>=x+14)&&(x0<=x+19))||(x0==x+25)))||((y0==y+20)&&(((x0>=x+9)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+25))))){
						gotoxy(x0,y0);setcolor(0);printf(" ");setcolor(8);
					}
					else if((y0==y+3 &&(((x0>=x+10)&&(x0<=x+12))||((x0>=x+14)&&(x0<=x+21))))||((y0==y+4)&&(((x0>=x+9)&&(x0<=x+12))||((x0>=x+15)&&(x0<=x+22))))||(((y0==y+5)||(y0==y+6))&&(((x0>=x+8)&&(x0<=x+12))||((x0>=x+16)&&(x0<=x+23))))||((y0==y+6)&&(x0==x+13))||((y0==y+7)&&((x0==x+8)||(x0==x+14)||(x0==x+15)||(x0==x+23)))||((y0==y+8)&&((x0==x+8)||(x0==x+9)||(x0==x+22)||(x0==x+23)))||((y0==y+9)&&(((x0>=x+8)&&(x0<=x+10))||(x0==x+21)||(x0==x+22)))||((y0==y+10)&&(((x0>=x+9)&&(x0<=x+11))||((x0>=x+20)&&(x0<=x+22))))||((y0==y+11)&&(((x0>=x+8)&&(x0<=x+8+2))||(((x0>=x+21)&&(x0<=x+21+2)))))||((y0==y+14)&&((x0>=x+13)&&(x0<=x+18)))||((y0==y+15)&&((x0==x+11)||(x0==x+12)||(x0==x+19)||(x0==x+20)))){
						gotoxy(x0,y0);setcolor(muda*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+3)&&((x0==x+22)||(x0==x+23)))||((y0==y+4)&&((x0==x+23)||(x0==x+24)))||(((y0>=y+5)&&(y0<=y+11))&&(x0==x+24))||(((y0>=y+5)&&(y0<=y+8))&&(x0==x+25))||((x0==x+23)&&((y0==y+9)||(y0==y+10)))||((x0==x+25)&&(y0==y+11))||((y0==y+13)&&((x0==x+3)||(x0==x+10)||(x0==x+30)))||((y0==y+14)&&((x0==x+4)||(x0==x+9)||(x0==x+22)||(x0==x+29)))||((y0==y+15)&&((x0==x+5)||(x0==x+8)||(x0==x+9)||((x0>=x+13)&&(x0<=x+18))||(x0==x+23)||(x0==x+25)||(x0==x+28)))||((y0==y+16)&&((x0==x+6)||((x0>=x+11)&&(x0<=x+13))||((x0>=x+18)&&(x0<=x+23))))||((y0==y+17)&&((x0==x+8)||(x0==x+23)||(x0==x+26)))||((y0==y+18)&&((x0==x+12)||(x0==x+21)||(x0==x+24)))||((y0==y+19)&&(((x0>=x+10)&&(x0<=x+14))||((x0>=x+20)&&(x0<=x+24))))){
						gotoxy(x0,y0);setcolor(color*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+8)&&(((x0>=x+11)&&(x0<=x+13))||((x0>=x+16)&&(x0<=x+20))))||((y0==y+9)&&((x0==x+12)||(x0==x+13)||((x0>=x+15)&&(x0<=x+19))))||((y0==y+11)&&((x0==x+12)||(x0==x+14)||(x0==x+16)||(x0==x+18)||(x0==x+19)))||((y0==y+16)&&((x0>=x+14)&&(x0<=x+17)))){
						gotoxy(x0,y0);setcolor(8*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+13)&&((x0>=x+11)&&(x0<=x+21)))||((y0==y+14)&&((x0>=x+19)&&(x0<=x+21)||(x0==x+11)||(x0==x+12)))||((y0==y+15)&&((x0==x+21)||(x0==x+22)))||((y0==y+17)&&((x0>=x+11)&&(x0<=x+22)))||((y0==y+18)&&((x0>=x+14)&&(x0<=x+19)))){
						gotoxy(x0,y0);setcolor(7*16);printf(" ");setcolor(8);
					}
//					else{
//						gotoxy(x0,y0);setcolor(15*16);printf(" ");setcolor(8);
//					}		
					break;
				case 3://Pengintai
					if(((y0==y+2)&&((x0>=x+10)&&(x0<=x+23)))||((y0==y+3)&&((x0==x+9)||(x0==x+24)))||((y0==y+4)&&((x0==x+8)||(x0==x+25)))||(((x0==x+7)||(x0==x+26))&&((y0>=y+5)&&(y0<=y+11)))||((y0==y+7)&&(((x0>=x+12)&&(x0<=x+14))||((x0>=x+17)&&(x0<=x+19))))||((y0==y+10)&&((x0>=x+14)&&(x0<=x+18)))||((y0==y+12)&&(((x0>=x+8)&&(x0<=x+25))))||((x0==x+7)&&((y0>=y+13)&&(y0<=y+16)))||(((x0==x+10)||(x0==x+24))&&((y0>=y+14)&&(y0<=y+17)))||((x0==x+25)&&((y0==y+13)||(y0==y+16)))||((x0==x+26)&&((y0==y+14)||(y0==y+15)||(y0==y+17)))||((y0==y+16)&&(x0==x+27))||((y0==y+17)&&((x0==x+8)||(x0==x+9)))||((y0==y+18)&&((x0==x+8)||(x0==x+13)||(x0==x+20)||(x0==x+24)))||((y0==y+19)&&((x0==x+9)||((x0>=x+14)&&(x0<=x+19))||(x0==x+24)))||((y0==y+20)&&(((x0>=x+9)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+24))))){
						gotoxy(x0,y0);setcolor(0*16);printf(" ");setcolor(8);
					}
					else if((((y0>=y+3)&&(y0<=y+6))&&((x0>=x+10)&&(x0<=x+21)))||((x0==x+10)&&((y0>=y+7)&&(y0<=y+11)))||(((x0==x+9)||(x0==x+22))&&((y0>=y+4)&&(y0<=y+11)))||(((x0==x+8)||(x0==x+23))&&((y0>=y+5)&&(y0<=y+11)))||((y0==y+7)&&((x0==x+11)||(x0==x+15)||(x0==x+16)||(x0==x+20)||(x0==x+21)))||((y0==y+13)&&((x0>=x+11)&&(x0<=x+23)))||((y0==y+14)&&((x0==x+8)||(x0==x+9)||(x0==x+11)||(x0==x+12)||((x0>=x+19)&&(x0<=x+23))))||((y0==y+16)&&((x0==x+8)||(x0==x+9)))||((y0==y+17)&&((x0>=x+11)&&(x0<=x+21)))||((y0==y+18)&&(((x0>=x+9)&&(x0<=x+11))||((x0>=x+15)&&(x0<=x+18))||((x0>=x+21)&&(x0<=x+23))))){
						gotoxy(x0,y0);setcolor(muda*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+8)&&((x0>=x+12)&&(x0<=x+20)))||(((y0>=y+8)&&(y0<=y+11))&&((x0==x+11)||(x0==x+21)))||((y0==y+13)&&((x0>=x+8)&&(x0<=x+10)))||((y0==y+15)&&((x0==x+8)||(x0==x+9)||((x0>=x+13)&&(x0<=x+18))))||((y0==y+16)&&((x0>=x+11)&&(x0<=x+23)))||((y0==y+17)&&((x0==x+25)||(x0==x+27)))||((y0==y+18)&&((x0==x+14)||(x0==x+19)||(x0==x+25)||(x0==x+28)))||((y0==y+19)&&(((x0>=x+10)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+23))||(x0==x+25)))){
						gotoxy(x0,y0);setcolor(8*16);printf(" ");setcolor(8);
					}
					else if((((x0>=x+14)&&(x0<=x+18))&&((y0==y+9)||(y0==y+11)))||(((y0>=y+9)&&(y0<=y+11))&&((x0==x+12)||(x0==x+13)||(x0==x+19)||(x0==x+20)))||((y0==y+14)&&((x0>=x+13)&&(x0<=x+19)))||((y0==y+15)&&((x0==x+11)||(x0==x+12)||((x0>=x+19)&&(x0<=x+23))))||((y0==y+17)&&((x0==x+22)||(x0==x+23)))||((y0==y+18)&&(x0==x+12))){
						gotoxy(x0,y0);setcolor(7*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+3)&&((x0==x+22)||(x0==x+23)))||((y0==y+4)&&((x0==x+23)||(x0==x+24)))||(((x0==x+24)||(x0==x+25))&&((y0>=y+5)&&(y0<=y+11)))||((y0==y+12)&&((x0==x+26)))||((y0==y+13)&&((x0==x+24)||(x0==x+26)||(x0==x+27)))||((y0==y+14)&&((x0==x+25)||(x0==x+27)||(x0==x+28)))||((y0==y+15)&&((x0==x+25)||(x0==x+27)||(x0==x+28)||(x0==x+29)))||((y0==y+16)&&((x0==x+26)||(x0==x+28)||(x0==x+29)||(x0==x+30)))||((y0==y+17)&&((x0>=x+28)&&(x0<=x+32)))||((y0==y+18)&&((x0==x+26)||(x0==x+27)||((x0>=x+29)&&(x0<=x+33))))||((y0==y+19)&&((x0>=x+26)&&(x0<=x+34)))){
						gotoxy(x0,y0);setcolor(color*16);printf(" ");setcolor(8);
					}
//					else{
//						gotoxy(x0,y0);setcolor(15*16);printf(" ");setcolor(8);
//					}
					break;
				case 4://pemburu
				
					break;
				case 0://kuda
				
					break;
				case 5://penyihir
					if(((y0==y)&&((x0>=x+15)&&(x0<=x+25)))||((y0==y+1)&&(((x0>=x+12)&&(x0<=x+19))||((x0>=x+21)&&(x0<=x+28))))||((y0==y+2)&&((x0>=x+10)&&(x0<=x+16)||((x0>=x+18)&&(x0<=x+24))||((x0>=x+26)&&(x0<=x+30))))||((y0==y+3)&&(((x0>=x+8)&&(x0<=x+12))||((x0>=x+14)&&(x0<=x+20))||((x0>=x+22)&&(x0<=x+27))))||((y0==y+4)&&((x0==x+7)||(x0==x+8)||((x0>=x+10)&&(x0<=x+15))||((x0>=x+17)&&(x0<=x+22))||((x0>=x+24)&&(x0<=x+26))))||((y0==y+5)&&((x0>=x+6)&&(x0<=x+27)))||(((x0==x+7)||(x0==x+26))&&((y0>=y+6)&&(y0<=y+10)))||((y0==y+7)&&((x0==x+12)||(x0==x+13)||(x0==x+17)||(x0==x+18)))||((y0==y+10)&&((x0>=x+14)&&(x0<=x+18)))||((y0==y+11)&&((x0==x+8)||(x0==x+25)))||((y0==y+12)&&(((x0>=x+6)&&(x0<=x+13))||((x0>=x+19)&&(x0<=x+27))))||((y0==y+13)&&(((x0>=x+7)&&(x0<=x+9))||((x0>=x+22)&&(x0<=x+26))))||((y0==y+14)&&((x0==x+4)||(x0==x+7)||(x0==x+8)||(x0==x+10)||((x0>=x+23)&&(x0<=x+26))))||((y0==y+15)&&((x0==x+5)||(x0==x+7)||(x0==x+10)||(x0==x+24)||(x0==x+26)))||((y0==y+16)&&(((x0>=x+6)&&(x0<=x+8))||(x0==x+10)||((x0>=x+24)&&(x0<=x+27))))||((y0==y+17)&&((x0==x+6)||(x0==x+7)||(x0==x+10)||(x0==x+24)||(x0==x+27)))||((y0==y+18)&&((x0==x+10)||(x0==x+11)||(x0==x+13)||(x0==x+20)||(x0==x+22)|(x0==x+23)||(x0==x+25)))||((y0==y+19)&&((x0==x+9)||((x0>=x+14)&&(x0<=x+19))||(x0==x+25)))||((y0==y+20)&&(((x0>=x+9)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+25))))){
						gotoxy(x0,y0);setcolor(0*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+2)&&((x0==x+31)||(x0==x+32)))||((y0==y+3)&&((x0>=x+29)&&(x0<=x+33)))||((y0==y+4)&&((x0>=x+30)&&(x0<=x+32)))||(((y0==y+9)||(y0==y+11))&&((x0>=x+13)&&(x0<=x+19)))||((y0==y+10)&&((x0==x+13)||(x0==x+19)))||(((y0==y+12)||(y0==y+14))&&((x0>=x+14)&&(x0<=x+18)))||((y0==y+13)&&((x0>=x+15)&&(x0<=x+19)))||((y0==y+15)&&((x0==x+15)||(x0==x+16)))){
						gotoxy(x0,y0);setcolor(7*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+7)&&((x0==x+14)||(x0==x+19)))||((y0==y+16)&&((x0>=x+14)&&(x0<=x+17)))||((y0==y+17)&&((x0>=x+11)&&(x0<=x+22)))||((y0==y+18)&&((x0>=x+14)&&(x0<=x+19)))){
						gotoxy(x0,y0);setcolor(8*16);printf(" ");setcolor(8);
					}
					else if(((x0==x+8)&&((y0>=y+6)&&(y0<=y+10)))||((((x0>=x+9)&&(x0<=x+11))||((x0>=x+20)&&(x0<=x+23)))&&((y0>=y+6)&&(y0<=y+11)))||((y0==y+7)&&((x0==x+15)||(x0==x+16)))||(((y0==y+8)||(y0==y+6))&&((x0>=x+12)&&(x0<=x+19)))||((x0==x+12)&&((y0>=y+9)&&(y0<=y+11)))||((x0==x+13)&&((y0>=y+13)&&(y0<=y+16)))||((x0==x+14)&&((y0==y+13)||(y0==y+15)))||((x0==x+17)&&(y0==y+15))||((x0==x+18)&&((y0==y+15)||(y0==y+16)))||((x0==x+19)&&((y0>=y+14)&&(y0<=y+16)))){
						gotoxy(x0,y0);setcolor(muda*16);printf(" ");setcolor(8);
					}
					else if((((x0==x+24)||(x0==x+25))&&((y0>=y+6)&&(y0<=y+10)))||((x0==x+24)&&(y0==y+11))||(((x0==x+11)||(x0==x+12)||(x0==x+20)||(x0==x+21))&&((y0>=y+13)&&(y0<=y+16)))||((x0==x+22)&&((y0>=y+14)&&(y0<=y+16)))||((x0==x+23)&&((y0>=y+15)&&(y0<=y+17)))||((y0==y+13)&&(x0==x+10))||((y0==y+14)&&(x0==x+9))||((y0==y+15)&&((x0==x+8)||(x0==x+9)||(x0==x+25)))||((y0==y+17)&&((x0==x+8)||(x0==x+26)))||((y0==y+18)&&((x0==x+12)||(x0==x+21)||(x0==x+24)))||((y0==y+19)&&(((x0>=x+10)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+24))))){
						gotoxy(x0,y0);setcolor(color*16);printf(" ");setcolor(8);
					}
					else if(((y0==y)&&(x0==x+26))||((y0==y+1)&&(x0==x+20))||((y0==y+2)&&((x0==x+17)||(x0==x+25)))||((y0==y+3)&&((x0==x+13)||(x0==x+21)))||((y0==y+4)&&((x0==x+9)||(x0==x+16)||(x0==x+23)))){
						gotoxy(x0,y0);setcolor(14*16);printf(" ");setcolor(8);
					}
//					else{
//						gotoxy(x0,y0);setcolor(15*16);printf(" ");setcolor(8);
//					}
					break;					
				case 6://patih
					if(((y0<=y+10)&&((x0==x+7)||(x0==x+26)))||((y0==y)&&(((x0>=x+8)&&(x0<=x+10))||((x0>=x+14)&&(x0<=x+18))||((x0>=x+23)&&(x0<=x+25))))||(((y0>=y+1)&&(y0<=y+2))&&((x0==x+11)||(x0==x+13)||(x0==x+19)||(x0==x+22)))||((y0==y+2)&&((x0==x+12)||(x0==x+20)||(x0==x+21)))||((y0==y+7)&&((x0==x+12)||(x0==x+13)||(x0==x+17)||(x0==x+18)))||((y0==y+10)&&((x0>=x+14)&&(x0<=x+18)))||((y0==y+11)&&((x0==x+8)||(x0==x+25)))||((y0==y+12)&&((x0>=x+6)&&(x0<=x+27)))||(((y0>=y+13)&&(y0<=y+16))&&((x0==x+7)||(x0==x+10)||(x0==x+24)||(x0==x+26)))||(((y0==y+13)||(y0==y+14))&&((x0==x+8)||(x0==x+23)||(x0==x+25)))||((y0==y+13)&&((x0==x+9)||(x0==x+22)))||((y0==y+16)&&((x0==x+8)||(x0==x+25)||(x0==x+27)))||((y0==y+17)&&((x0==x+6)||(x0==x+7)||(x0==x+10)||(x0==x+24)||(x0==x+27)))||((y0==y+18)&&((x0==x+10)||(x0==x+11)||(x0==x+13)||(x0==x+20)||(x0==x+22)||(x0==x+23)||(x0==x+25)))||((y0==y+19)&&((x0==x+9)||((x0>=x+14)&&(x0<=x+19))||(x0==x+25)))||((y0==y+20)&&(((x0>=x+9)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+25))))||((y0==y+4)&&((x0>=x+8)&&(x0<=x+25)))){
						gotoxy(x0,y0);setcolor(0*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+3)&&((x0>=x+8)&&(x0<=x+24)))||(((y0==y+1)||(y0==y+2))&&((x0==x+8)||(x0==x+9)||((x0>=x+14)&&(x0<=x+16))||(x0==x+23)||(x0==x+24)))){
						gotoxy(x0,y0);setcolor((6+8)*16);printf(" ");setcolor(8);
					}
					else if((((y0==y+1)||(y0==y+2))&&((x0==x+10)||(x0==x+17)||(x0==x+18)||(x0==x+25)))||((y0==y+3)&&(x0==x+25))){
						gotoxy(x0,y0);setcolor((6)*16);printf(" ");setcolor(8);
					}
					else if((((y0==y+5)||(y0==y+6)||(y0==y+8))&&((x0>=x+8)&&(x0<=x+23)))||((y0==y+7)&&(((x0>=x+8)&&(x0<=x+11))||(x0==x+15)||(x0==x+16)||((x0>=x+20)&&(x0<=x+23))))||(((y0>=y+9)&&(y0<=y+11))&&(((x0>=x+9)&&(x0<=x+12))||((x0>=x+20)&&(x0<=x+23))))||((x0==x+8)&&((y0==y+9)||(y0==y+10)))||((y0==y+11)&&((x0>=x+14)&&(x0<=x+18)))||((y0==y+14)&&((x0>=x+13)&&(x0<=x+18)))||((y0==y+15)&&((x0==x+11)||(x0==x+12)||(x0==x+19)||(x0==x+20)))){
						gotoxy(x0,y0);setcolor((muda)*16);printf(" ");setcolor(8);
					}
					else if((((x0==x+24)||(x0==x+25))&&((y0>=y+5)&&(y0<=y+10)))||((x0==x+24)&&(y0==y+11))||((y0==y+14)&&((x0==x+9)||(x0==x+22)))||((y0==y+15)&&((x0==x+8)||(x0==x+9)||((x0>=x+13)&&(x0<=x+18))||(x0==x+23)||(x0==x+25)))||((y0==y+16)&&((x0==x+6)||((x0>=x+11)&&(x0<=x+13))||((x0>=x+18)&&(x0<=x+23))))||((y0==y+17)&&((x0==x+8)||(x0==x+23)||(x0==x+26)))||((y0==y+18)&&((x0==x+12)||(x0==x+21)||(x0==x+24)))||((y0==y+19)&&(((x0>=x+10)&&(x0<=x+13))||((x0>=x+20)&&(x0<=x+24))))){
						gotoxy(x0,y0);setcolor((color)*16);printf(" ");setcolor(8);
					}
					else if(((y0==y+7)&&((x0==x+14)||(x0==x+19)))||((y0==y+9)&&((x0>=x+13)&&(x0<=x+19)))||(((y0==y+10)||(y0==y+11))&&((x0==x+13)||(x0==x+19)))||((y0==y+16)&&((x0>=x+14)&&(x0<=x+17)))){
						gotoxy(x0,y0);setcolor(8*16);printf(" ");setcolor(8);
					}
					else if((((y0==y+13)||(y0==y+17))&&((x0>=x+11)&&(x0<=x+21)))||((y0==y+14)&&((x0==x+11)||(x0==x+12)||((x0>=x+19)&&(x0<=x+21))))||(((y0==y+17)||(y0==y+15))&&((x0==x+21)||(x0==x+22)))||((y0==y+18)&&((x0>=x+14)&&(x0<=x+19)))){
						gotoxy(x0,y0);setcolor(7*16);printf(" ");setcolor(8);
					}
//					else{
//						gotoxy(x0,y0);setcolor(15*16);printf(" ");setcolor(8);
//					}
					break;
			}
			x0++;
		}
		y0++;
	}
	
}

void menu_permainan(){
	int b=1,k=1;
	for(b=0;b<=59;b++){
		for(k=90;k<=107;k++){
			if(((b>=1 && b<=8)&& (k>=92&&k<=96))||((b>=6&&b<=8)&&(k>=97&&k<=105))){
				if((b>=2 && k<=94)||(b>=7&&k<=103)){
					gotoxy(k,b);setcolor(16*9+9);printf(" ");setcolor(8);
				}else if(!((b==1 && k==92)||(b==8&&(k>=104 &&k<=105)))){
					gotoxy(k,b);setcolor(16*1+1);printf(" ");setcolor(8);
				}
				else{
					gotoxy(k,b);setcolor(16*15+15);printf(" ");setcolor(8);
				}
			}
			else if(((b>=12 && b<=19) && (k>=92&&k<=96))||((b>=17&&b<=19)&&(k>=97&&k<=101))||((b>=12&&b<=19)&&(k>=101&&k<=105))){
				if((b>=13&&k<=94)||(b>=13&&(k==102||k==103||k==101))||(b>=18&&k<=103)){
					gotoxy(k,b);setcolor(16*12+12);printf(" ");setcolor(8);
				}else if(!((b==12&&k==92)||(b==19&&(k==104||k==105))||(b==12&&k==101))){
					gotoxy(k,b);setcolor(16*4+4);printf(" ");setcolor(8);
				}else{
					gotoxy(k,b);setcolor(16*15+15);printf(" ");setcolor(8);					
				}
			}
			else if(((b>=23 && b<=30) && (k>=92&&k<=96))||(((b==23||b==24)||(b>=28&&b<=30))&&(k>=97&&k<=101))||((k==102)&&((b>=23&&b<=27)||(b>=28&&b<=30)))||(k==103&&(b>=23&&b<=30))||(k==104&&(b>=24&&b<=29))||(k==105&&(b>=25&&b<=28))){
				if((k<=94&&b>=24)||(b==24&&k<=102)||((k==102||k==103)&&(b<=28&&b>=25))||((b==29||b==30)&&(k<=101))||(b==29&&k==102)){
					gotoxy(k,b);setcolor(16*14+14);printf(" ");setcolor(8);
				}else if(!((b==23&&k==92)||(b==30&&(k==102||k==103)))){
					gotoxy(k,b);setcolor(16*6+6);printf(" ");setcolor(8);
				}else{
					gotoxy(k,b);setcolor(16*15+15);printf(" ");setcolor(8);
				}
			}
			else if(((b>=36 && b<=40) && ((k>=92&&k<=96)||(k>=101&&k<=105)))||(((b==34||b==35)||(b>=41&&b<=42))&&(k>=94&&k<=103))||((b==35||b==41)&&(k==93||k==104))){
				if((k==92||k==93)||(b==35&&k<=102)||(k==94&&b>=35)||(b==42&&k<=101)||((b<=40&&b>=36)&&(k>=101&&k<=103))||(b==41&&(k==101||k==102))){
					gotoxy(k,b);setcolor(16*10+10);printf(" ");setcolor(8);
				}else{
					gotoxy(k,b);setcolor(16*2+2);printf(" ");setcolor(8);
				}
			}else if(b>=44){
				gotoxy(k,b);setcolor(16*8+8);printf(" ");setcolor(8);
			}else{
				gotoxy(k,b);setcolor(16*15+15);printf(" ");setcolor(8);
			}
		}
	}
}
void Print_Awal(int player){
	int i=0, x, y;
	switch(player){
		case 0:
			clear_kotak(6,4);					
			clear_kotak(24,4);					
			clear_kotak(6,16);					
			clear_kotak(24,16);					
			for(i=0;i<4;i++){
				switch(i){
					case 0:
						x=4;
						y=6;
						break;
					case 1:
						x=4;
						y=24;
						break;
					case 2:
						x=16;
						y=6;
						break;
					case 3:
						x=16;
						y=24;
						break;
				}
				if(home[player][i].pion==true){
					gerak_pion(player, home[player][i].type, y, x);
				}
			}
			break;
		case 1:
			clear_kotak(60,4);					
			clear_kotak(78,4);					
			clear_kotak(60,16);					
			clear_kotak(78,16);					
			for(i=0;i<4;i++){
				switch(i){
					case 0:
						x=4;
						y=60;
						break;
					case 1:
						x=4;
						y=78;
						break;
					case 2:
						x=16;
						y=60;
						break;
					case 3:
						x=16;
						y=78;
						break;
				}
				if(home[player][i].pion==true){
					gerak_pion(player, home[player][i].type, y, x);
				}
			}
			break;
		case 2:
			clear_kotak(60,40);					
			clear_kotak(78,40);					
			clear_kotak(60,52);					
			clear_kotak(78,52);					
			for(i=0;i<4;i++){
				switch(i){
					case 0:
						x=40;
						y=60;
						break;
					case 1:
						x=40;
						y=78;
						break;
					case 2:
						x=52;
						y=60;
						break;
					case 3:
						x=52;
						y=78;
						break;
				}
				if(home[player][i].pion==true){
					gerak_pion(player, home[player][i].type, y, x);
				}
			}
			break;
		case 3:
			clear_kotak(24,52);					
			clear_kotak(6,52);					
			clear_kotak(24,40);					
			clear_kotak(6,40);					
			for(i=0;i<4;i++){
				switch(i){
					case 0:
						x=52;
						y=24;
						break;
					case 1:
						x=52;
						y=6;
						break;
					case 2:
						x=40;
						y=24;
						break;
					case 3:
						x=40;
						y=6;
						break;
				}
				if(home[player][i].pion==true){
					gerak_pion(player, home[player][i].type, y, x);
				}
			}
			break;
	}
}

void ClearPilihan(warna)
	{
		int i,j;
	for(i = 44; i < 60;i++){
		for(j=90;j<108;j++){
			gotoxy(j,i);
			setcolor(16*warna+8);printf(" ");
		}
	}
	}

void drawdice(int x, int y, int dadu){
	int i,j;
	for(i = 0; i < 5;i++){
		for(j=0;j<7;j++){
			gotoxy(x+j,y+i);
			setcolor(16*15);
			printf(" ");
		}
	}
	int xo=x,yo=y,xt=xo+6,yt=y+4;
	setcolor(16 * 15 + 12);
	switch(dadu){
		case 1 :
				while(yo<=yt){
					xo=x;
					while(xo<=xt){
						if(xo==x+3){
							gotoxy(xo,yo);printf("%c",254);
						}
						else if(xo==x+2 && (yo==y+1 || yo==yt)){
							gotoxy(xo,yo);printf("%c",254);
						}
						else if(xo==x+4 && yo==yt){
							gotoxy(xo,yo);printf("%c",254);
						}
						xo++;
					}
					yo++;
				}
			
			break;
		case 2 :
			while(yo<=yt){
					xo=x;
					while(xo<=xt){
						if((yo==y) && (xo>=x+1 && xo<=xt-1)){
							gotoxy(xo,yo);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
							gotoxy(xo,yt);printf("%c",254);
						}
						else if(yo==y+1 && (xo>=xt-2 && xo<=xt-1)){
							gotoxy(xo,yo);printf("%c",254);
							gotoxy(xo-3,yo+2);printf("%c",254);
						}
						xo++;
					}
					yo++;
				}
			break;
		case 3 :
			
			while(yo<=yt){
					xo=x;
					while(xo<=xt){
						if((yo==y) && (xo>=x+1 && xo<=xt-1)){
							gotoxy(xo,yo);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
							gotoxy(xo,yt);printf("%c",254);
						}
						else if(yo==y+1 && (xo>=xt-2 && xo<=xt-1)){
							gotoxy(xo,yo);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
						}
						xo++;
					}
					yo++;
				}
			break;
		case 4 :
			
			while(yo<=yt){
					xo=x;
					while(xo<=xt){
						if(xo==xt-1){
							gotoxy(xo,yo);printf("%c",254);
						}
						else if(xo==x+1 && (yo<=y+2)){
							gotoxy(xo,yo);printf("%c",254);
						}
						else if(yo==y+2 && (xo>=x+2 && xo<=x+4)){
							gotoxy(xo,yo);printf("%c",254);
						}
						xo++;
					}
					yo++;
				}
			break;
		case 5 :
			
			while(yo<=yt){
					xo=x;
					while(xo<=xt){
						if((yo==y) && (xo>=x+1 && xo<=xt-1)){
							gotoxy(xo,yo);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
							gotoxy(xo,yt);printf("%c",254);
						}
						else if(yo==y+1 && (xo>=xt-2 && xo<=xt-1)){
							gotoxy(xo-3,yo);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
						}
						xo++;
					}
					yo++;
				}
			break;
		case 6 :
			
			while(yo<=yt){
					xo=x;
					while(xo<=xt){
						if((yo==y) && (xo>=x+1 && xo<=xt-1)){
							gotoxy(xo,yo);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
							gotoxy(xo,yt);printf("%c",254);
						}
						else if(yo==y+1 && ( xo==xt-1)){
							gotoxy(xo-4,yo);printf("%c",254);
							gotoxy(xo-4,yo+2);printf("%c",254);
							gotoxy(xo,yo+2);printf("%c",254);
						}
						xo++;
					}
					yo++;
				}
			break;
	}
	setcolor(8);
	
}


int Print_Pion_Baru_Menu(int No_Player, int t){
	int warna;
	if(No_Player == 0){
		warna = 9;
	}
	else if(No_Player == 1){
		warna = 12;
	}
	else if(No_Player == 2){
		warna = 14;
	}
	else if(No_Player == 3){
		warna = 10;
	}
	ClearPilihan(warna);
	int i,n,Jmlh_Pion,Pilihan;
	Lokasi Pion;
	Node P;
	P = ListPlayer[No_Player].Pion;
	if(t==1){
		Jmlh_Pion=CountNode(ListPlayer[No_Player].Pion);
		P = ListPlayer[No_Player].Pion;
		while(P != Nil)
			{
				Pion = Koordinat(P->type);
				gerak_pion(No_Player, P->type, Pion.x, Pion.y);
				P = P->next;
			}
	}else{
		Jmlh_Pion=0;
		for(i = 0; i < 4; i++){
			if(home[No_Player][i].pion == true){
				Pion = Koordinat(home[No_Player][i].type);	
				gerak_pion(No_Player, home[No_Player][i].type, Pion.x, Pion.y);
				Jmlh_Pion++;
			}
		}	
	}
	i=0;
	Pion = Koordinat(i);
	do{
		for(n=93;n<108;n++){		
			setcolor(16*warna+0);gotoxy(n,52);printf(" ");
			setcolor(16*warna+0);gotoxy(n,58);printf(" ");
		}
		gotoxy((Pion.x)+2, (Pion.y)+4);setcolor(16*warna+0);printf("%c%c",17,16);setcolor(8);
		Pilihan = getch();
		if(Pilihan == 77){
			if(Pion.x==100 && Pion.y==54){
				i=0;
			}else{
				i=i+1;
			}
		}else if(Pilihan == 75 ){
			if(Pion.x==92 && Pion.y==48){
				i=3;
			}else{
				i=i-1;
			}	
		}else if(Pilihan == 80 ){
			if(Pion.x==92 && Pion.y==54){
				i=0;
			}else if(Pion.x==100 && Pion.y==54){
				i=1;
			}else{
				i=i+2;
			}
		}else if(Pilihan == 72 ){
			if(Pion.x==92 && Pion.y==48){
				i=2;
			}else if(Pion.x==100 && Pion.y==48){
				i=3;
			}else{
				i=i-2;
			}
		}
		if(i>4){
			i=0;
		}
		Pion = Koordinat(i);		
	}while(Pilihan!=13 && Pilihan!=32);
	return (i);
}

Lokasi Koordinat(int No_Pion){
	Lokasi Pilihan;
	switch(No_Pion){
		case 0:
			Pilihan.x=92;
			Pilihan.y=48;
			return Pilihan;
			break;
		case 1:
			Pilihan.x=100;
			Pilihan.y=48;
			return Pilihan;
			break;
		case 2:
			Pilihan.x=92;
			Pilihan.y=54;
			return Pilihan;
			break;
		case 3:
			Pilihan.x=100;
			Pilihan.y=54;
			return Pilihan;
			break;
	}
}

int gamemode(){
	
	system("cls");
	int x,y,pil,pencet,korektor=0;
	x=3;
	y=4;
	gotoxy(x,y);printf("Pilih mode");
	pil=y+2;
	do{
		gotoxy(x,y+2);printf("Player versus Player");
		gotoxy(x,y+3);printf("Player versus Computer");
		if(pil == y+2){
			gotoxy(x,pil);setcolor(16*10+0);printf("Player versus Player");setcolor(8);
		}
		else if(pil == y+3){
			gotoxy(x,pil); setcolor(16*14+0);printf("Player versus Computer");setcolor(8);
		}
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
		if(pil<y+2){
			pil=y+3;
		}
		if(pil>y+3){
			pil=y+2;
		}
		
	}while(korektor!=1);
	return pil;
}
