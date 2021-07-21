/*
 *	File          : stack.c
 *	Deskripsi     : Body file dari ADT Stack [Linked List]
 */

#ifndef stack_C
#define stack_C

#include "stack.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>

//Kamus Global

/* Prototype ADT Stack [Linked List] */

/* {Konstruktor pembentuk Stack} */
void CreateStack(Stack *s){
/* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/
	
	//Kamus
	
	//Algoritma
	top(*s) = nil;
}

/* {Opeasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
address1 Alokasi1(infotype1 x){
//Mengirim sebuah elemen stack dalam bentuk address

	//Kamus
	tabStack *p;
	
	//Algoritma
	p = (tabStack*)malloc(sizeof(tabStack));
	if(p != nil){
		info(p) = x;
		p->prev = nil;
		return p;
	} else {
		return nil;
	}
}

void Dealokasi1(address1 p){
/* I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   		 Melakukan dealokasi / pengenmbalian address P ke sistem
*/

	//Kamus
	
	//Algoritma
	free(p);
}

/* {Kelompok Interaksi Dengan I/O Device} */
void Push(Stack *s, infotype1 x){
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/
	
	//Kamus
	//tabstack *p;
	address1 p,q;
	
	//Algoritma
	p = Alokasi1(x);
	if (isStackEmpty(*s)) { // Stack Kosong
		top(*s) = p;
	} else { // Stack tidak kosong
		prev(p) = top(*s);
		top(*s) = p;
	}
}

void Pop(Stack *s, infotype1 *x){
/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/

	//Kamus
	address1 pTOP,tmp2;
	int out;
	
	//Algoritma
	pTOP = top(*s);
	*x = info(pTOP);
	if(prev(pTOP) == nil){ // hanya ada 1 elemen
		top(*s) = nil;
	} else { // lebih dari satu elemen
		top(*s) = prev(pTOP);
		prev(pTOP) = nil;
	}
}

dokumen Peek(Stack S){
	return S.top->info;
}

void PrintStack(Stack s){
/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/
	int i = 1;

	//Kamus
	tabStack *p, *q;
	
	//Algoritma
	if(!isStackEmpty(s)){	
		p = top(s);	
		while (p != nil){
			printf("%d. %s\n", i, info(p).nama);
			p = prev(p);
			i++;
		}
	}
	else {
		printf("[Tidak Ada]\n");
	}
}

/* {Kelompok Operasi Cek elemen kosong} */
boolean isStackEmpty(Stack s){
//Mengirimkan true jika stack kosong, false jika tidak
	
	//Kamus
	
	//ALgoritma
	if(top(s) == nil){
		return true;
	} else {
		return false;
	}	
}	

void ReadRegistrasi(dokumen *data){
	fflush(stdin);
	
	printf("No KTP                       : "); 
	scanf("%s", &data->noKTP);
	fflush(stdin); // clear last char in stdin
	
	printf("Nama                         : "); 
	scanf("%[^\n]c", &data->nama);
	
	printf("Kategori                     : "); 
	scanf("%s", &data->kategori);
	
	if(stricmp(data->kategori,"Lansia") == 0) {
		fflush(stdin);
		printf("Fotocopy KTP                 : [Y/N] ");
		scanf("%c",&data->FotoCopyKTP); fflush(stdin);
		printf("Kartu Keluarga               : [Y/N] ");
		scanf("%c",&data->KartuKeluarga);
	}
	else{
		fflush(stdin);
		printf("Fotocopy KTP                 : [Y/N] ");
		scanf("%c",&data->FotoCopyKTP); fflush(stdin);
		printf("Surat Pengantar              : [Y/N] ");
		scanf("%c",&data->SuratPengantar);
	}
}

#endif
