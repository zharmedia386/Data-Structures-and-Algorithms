#include "binarytree.h"
#include <stdio.h>
#include <conio.h>

//----------------------Prototype ADT Queue Circular------------------------//
void createBinaryTree(binaryTree BT[MaxEl+1]){
	int i;
	for(i=0; i<MaxEl+2; i++){
		BT[i].info = Nil;
	}
}

//---------- Operasi pengecekan --------------//
/* Mengirim true jika Queue kosong: lihat definisi di atas */
boolean isBinaryTreeEmpty(binaryTree BT[MaxEl+1]){
	if (BT[1].info == Nil){
		return true;
	}else{
		return false;
	}
}

/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu Rear berada MaxEl*/
boolean isBinaryTreeFull(binaryTree BT[MaxEl+1]){
	if(NBElmt(BT) == MaxEl) {
		return true;
	} else {
		return false;
	}
}

//---------- Operasi Penambahan dan Pengurangan --------------//
/* Proses L Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* Prekondisi : Queue dipastikan tidak penuh, yaitu Rear != MaxEl */
/* I.S. : Q mungkin kosong atau Q mungkin berisi antrian tidak penuh
   F.S : X menjadi elemen pada REAR yang baru, REAR "maju"
         Jika Rear(Q)=MaxE1+1 maka tidak bisa melakukan penambahan
*/
void insert(binaryTree BT[MaxEl+1], infotype x, int *checkpoint){
	int posisi = 1;
	if(!isBinaryTreeFull(BT)) {
		if (isBinaryTreeEmpty(BT)) {
			BT[1].info = x;
 			BT[1].left = Nil;
			BT[1].right = Nil;
			BT[1].parent = Nil;
			*checkpoint=*checkpoint+1;
		}else if(x < BT[posisi].info){
			insertLeft(BT, posisi, x, checkpoint);
		}else if(x >= BT[posisi].info){
			insertRight(BT, posisi, x, checkpoint);
		}
	}else{
		printf("Binary Tree Penuh");
	}
}

void insertLeft(binaryTree BT[MaxEl+1], int posisi, int x, int *checkpoint){
	if(BT[posisi].left == Nil){
		BT[*checkpoint+1].info = x;
 		BT[*checkpoint+1].left = Nil;
		BT[*checkpoint+1].right = Nil;
		BT[*checkpoint+1].parent = posisi;
		BT[posisi].left = *checkpoint+1;
		*checkpoint=*checkpoint+1;
	}else if(x < BT[BT[posisi].left].info){
		posisi = BT[posisi].left;
		insertLeft(BT, posisi, x, checkpoint);
	}else if(x >= BT[BT[posisi].left].info){
		posisi = BT[posisi].left;
		insertRight(BT, posisi, x, checkpoint);
	}
}

void insertRight(binaryTree BT[MaxEl+1], int posisi, int x, int *checkpoint){
	if(BT[posisi].right == Nil){
		BT[*checkpoint+1].info = x;
 		BT[*checkpoint+1].left = Nil;
		BT[*checkpoint+1].right = Nil;
		BT[*checkpoint+1].parent = posisi;
		BT[posisi].right = *checkpoint+1;
		*checkpoint=*checkpoint+1;
	}else if(x < BT[BT[posisi].right].info){
		posisi = BT[posisi].right;
		insertLeft(BT, posisi, x, checkpoint);
	}else if(x >= BT[BT[posisi].right].info){
		posisi = BT[posisi].right;
		insertRight(BT, posisi, x, checkpoint);
	}
}

void printBinaryTreeInfo(binaryTree BT[MaxEl+1]){
	int i;
	if(!isBinaryTreeEmpty(BT)){
		for(i=0; i<MaxEl+1; i++){
			printf("%d ", BT[i].info);
		}
	}
}

//---------- Operasi Pendukung --------------//
/* Mengirimkan banyaknya elemen queue melalui taging pada Front & Rear. Mengirimkan 0 jika Q kosong 
   Perhitungannya : Rear - Front + 1, karena Front tidak mungkin lebih besar dari Rear
*/ 
int NBElmt(binaryTree BT[MaxEl+1]){
	int i, result;
	result = 0;
	if(!isBinaryTreeEmpty(BT)){
		for(i=0; i<MaxEl+1; i++){
			if(BT[i].info!=0){
				result++;
			}
		}
	}
	return result;
} 

