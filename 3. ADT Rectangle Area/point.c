// Program     : Point.c
// Deskripsi   : Body ADT POINT 
// oleh        : Ani Rahmani
// Tgl/Version : 22 April 2021

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

/*KELOMPOK CREATOR */

void MakePoint(POINT *P, int XX, int YY)
{/*Prosedur untuk membuat POINT dengan nilai dari user*/
	(*P).x=XX;
	(*P).y=YY;
}

POINT CreatePoint (int XX, int YY)
//Fungsi untuk menghasilkan sebuah POINT berdasarkan nilai-nilai dari user
{
  POINT P;

  P.x = XX;
  P.y = YY;

  return P;
}


/*KELOMPOK VALIDASI*/
//Asumsi : posisi point bebas, artinya tidak perlu ada validasi


/* KELOMPOK GET / SET */

int GetX(POINT P) 
{ /*Mengembalikan nilai x dari sebuah POINT */
 return P.x;

}

void SetX(POINT *P, int XX)
{ /* Mengubah nilai X dari sebuah POINT */
  (*P).x = XX;
}

int GetY(POINT P)
{ /*Mengembalikan nilai y dari sebuah POINT */
 return P.y;
}

void SetY(POINT *P, int YY)
{ /* Mengubah nilai Y dari sebuah POINT */
  (*P).y = YY;
}

void ReSet(POINT *P)
{ /* Mengubah koordinat sebuah POINT menjadi 0,0 */
  (*P).x =0;
  (*P).y =0;
}


/*KELOMPOK PRINT/CETAK*/
void PrintPoint(POINT P)
{ /* Menampilkan POINT */
  printf("(%d,%d)",P.x, P.y);

  }

/*KELOMPOK LAIN */

int Kuadran(POINT P)
{ /* menghasilkan kuadran dari POINT P*/
  int k;

  if(P.x > 0)
	  if(P.y > 0)
		  k=1;
	  else
		  k=4;
  else if (P.y > 0)
			 k=2;
		  else
			 k=3;

		 return k;
  }

boolean IsOnSumbuX(POINT P)
{ /* Mengirimkan True jika P ada di sumbu X  */
  return (P.y==0);

  }
boolean IsOnSumbuY(POINT P)
{/* Mengirimkan True jika P ada di sumbu Y  */
  return (P.x==0);
 }

boolean IsOrigin(POINT P)
{ /* Mengirimkan True jika P ada di titik pusat */
  return ((P.x==0) && (P.y==0));

}
void NextX(POINT *PP)
{ /* Menggeser PP, 1 koordinat ke kanan*/
  (*PP).x++;

  }

void NextX_N(POINT *PP, int N)
{ /* Menggeser P, sejauh N koordinat ke kanan*/
	 (*PP).x=(*PP).x + N;
  }

void PrevX(POINT *P)
{ /* Menggeser P 1 koordinat ke kiri*/
(*P).x--;
}

void PrevX_N(POINT *P, int N){
/* Menggeser P, sejauh N koordinat ke kiri */
  (*P).x=(*P).x - N;
}

/*MENGHITUNG JARAK DUA POINT */
int Jarak (POINT P1, POINT P2)
{/*Menghasilkan jarak P1 dan P2 */
  return sqrt((P1.x-P2.x)*(P1.x-P2.x) +(P1.y-P2.y) * (P1.y-P2.y));
}

