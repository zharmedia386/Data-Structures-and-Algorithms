/* File :  list1.c   					*/
/* Desk :  body list  berkait dgn representasi fisik    */
/*         pointer; 					*/
/* 	   Representasi address dgn pointer 		*/
/*	   infotype adalah integer			*/
/* Oleh :  ANI RAHMANI / 23501007 	  		*/
/* Tgl  :  25/10/01					*/	 

#ifndef list_C
#define list_C

#include "boolean.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

boolean ListEmpty(List L){
	return (First(L) == Nil);
}

void CreateList(List *L){
	First(*L) = Nil;
}

address Alokasi(infotype X){
	address P;
	P = (address)malloc(sizeof(ElmtList));
	if(P != Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi(address *P){
	Next(*P) = Nil;
	free(*P);
}

address Search1(List L, infotype X){
	address P = First(L);
	boolean found = false;
	
	while((P != Nil) && (!found)){
		if(Info(P).nama == X.nama){
			found = true;
		}
		else{
			P = Next(P);
		}
	}
	return P;
}

address Search2(List L, infotype X){
	address P;
	if(First(L) != Nil){
		return Nil;
	}
	else{
		P = First(L);
		while((Next(P) != Nil) && (Info(P).nama != X.nama)){
			P = Next(P);
		}
		if(Info(P).nama == X.nama){
			return P;
		}
		else{
			return Nil;
		}
	}
	return P;
}

boolean FSearch(List L, address P){
	address PTemp = First(L);
	boolean found = false;
	
	while((PTemp != Nil) && (!found)){
		if(PTemp == P){
			found = true;
		}
		else{
			PTemp = Next(PTemp);
		}
	}
	return found;
}

address SeachPrec(List L, infotype X){
	address Prec;
	address P = First(L);
	
	if(Next(P) == Nil){
		Prec = Nil;
	}
	else{
		while((Next(P) != Nil) && (Info(P).nama != X.nama)){
			Prec = P;
			P = Next(P);
		}
		if(Info(P).nama == X.nama){
			return Prec;
		}
		else{
			return Nil;
		} 
	}
}

/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(List *L, address P){
	Next(P)	 = First(*L);
	First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast(List *L, address P){
	address Last;
	if(ListEmpty(*L)){
		InsertFirst(&(*L),P);
	}
	else{
		Last = First(*L);
		while(Next(Last) != Nil){
			Last = Next(Last);
		}
		Next(Last) = P;
	}
}

/* ** PRIMITIF BERDASARKAN NILAI ** */

void InsVFirst(List *L, infotype X){
	address P = Alokasi(X);
	if(P != Nil){
		InsertFirst(&(*L),P);
	}
}

void InsVLast(List *L,infotype X){
	address P = Alokasi(X);
	if(P != Nil){
		InsertLast(&(*L),P);
	}
}

/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst(List *L, address *P){
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP(List *L, infotype X){
	address P = First(*L);
	
	while((Next(P) != Nil) && (Info(P).nama != X.nama)){
		P = Next(P);
	}
	
	if(Info(P).nama != X.nama){
		Dealokasi(&P);
	}
}

void DelLast(List *L, address *P){
	address Last, PrecLast;
	Last = First(*L);
	if(Next(Last) == Nil){
		DelFirst(&(*L),&(Last));
	}
	else{
		PrecLast = Nil;
		while(Next(Last) != Nil){
			PrecLast = Last;
			Last = Next(Last);
		}
		*P = Last;
		Next(PrecLast) = Nil;
	}
}

void DelAfter(List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}

/* *** Penghapusan Elemen  ***  */
void DelVFirst(List *L, infotype *X){
	address P;
	DelFirst(&(*L),&P);
	*X = Info(P);
	Dealokasi(&P);
}

void DelVLast(List *L, infotype *X){
	address P;
	DelLast(&(*L),&P);
	*X = Info(P);
	Dealokasi(&P);
}

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L){
	int i;
	address P = First(L);
	if(P == Nil){
		printf("List Kosong !'n'");
	}
	else{
		do{
			PrintMenu(Info(P));
			P = Next(P);
			i++;
		}while(P != Nil);
	}
	printf("\n");
}

void PrintFormat(List L)
{
int i;	
  address P=First(L);
  if( P==Nil) { 
  	  printf("\nPendaftar Masih Kosong!\n");
  } 
  else { 
	    do 
		{ 
			printf("%s (", P->info.nama);
			PrintTimeFormat(P->info.jam);
			printf("-%s)\n", P->info.kategori);
			P=Next(P);
			i++;
	    } while(P!=Nil); 
	 }
}

void PrintListByCategory(List L, char *p)
{
	address P=First(L);
	if( P==Nil) 
	{ 
  	printf("\nPendaftar Masih Kosong!\n");
  	} 
	else 
	{ 
		do 
		{ 
			if(strcmp(P->info.kategori, p) == 0)
			{
				printf("%s (", P->info.nama);
				PrintTimeFormat(P->info.jam);
				printf("-%s)", P->info.kategori);
				printf(" (Sesi ");
				switch(P->info.sesi)
				{
					case 1 :printf("I) (Pagi)\n"); break;
					case 2 :printf("II) (Siang)\n"); break;
					case 3 :printf("III) (Sore)\n"); break;
				}
			}
			P=Next(P);
	    } while(P!=Nil); 
	 }
}

int NbElmt(List L)
{ /* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */
  address P;
  int NbEl=0;
  if(ListEmpty(L)){
 	return 0;
  } else { /* Tidak kosong */
	      P=First(L);
       	      do {
		    NbEl++;  
		    P=Next(P);  
	      }while(P!=Nil);
  	}
       return NbEl;		      
}

/******************************************************/
/***   		PROSES TERHADAP LIST		    ***/
/******************************************************/
void DelAll(List *L)
{ /* Delete semua elemen list, dan alamat elemen di-dealokasi */
   infotype X;
   while(!ListEmpty(*L)) {
	  DelVFirst(&(*L),&X);
   } /* kosong */
}

void SortListByCategory(List *L)
{
	address next;	
	address current;
	menu temp;
	
	if(ListEmpty(*L))
		return;
	
	current = L->First; 
	while(current!=Nil) 
	{ 
		next=current->next;
		while(next != Nil)
		{
			if(strcmp(current->info.kategori, next->info.kategori) < 0) 
			{
				temp = current->info;
				current->info = next->info;
				next->info= temp;
			}
			next = next->next;
		}
		current = current->next;		
	}
}

void SortListByTime(List *L)
{
	address next;	
	address current;
	menu temp;
	
	if(ListEmpty(*L))
		return;
	
	current = L->First; 
	while(current!=Nil) 
	{ 
		next=current->next;
		while(next != Nil)
		{
			if(CompareTime(current->info.jam, next->info.jam) > 0) 
			{
				temp = current->info;
				current->info = next->info;
				next->info= temp;
			}else if(CompareTime(current->info.jam, next->info.jam) == 0)
			{
				if(strcmp(current->info.kategori, next->info.kategori) < 0)
				{
					temp = current->info;
					current->info = next->info;
					next->info= temp;
				}
			}
			
			
			next = next->next;
		}
		current = current->next;		
	}
}

void CpAlokList(List Lin, List  *Lout)
{ /* I.S   : Lin sembarang				    */
  /* F.S   : Jika semua alokasi berhasil, maka Lout berisi  */
  /*         hasil copy Lin. Jika ada alokasi yang  gagal   */
  /*         maka Lout=Nil, dan semua elemen yang terlanjur */
  /*	   dialokasi, didealokasi dengan melakukan alokasi  */
  /*	   elemen. Lout adalah List kosong, jika ada alokasi*/
  /*	   elemen yang gagal				    */
    	
	/* Kamus */
	address P,Pout;
	infotype X;
	
	/* ALgoritma */
	if(!ListEmpty(Lin)) { /* tidak kosong */
	   
		CreateList(&(*Lout));
		P=First(Lin);
		do 
		{  
			X=Info(P);
			Pout=Alokasi(X);
			if(Pout!=Nil) {  /* Alokasi berhasil */
				InsertLast(&(*Lout),Pout);
				P=Next(P);
			} else { /* Alokasi Pout gagal */
			     DelAll(&(*Lout));
			     First(*Lout)=Nil;
			     break;  
		    }
	    } while	(P != Nil);   
	}  
}

#endif
