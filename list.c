#include "list.h"

//ini buat list

void CreateList( Node *List)
	{
		*List = Nil;
	}
	
Node Alokasi( int value , int posisi)
	{
		Node P;
		P = (Node) malloc(sizeof (ElmntList));
		if(P != Nil)
			{
				P->type = value;
				P->Position = posisi;
				P->before = posisi;
				P->next = Nil;
			}
		return (P);
	}

void Dealokasi( Node P)
	{
		if( P != Nil)
			{
				P->next = Nil;
				free(P);
			}
	}

Node SearchNode( Node List, int value)
	{
		boolean found = false;
		
		while( List != Nil && !found )
			{
				if(List->type == value)
					{
						found = true;
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

Node SearchPrevNode( Node List, int value)
	{
		Node Prev;
		Prev = Nil;
		int found = false;
		if(List != Nil)
			{
				while( List != Nil && found == false )
					{
						if(List->type == value)
							{
								found = true;
							}
						Prev = List;
						List = List->next;
					}
			}
		
		if(found == true)
			{
				return (Prev);
			}
		else
			{
				return (Nil);
			}
	}


void InsLast( Node *List, int value, int posisi)
	{
		Node P;
		P = Alokasi(value,posisi);
		if( P != Nil )
			{
				InsertLast(&(*List), P);
			}
	}
	
void InsertLast( Node *List, Node P)
	{
		Node Last;
		if(*List != Nil)
			{
				Last = *List;
				while(Last->next != Nil)
					{
						Last = Last->next;
					}
				Last->next = P;
			}
		else
			{
				*List = P;
			}
	}
	
int CountNode( Node List)
	{
		int i = 0;
		while(List != Nil)
			{
				i++;
				List = List->next;
			}
		return i;
	}
	
int DelP( Node *List, int value)
	{
		int type;
		Node Prev,P;
		Prev = SearchPrevNode( *List, value);
		if(Prev == *List)
			{
				P = *List;
				*List = Prev->next;
			}
		else
			{
				P = Prev->next;
				Prev->next = P->next;
			}
		P->next = Nil;
		type = P->type;
		Dealokasi(P);
		return type;
	}
