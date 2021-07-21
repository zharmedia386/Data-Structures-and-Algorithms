#ifndef binarytree_h
#define binarytree_h
#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Nil 0
#define MaxEl 15

//#define Info(BT) (BT).info
//#define Left(BT) (BT).left 
//#define Right(BT) (BT).right 
//#define Parent(BT) (BT).parent 

//#define Info
//#define InfoLeft(BT) (BT).Data[(BT).Left] 
//#define InfoRight(BT) (BT).Data[(BT).Right] 

// Nil adalah Binary Tree dengan elemen kosong 
// karena indeks dalam bahasa c dimulai 0 maka tabel dengan indeks 0 tidak dipakai

// Jika BT adalah Binary Tree maka akses elemen :
// BT.T[BT.left] untuk mengakses elemen anak pertama
// BT.T[BT.right] untuk mengakses elemen anak kedua
// BT.left adalah alamat elemen anak pertama
// BT.right adalah alamat elemen anak kedua

// Definisi akses dengan selektor : set dan get

//------------------- ABSTRACT DATA TYPE BINARY TREE -------------------------------//
// Binary Tree adalah .
// Defnisi Binary Tree :
/* Queue kosong : right = Nil, left = Nil, 
	Elemen yang dipakai menyimpan nilai stack T[1]...T[MaxEl]
	Jika Q adalah Queue maka akses elemen
	Q.T[Q.Front] untuk mengakses elemen pertama
	Q.T[Q.Rear] untuk mengakses elemen terakhir
	Q.Front adalah alamat elemen pertama
	Q.Rear adalah alamat elemen terakhir			
*/

typedef int address; //type data bentukan “address” dalam bentuk integer untuk menyimpan indeks
typedef int infotype; //type data bentukan “infotype” dalam bentuk integer untuk menyimpan nilai
typedef struct {
	infotype info; //Menyimpan Nilai
	address left; //address penunjuk anak pertama (indeks)
	address right; //address penunjuk anak kedua (indeks)
	address parent; //address penunjuk orang tua (indeks)
}binaryTree;
//----------------------Prototype ADT Queue Circular------------------------//

//---------- Konstruktor --------------//
/* I.S : Q terdefinisi tidak diketahui isinya
   F.S : Q diinisialisasi dengan Front(Q)=nil, Rear(Q)=nil
*/
void createBinaryTree(binaryTree BT[MaxEl+1]);

//---------- Operasi pengecekan --------------//
/* Mengirim true jika Queue kosong: lihat definisi di atas */
boolean isBinaryTreeEmpty(binaryTree BT[MaxEl+1]);

/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu Rear berada MaxEl*/
boolean isBinaryTreeFull(binaryTree BT[MaxEl+1]);

//---------- Operasi Penambahan dan Pengurangan --------------//
/* Proses L Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* Prekondisi : Queue dipastikan tidak penuh, yaitu Rear != MaxEl */
/* I.S. : Q mungkin kosong atau Q mungkin berisi antrian tidak penuh
   F.S : X menjadi elemen pada REAR yang baru, REAR "maju"
         Jika Rear(Q)=MaxE1+1 maka tidak bisa melakukan penambahan
*/

void insert(binaryTree BT[MaxEl+1], infotype x, int *checkpoint);
void insertLeft(binaryTree BT[MaxEl+1], int posisi, int x, int *checkpoint);
void insertRight(binaryTree BT[MaxEl+1], int posisi, int x, int *checkpoint);
/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S : Q mungkin kosong atau Q mungkin berisi antrian 
   F.S : Q berkurang satu elemen didepan disimpan pada X
         Front(Q) "tetap" 
		  ketika Front(Q) < Rear, maka ada pergeseran elemen setelahnya selama masih ada antrian
          ketika Front = Rear, maka Front = Nil dan Rear = Nil
*/
//void deQueue(Queue *Q, infotype *x);

//---------- Operasi I/O --------------//
/* Menampilkan antrian ke layar dengan mengakses setiap info mulai dari Front s.d. rear */
/* I.S : mungkin kosong atau Q mungkin berisi antrian
   F.S : Jika Queue tidak kosong, semua info yang disimpan pada elemen queue diprint. 
*/
void printBinaryTreeInfo(binaryTree BT[MaxEl+1]);

//---------- Operasi Pendukung --------------//
/* Mengirimkan banyaknya elemen queue melalui taging pada Front & Rear. Mengirimkan 0 jika Q kosong 
   Perhitungannya : Rear - Front + 1, karena Front tidak mungkin lebih besar dari Rear
*/ 
int NBElmt(binaryTree BT[MaxEl+1]);
//Mencari element berdasarkan data
//Mencari child
//Mencari parent
#endif
