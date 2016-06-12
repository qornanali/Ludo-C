#include"Lurik.h"

Node SearchNodeToFlee( Node List, int value, int noPlayer);
Node SearchNodeToEat( Node List, int value,int noPlayer);
void keluarin_pion(int noPlayer);
int petak_awal_player(int noPlayer);
int step_left_to_be_eaten(int noPlayer,Node *temp);
int finish_player(int noPlayer);
int step_left_to_finish(int noPlayer,Node *temp);
int tdk_ada_pion_di_petak_awal(int noPlayer);
void comp_turn(int noPlayer);
int suicide(int noPlayer,int pos);


void comp_turn(int noPlayer){//procedure gerak() blm d panggil
	int warna,dadu,yg_gerak_pion_ke,step_to_finish,step_to_eat,step_to_be_eaten,difficulty=2,type;
	Node temp,P;
	int safe_zone=finish_player(noPlayer)-5;Lokasi Posisi;int x;
	
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
	
	switch(difficulty){
		case 0:
			step_to_finish=step_left_to_finish(noPlayer,&temp);
			if(ListPlayer[noPlayer].Info.chance>0){
				if(step_to_finish&&!ada_pion_di_home(noPlayer)&&tdk_ada_pion_di_main_track(noPlayer)){			//cek jk ada pion d safezone
					if(step_to_finish%2==0){
						dadu=shake_dice(2,94,47,noPlayer);
						ListPlayer[noPlayer].Info.chance--;
					}else{
						dadu=shake_dice(3,94,47,noPlayer);//shake dice 3
						ListPlayer[noPlayer].Info.chance--;
					}
				}else{
					dadu=shake_dice(1,94,47,noPlayer);
				}
			}else{
				dadu=shake_dice(1,94,47,noPlayer);
			}
			gotoxy(0,60);printf("chance p%d: %d",noPlayer,ListPlayer[noPlayer].Info.chance);
			Sleep(1000);
			//getch();
			if(dadu==6&&tdk_ada_pion_di_petak_awal(noPlayer)&&ada_pion_di_home(noPlayer)){
				keluarin_pion(noPlayer);
			}
				else//pion d home
			if(dadu==step_to_finish){		//cek jk ada pion d safezone	
				moving(noPlayer,temp,dadu);
			}else{
				if(CountNode(ListPlayer[noPlayer].Pion)!=0){
					temp=pion_terjauh(noPlayer);
					moving(noPlayer,temp,dadu);
				}
			}
			if(dadu==6)comp_turn(noPlayer);
			break;
		case 1:
			step_to_finish=step_left_to_finish(noPlayer,&temp);
			step_to_eat=step_left_to_eat(noPlayer,&temp);
			if(ListPlayer[noPlayer].Info.chance>0){
				if(step_to_eat){
					if(step_to_eat%2==0){
						dadu=shake_dice(2,94,47,noPlayer);
						ListPlayer[noPlayer].Info.chance--;
					}else{
						dadu=shake_dice(3,94,47,noPlayer);
						ListPlayer[noPlayer].Info.chance--;
					}
				}else{
					dadu=shake_dice(1,94,47,noPlayer);
				}
			}else{
				dadu=shake_dice(1,94,47,noPlayer);
			}
			gotoxy(0,60);printf("chance p%d: %d, dadu %d",noPlayer,ListPlayer[noPlayer].Info.chance,dadu);
			Sleep(1000);
			//getch();
			if(dadu==step_to_eat){
				moving(noPlayer,temp,dadu);
			}else
			if(dadu==6&&tdk_ada_pion_di_petak_awal(noPlayer)&&ada_pion_di_home(noPlayer)){
				keluarin_pion(noPlayer);
			}else
			if(dadu==step_to_finish){			//cek jk ada pion d safezone
				int step_to_finish=step_left_to_finish(noPlayer,&temp);	
				moving(noPlayer,temp,dadu);
			}else{
				if(CountNode(ListPlayer[noPlayer].Pion)!=0){
					temp=pion_terjauh(noPlayer);
					moving(noPlayer,temp,dadu);
				}
			}
			if(dadu==6)comp_turn(noPlayer);
			break;
		case 2:
			step_to_finish=step_left_to_finish(noPlayer,&temp);
			step_to_eat=step_left_to_eat(noPlayer,&temp);
			step_to_be_eaten=step_left_to_be_eaten(noPlayer,&temp);
			if(ListPlayer[noPlayer].Info.chance>0){
				if(step_to_eat){
					if(step_to_eat%2==0){
						dadu=shake_dice(2,94,47,noPlayer);
						ListPlayer[noPlayer].Info.chance--;
					}else{
						dadu=shake_dice(3,94,47,noPlayer);
						ListPlayer[noPlayer].Info.chance--;
					}
				}else{
					dadu=shake_dice(1,94,47,noPlayer);
				}
			}else{
				dadu=shake_dice(1,94,47,noPlayer);
			}
			if(ListPlayer[noPlayer].Pion!=NULL) x=ListPlayer[noPlayer].Pion->Position;
			gotoxy(0,60);printf("chance p%d: %d, pos=%d",noPlayer,ListPlayer[noPlayer].Info.chance,x);
			Sleep(1000);
			//getch();
			if(dadu==step_to_eat){
				int step_to_eat=step_left_to_eat(noPlayer,&temp);
				//getch();
				moving(noPlayer,temp,dadu);
			}else
			if(dadu==6&&tdk_ada_pion_di_petak_awal(noPlayer)&&ada_pion_di_home(noPlayer)){//ada pion d home blm fix
				keluarin_pion(noPlayer);
			}else
			if(step_to_be_eaten){
				//getch();
				step_to_be_eaten=step_left_to_be_eaten(noPlayer,&temp);
				moving(noPlayer,temp,dadu);
				//while(1)printf("U");
			}else
			if(dadu==step_to_finish){			//cek jk ada pion d safezone
				int step_to_finish=step_left_to_finish(noPlayer,&temp);	
				moving(noPlayer,temp,dadu);
			}else{
				if(CountNode(ListPlayer[noPlayer].Pion)!=0){
					temp=pion_terjauh(noPlayer);
					moving(noPlayer,temp,dadu);
				}
			}
			if(dadu==6)comp_turn(noPlayer);
			break;
	}
}

