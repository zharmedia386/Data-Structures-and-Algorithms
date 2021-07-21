/* Program		: circle.c
Deskripsi 		: Spesifikasi ADTCircle
Dibuat oleh    	: Muhammad Azhar Alauddin
Tanggal     	: 13 April 2021
Teks Editor     : DevC++
---------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

/*Prototype*/

/*KELOMPOK CREATOR */

void MakeCircle(Circle *C, POINT *P, float r){ /*Prosedur untuk membuat Circle dengan nilai dari user*/
	C->P = *P;
	C->r = r;
}

Circle CreateCircle (int XX, int YY, float R){ /*Fungsi untuk menghasilkan sebuah Circle berdasarkan nilai-nilai dari user*/
	Circle *C = (Circle*)malloc(sizeof(Circle));
	POINT P = CreatePoint(XX,YY);
	MakeCircle(C,&P,R);
	return *C;
}


/*KELOMPOK VALIDASI*/

/*KELOMPOK Get/Set */

float GetRadius(Circle C){ /* mengembalikan nilai radius dari sebuah Circle */
	return C.r;
}

void SetRadius(Circle *C1, float R){ /* Mengubah nilai Radius sebuah Circle */
	C1->r = R;
}

/*KELOMPOK PRINT/CETAK*/
void PrintCircle(Circle C){ /* Menampilkan Circle : Titik Pusat & Radius */
	PrintPoint(C.P);
	printf("r=%.2f",C.r);
}

/*KELOMPOK LAIN */
float Area(Circle C1){ /* menghasilkan nilai Luas dari Circle C1*/
	return C1.r*C1.r*3.14159265358979323846;
}

float Circumf(Circle C1){ /* menghasilkan nilai Keliling dari Circle */
	return C1.r*2*3.14159265358979323846;
}

boolean CompareCircle(Circle C1, Circle C2){ /* menghasilkan True jika Luas C1 = C2, Gunakan fungsi Luas */
	return (Area(C1) == Area(C2)) ? true : false;
}
/* menghasilkan True jika Luas C1 = C2, Gunakan fungsi Luas */

Circle CopyCircle(Circle C1){ /*Mengembalikan sebuah Circle */
	Circle *C2;
	C2->P.x = C1.P.x;
	C2->P.y = C1.P.y;
	C2->r = C1.r;
	return *C2;
}

