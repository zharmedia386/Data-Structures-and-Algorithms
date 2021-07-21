/*
 *	File          : stack.h
 *	Deskripsi     : Header file dari ADT Stack [Linked List]
 */

#ifndef _stack_H
#define _stack_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define nil NULL
#define info(p) (p)->info
#define prev(p) p->prev

#define top(s) (s).top

/* Definisi Type Bentukan ADT Stack [Linked List] */
typedef struct{
	char NamaPengirim[100];
	char AlamatPengirim[100];
	char NoPengirim[50];
	char NamaPenerima[100];
	char AlamatPenerima[100];
	char NoPenerima[50];
}dokumen;

typedef dokumen infotype1;

typedef struct telmstack *address1;

typedef struct telmstack{
	infotype1 info;
	address1 prev;
}tabStack;

typedef struct{
	address1 top;
}Stack;

/* Prototype ADT Stack [Linked List] */
/* {Konstruktor pembentuk Stack} */
void CreateStack(Stack *s);
/* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/

/* {Opeasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
address1 Alokasi1(infotype1 x);
//Mengirim sebuah elemen stack dalam bentuk address

void Dealokasi1(address1 p);
/* I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   		 Melakukan dealokasi / pengenmbalian address P ke sistem
*/

/* {Kelompok Interaksi Dengan I/O Device} */
void Push(Stack *s, infotype1 x);
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/

void Pop(Stack *s, infotype1 *x);
/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/

dokumen Peek(Stack S);

void PrintStack(Stack s);
/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/

/* {Kelompok Operasi Cek elemen kosong} */
boolean isStackEmpty(Stack s);
//Mengirimkan true jika stack kosong, false jika tidak

void ReadPaket(dokumen *data);

#endif
