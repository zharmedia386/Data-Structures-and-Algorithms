/* Program		: circle.h
Deskripsi 		: Spesifikasi ADTCircle
Dibuat oleh    	: Muhammad Azhar Alauddin
Tanggal     	: 13 April 2021
Teks Editor     : DevC++
---------------------------------------------------------------*/

#include "boolean.h"
#include "Point.h"

#ifndef  CIRCLE_H
#define  CIRCLE_H


/* definisi type data */
typedef  struct
  {  POINT  P;
     float  r;
} Circle; // type Circle


/*  Prototype */

/*KELOMPOK CREATOR */

void MakeCircle(Circle *C,POINT *P, float r);
/*Prosedur untuk membuat Circle dengan nilai dari user*/

Circle CreateCircle (int XX, int YY, float R);
/*Fungsi untuk menghasilkan sebuah Circle berdasarkan nilai-nilai dari user*/

/*KELOMPOK VALIDASI*/

/*KELOMPOK Get/Set */

float GetRadius(Circle C);
/* mengembalikan nilai radius dari sebuah Circle */

void SetRadius(Circle *C1, float R);
/* Mengubah nilai Radius sebuah Circle */

/*KELOMPOK PRINT/CETAK*/
void PrintCircle(Circle C);
/* Menampilkan Circle : Titik Pusat & Radius */

/*KELOMPOK LAIN */
float Area(Circle C1);
/* menghasilkan nilai Luas dari Circle C1*/

float Circumf(Circle C1);
/* menghasilkan nilai Keliling dari Circle */

boolean CompareCircle(Circle C1, Circle C2);
/* menghasilkan True jika Luas C1 = C2, Gunakan fungsi Luas */

Circle CopyCircle(Circle C1);
/*Mengembalikan sebuah Circle */


#endif


