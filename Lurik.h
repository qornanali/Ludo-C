#ifndef Lurik_H
#define Lurik_H
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define sikukananbawah 217
#define sikukiriatas 218
#define sikukananatas 191
#define sikukiribawah 192
#define duasikukananatas 187
#define duasikukananbawah 188
#define duasikukiriatas 201
#define duasikukiribawah 200
#define duahor 205
#define duaver 186
#define ver 179
#define hor 196
#define true 0
#define false 1
#define Nil NULL

/* --------------------- Tipe Data -------------------- */

typedef int bool;

typedef struct {
	int x;
	int y;
} Lokasi;

typedef struct Lst *Node;
typedef struct Lst {
		int type;
		int before;
		int Position;
		Node next;
	} ElmntList;

typedef struct {
	char nama[60];
	int skor;
	int chance;
	int finish;
} PlayerInfo;

typedef struct{
	PlayerInfo Info;
	Node Pion;
} Player;

typedef struct {
	int pion;
	int type;
} status;

int nplayer,dice_value;
Player ListPlayer[4];

status home[4][4];
int Dice_Pattern[6][6];

int terbesar,mode;
/* --------------------- Prototype -------------------- */

/* UI Prototype */
void clear_kotak(int x, int y);
void gerak_pion(int player, int hero, int x, int y);
void gotoxy(int x, int y);
void setcolor(unsigned short color);
void draw_shape(int x,int y,int v, int h, int type);
void menu();
void intro();
void papan();
void clear_kotak(int x, int y);
void menu_permainan();
void helpabout(int a);
void Print_Awal(int player);
void drawdice(int x, int y, int dadu);
void ClearPilihan( int warna);
Lokasi Koordinat(int No_Pion);
int Print_Pion_Baru_Menu(int No_Player, int t);

/* Data Prototype */
void prepareplayer(int x, int y, int n);
void swapvalue(int *a, int *b);
void savehighscore(char nama[], int skor);
void showhighscore();
void cek_win();

/* Game Prototype */
int shake_dice(int opt,int x, int y, int No_Player);
int odd_even( int opt, int value);
void UserBermain(int noPlayer);
void moving(int noPlayer, Node P,int dadu);
Lokasi posisi_koordinat(int posisi);
int Play();
int CekHome(int noPlayer);
Node cekfront(int mynoplayer, int posisi, int *hisnoplayer);
Node SearchNodeToFlee( Node List, int value,int noPlayer);
Node SearchNodeToEat( Node List, int value,int noPlayer);
void keluarin_pion(int noPlayer);
int petak_awal_player(int noPlayer);
int step_left_to_be_eaten(int noPlayer,Node *temp);
int step_left_to_eat(int noPlayer,Node *temp);
int safe_zone_player(int noPlayer);
int finish_player(int noPlayer);
int step_left_to_finish(int noPlayer,Node *temp);
int ada_pion_di_home(int noPlayer);
int tdk_ada_pion_di_petak_awal(int noPlayer);
Node pion_terjauh(int noPlayer);
void comp_turn(int noPlayer);
void pionmove(int noPlayer, Node P,int dadu);
void setHome(int type, int state, int noPlayer);
void moving_pion(int noPlayer, Node P ,int dadu );
void herodoskill(int noPlayer, Node P, int *add);
bool active(Node P);


/* List Prototype */
void CreateList( Node *List);
int EmptyList( Node List);
void InsLast( Node *List, int value, int posisi);
void InsertLast( Node *List, Node P);
void PrintNode( Node List);
Node Alokasi (int value, int posisi);
void Dealokasi(Node P);
Node SearchNode( Node List, int value);
Node SearchPrevNode( Node List, int value);
int CountNode( Node List);
int DelP( Node *List, int value);

/*bot prototype*/


#endif
