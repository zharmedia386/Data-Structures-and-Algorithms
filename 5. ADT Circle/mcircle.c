/* Program		: mcircle.c
Deskripsi 		: Main Driver dari Circle.c
Dibuat oleh    	: Muhammad Azhar Alauddin
Tanggal     	: 13 April 2021
Teks Editor     : DevC++
---------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

int main(){
	
	//Kamus data
	POINT P;
	int X,Y;
	float r;
	
	//Membuat Circle 1
	scanf("%d %d %f", &X, &Y, &r);
	Circle C1 = CreateCircle(X,Y,r);
	
	//Membuat Circle 2
	scanf("%d %d %f", &X, &Y, &r);
	Circle C2 = CreateCircle(X,Y,r);
	
	//Mencari Luas dari masing-masing circle
	float L1 = Area(C1);
	float L2 = Area(C2);
	
	//Membandingkan kedua circle
	if(CompareCircle(C1, C2) == 1){
		printf("dua buah Circle memiliki luas area yang sama\n");
	} else if (CompareCircle(C1,C2) == 0) {
		if (L1 < L2) {
			printf("Circle 1 memiliki luas area yang lebih kecil dibandingkan Circle 2\n");
		} 
		else if (L1 > L2){
			printf("Circle 1 memiliki luas area yang lebih besar dibandingkan Circle 2\n");
		}
	
	}
	return 0;
}

