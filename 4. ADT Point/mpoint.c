/* Program		: mpoint.c
Deskripsi 		: Main Driver dari point.c
Dibuat oleh    	: Muhammad Azhar ALauddin
Tanggal      	: 13 April 2021
Teks Editor     : DevC++
---------------------------------------------------------------*/
#include <stdio.h>
#include "point.h"

int main () {
	
	//Kamus Data
	POINT P;
	int X, Y;
	int temp;
	
	scanf ("%d %d", &X, &Y);
	SetX(&P,X);
	SetY(&P,Y);
	PrintPoint (P);
	
	if(IsOrigin(P)){
		printf("Titik Origin");
		return 0;
	}
	
	else if(IsOnSumbuY(P)){
		printf("Titik berada pada sumbu Y");
		return 0;
	}
	else if(IsOnSumbuX(P)){
		printf("Titik berada pada sumbu X");
		return 0;
	}
	
	else if (Kuadran(P) > 0 && Kuadran(P) < 5 ){
		switch (Kuadran(P)){
			case 1:
				NextX(&P);
				break;
			case 2:
				PrevX(&P);
				break;
			case 3:
				scanf ("%d", &temp);
				PrevX_N(&P, temp);
				break;
			case 4:
				scanf ("%d", &temp);
				NextX_N(&P, temp);
				break;
		}
		PrintPoint (P);
	}	
}