Node pion_terjauh(int noPlayer){
	int max=-9,x;
	Node target,temp=ListPlayer[noPlayer].Pion;
	while(temp!=NULL){
		x=temp->Position;if(x<(noPlayer*13+1))x+=52;
		if(max<x&&x<(53+(noPlayer*6))){
			max=x;
			target=temp;
		}
		temp=temp->next;
	}
	return(target);
}

int suicide(int noPlayer,int pos){
	Node temp=ListPlayer[noPlayer].Pion;
	while(temp->next!=NULL){
		if(temp->Position==pos)return(1);
		temp=temp->next;
	}
	return(0);
};

	

void keluarin_pion(int noPlayer){//unclean
	int type_pion;
	scanf("%d",&type_pion);	Lokasi Posisi;
	InsLast(&ListPlayer[noPlayer].Pion,type_pion,13*noPlayer);
	Node temp=ListPlayer[noPlayer].Pion;
	while(temp->next!=NULL)temp=temp->next;
	temp->Position = 13*noPlayer;
	Posisi=posisi_koordinat(temp->Position);
	moving(noPlayer,temp,1);
	home[noPlayer][type_pion].pion = false;
	Print_Awal(noPlayer);
}

int petak_awal_player(int noPlayer){
	int petak_awal;
	switch(noPlayer){
		case 0:
			petak_awal=0;
			break;
		case 1:
			petak_awal=13;
			break;
		case 2:
			petak_awal=26;
			break;
		case 3:
			petak_awal=39;
			break;	
	}
	return(petak_awal);
}

