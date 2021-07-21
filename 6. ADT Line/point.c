/* Program		  : point.c
Deskripsi 		  : Spesifikasi ADTPoint
Dibuat oleh    	  : Ani Rahmani
Dimodifikasi oleh : Muhammad Azhar Alauddin
Tanggal     	  : 13 April 2021
Teks Editor       : DevC++
---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

/*KELOMPOK CREATOR */

void MakePoint(POINT *P, int XX, int YY){ /*Prosedur untuk membuat POINT dengan nilai dari user*/
	P->x = XX;
	P->y = YY;
}

POINT CreatePoint (int XX, int YY){  /*Fungsi untuk menghasilkan sebuah POINT berdasarkan nilai-nilai dari user*/
	POINT* result = (POINT*)malloc(sizeof(POINT));
	result->x = XX;
	result->y = YY;
	return *result;
}

/*KELOMPOK VALIDASI*/

/*KELOMPOK PRINT/CETAK*/
void PrintPoint(POINT P){ /* Menampilkan POINT */
	printf("%d %d\n", P.x, P.y);
}

/* KELOMPOK GET / SET */

int GetX(POINT P){ /*Mengembalikan nilai x dari sebuah POINT */
	return P.x;
}

void SetX(POINT *P, int newX){ /* Mengubah nilai X dari sebuah POINT */
	P->x = newX;
}

int GetY(POINT P){ /*Mengembalikan nilai y dari sebuah POINT */
	return P.y;
}

void SetY(POINT *P, int newY){ /* Mengubah nilai Y dari sebuah POINT */
	P->y = newY;
}

void ReSet(POINT *P){ /* Mengubah koordinat sebuah POINT menjadi 0,0 */
	P->x = 0;
	P->y = 0;
}


/*KELOMPOK LAIN */
int Kuadran(POINT P){ /* menghasilkan kuadran dari POINT P*/
	if(P.y >= 0)
		return (P.x >= 0) ? 1 : 2;
	return (P.x >= 0) ? 4 : 3;
}

boolean IsOnSumbuX(POINT P){ /* Mengirimkan True jika P ada di sumbu X  */
	return (!P.y) ? true : false;
}

boolean IsOnSumbuY(POINT P){ /* Mengirimkan True jika P ada di sumbu Y  */
	return (!P.x) ? true : false;
}

boolean IsOrigin(POINT P){ /* Mengirimkan True jika P ada di titik pusat */
	return (!P.x && !P.y) ? true : false;
}

void NextX(POINT *PP){  /* Menggeser P 1 koordinat ke kanan*/
	PP->x++;
}

void NextX_N(POINT *PP, int N){ /* Menggeser P, sejauh N koordinat ke kanan*/
	PP->x += N;
}

void PrevX(POINT *P){ /* Menggeser P 1 koordinat ke kiri*/
	P->x--;
}

void PrevX_N(POINT *P, int N){ /* Menggeser P, sejauh N koordinat ke kiri */
	P->x -= N;
}


/*MENGHITUNG JARAK DUA POINT */
int Jarak (POINT P1, POINT P2){ /*Menghasilkan jarak P1 dan P2 */
	int x = abs(P2.x-P1.x);
	int y = abs(P2.y-P1.y);
	return x+y;
}



