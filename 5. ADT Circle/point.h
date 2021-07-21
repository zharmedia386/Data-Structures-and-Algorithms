/* Program		  : point.h
Deskripsi 		  : Spesifikasi ADTPoint
Dibuat oleh    	  : Ani Rahmani
Dimodifikasi oleh : Muhammad Azhar Alauddin
Tanggal     	  : 13 April 2021
Teks Editor       : DevC++
---------------------------------------------------------------*/
#include "boolean.h"
#ifndef  POINT_H
#define  POINT_H


/* definisi type data */
typedef  struct
  {  int  x;
		int y;
} POINT; // type POINT


/*  Prototype */

/*KELOMPOK CREATOR */

void MakePoint(POINT *P, int XX, int YY);
/*Prosedur untuk membuat POINT dengan nilai dari user*/

POINT CreatePoint (int XX, int YY);
/*Fungsi untuk menghasilkan sebuah POINT berdasarkan nilai-nilai dari user*/

/*KELOMPOK VALIDASI*/

/*KELOMPOK PRINT/CETAK*/
void PrintPoint(POINT P);
/* Menampilkan POINT */

/* KELOMPOK GET / SET */

int GetX(POINT P);
/*Mengembalikan nilai x dari sebuah POINT */

void SetX(POINT *P, int newX);
/* Mengubah nilai X dari sebuah POINT */

int GetY(POINT P);
/*Mengembalikan nilai y dari sebuah POINT */

void SetY(POINT *P, int newY);
/* Mengubah nilai Y dari sebuah POINT */

void ReSet(POINT *P);
/* Mengubah koordinat sebuah POINT menjadi 0,0 */


/*KELOMPOK LAIN */
int Kuadran(POINT P);
/* menghasilkan kuadran dari POINT P*/

boolean IsOnSumbuX(POINT P);
/* Mengirimkan True jika P ada di sumbu X  */

boolean IsOnSumbuY(POINT P);
/* Mengirimkan True jika P ada di sumbu Y  */

boolean IsOrigin(POINT P);
/* Mengirimkan True jika P ada di titik pusat */

void NextX(POINT *PP);
/* Menggeser P 1 koordinat ke kanan*/

void NextX_N(POINT *PP, int N);
/* Menggeser P, sejauh N koordinat ke kanan*/

void PrevX(POINT *P);
/* Menggeser P 1 koordinat ke kiri*/

void PrevX_N(POINT *P, int N);
/* Menggeser P, sejauh N koordinat ke kiri */


/*MENGHITUNG JARAK DUA POINT */
int Jarak (POINT P1, POINT P2);
/*Menghasilkan jarak P1 dan P2 */


#endif