Node SearchNodeToFlee( Node List, int value,int noPlayer)
	{
		int found = 0;
		
		while( List != Nil && !found )
			{
				if(value-List->Position<=6&&value-List->Position>=0&&value<53&&!(value>(noPlayer*13+1)&&List->Position<(noPlayer*13+1)))
					{
						found = 1;
					}
				else
					{
						List = List->next;
					}
			}
		if(found)
			{
				return (List);
			}
		else
			{
				return (Nil);
			}
	}
	
int step_left_to_be_eaten(int noPlayer,Node *temp){		//ngcek 6 petak d belakangny ada lawan gk, kl gk ada,return 0
	Node target;*temp=ListPlayer[noPlayer].Pion;
	int i;
	while(*temp!=NULL){
		for(i=0;i<4;i++){
			if(i==noPlayer)continue;
			target=SearchNodeToFlee(ListPlayer[i].Pion,(*temp)->Position,i);
			if(target!=NULL){
				return(1);
			}
		}
		*temp=(*temp)->next;
	}
	return(0);
}

Node SearchNodeToEat( Node List, int value,int noPlayer)
	{
		int found = 0;
		
		while( List != Nil && !found )
			{
				int x=List->Position;
				if(x-value<0)x+=52;
				if(x-value<=6&&List->Position<53&&!(value<(noPlayer*13+1)&&x>=(noPlayer*13+1))&&value<53)
					{
						found = 1;
						//while(1)printf("a");
					}
				else
					{
						List = List->next;
					}
			}
		if(found)
			{
				return (List);
			}
		else
			{
				return (Nil);
			}
	}
	
int step_left_to_eat(int noPlayer,Node *temp){//ngecek 6 petak d depan pionny ada lawan gk, kl gk ada, return 0
	Node target;*temp=ListPlayer[noPlayer].Pion;
	int i;
	while(*temp!=NULL){
		for(i=0;i<4;i++){
			if(i==noPlayer)continue;
			target=SearchNodeToEat(ListPlayer[i].Pion,(*temp)->Position,noPlayer);
			if(target!=NULL){
				return(target->Position-(*temp)->Position);
			}
		}
		*temp=(*temp)->next;
	}
	return(0);
}

int finish_player(int noPlayer){
	int finish;
	switch(noPlayer){
		case 0:
			finish=57;
			break;
		case 1:
			finish=63;
			break;
		case 2:
			finish=69;
			break;
		case 3:
			finish=75;
			break;
	}
	return(finish);
}

int ada_pion_di_home(int noPlayer){
	Node temp=ListPlayer[noPlayer].Pion;
	if(CountNode(temp)+ListPlayer[noPlayer].Info.finish==4)return(0);else return(1);
}

int step_left_to_finish(int noPlayer,Node *temp){//ngcek butuh nilai dadu brp buat finish
	int finish=finish_player(noPlayer),safe_zone=finish_player(noPlayer)-5;
	*temp=ListPlayer[noPlayer].Pion;
	while(*temp!=NULL){
		if((*temp)->Position>=safe_zone){
			return(finish-(*temp)->Position);
		}
		*temp=(*temp)->next;
	}
	return(0);
}

int tdk_ada_pion_di_petak_awal(int noPlayer){//ngcek d petak awal ada pion gk
	Node temp;int petak_awal=petak_awal_player(noPlayer);
	temp=ListPlayer[noPlayer].Pion;
	if(temp==NULL)
		return(1);
	else{
		temp=SearchNodebyPos(ListPlayer[noPlayer].Pion,petak_awal+1);
		if(temp==NULL)
			return(1);
		else
			return(0);
	}
}

int tdk_ada_pion_di_main_track(int noPlayer){
	Node temp=ListPlayer[noPlayer].Pion;
	while(temp!=NULL){
		if(temp->Position<53)return(0);
		temp=temp->next;
	}
	return(1);
}
