/* Program		: line.c
Deskripsi		: Spesifikasi ADTLine
Dibuat oleh		: Muhammad Azhar Alauddin
Tanggal			: 15 April 2021
Teks Editor 	: DevC++
---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "line.h"
#include "boolean.h"

/* CREATOR */
/* Prosedur Membuat Line*/
void MakeLine(LINE *line, POINT p1, POINT p2){
	line->startPoint = p1;
	line->endPoint = p2;
}

/* Fungsi untuk menghasilkan sebuah LINE berdasarkan POINT yang diinput user*/
LINE CreateLine(POINT p1, POINT p2){
	LINE* hasil = (LINE*)malloc(sizeof(LINE));
	MakeLine(hasil,p1,p2);
	return *hasil;
}

/* GETTER(ACCESSOR) */
/* Mengembalikan nilai poin awal */
POINT getStartPoint(LINE line){
	return line.startPoint;
}

/* Mengembalikan nilai poin akhir */
POINT getEndPoint(LINE line){
	return line.endPoint;
}

/* SETTER(MUTATOR) */
/* Mengubah nilai poin awal */
void setStartPoint(LINE *line, POINT newStartPoint){
	line->startPoint = newStartPoint;
}

/* Mengubah nilai poin akhir */
void setEndPoint(LINE *line, POINT newEndPoint){
	line->endPoint = newEndPoint;
}

/* INPUT USER */
/* Prosedur untuk menginput line dari user*/
void ReadLine(LINE *line){
	POINT p1,p2;
	printf("Input Point Start : ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Input Point End : ");
    scanf("%d %d",&p2.x, &p2.y);
	MakeLine(&(*line),p1,p2);
}

/* PRINTING OUT */
/* Prosedur untuk menampilkan informasi Line*/
void PrintLine(LINE line){
	printf("\n================ LINE ================\n");
	printf("Line berhasil dibuat dengan posisi : \n");
	printf("Point Start (%d,%d)\n",line.startPoint.x,line.startPoint.y);
	printf("Point End (%d,%d)",line.endPoint.x,line.endPoint.y);
}

/* LAIN-LAIN */
/* Fungsi untuk menghitung panjang antara 2 point pada sebuah line */
int PanjangLine(LINE line){
	return sqrt(pow(GetX(line.endPoint)-GetX(line.startPoint),2) + pow(GetY(line.endPoint)-GetY(line.startPoint),2));
}
