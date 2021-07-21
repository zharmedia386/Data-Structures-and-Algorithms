/* File             : rectangle.c
 * Deskripsi        : Implementasi modul interface dari Spesifikasi ADT Rectangle
 * Dibuat oleh      : Team Teaching SDA
 * Dimodifikasi oleh:  1A - 201524013 - Muhammad Azhar Alauddin
 * Tanggal/versi    : 22 April 2021/ 01
 * ================================================================
 */
 
 #include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>

/* Prosedur membuat Rectangle berdasarkan titik atas dan titik bawah
I.S. Rectangle belum terdefinisi
F.S. Rectangle sudah terdefinisi
*/
void MakeRectangle(RECTANGLE *rect, POINT t_atas, POINT t_bawah){
	rect->titik_atas = t_atas;
	rect->titik_bawah = t_bawah;
}

/* Fungsi untuk menghasilkan sebuah Rectangle berdasarkan titik atas dan titik bawah*/
RECTANGLE CreateRectangle(POINT t_atas, POINT t_bawah){
	RECTANGLE* hasil = (RECTANGLE*)malloc(sizeof(RECTANGLE));
	MakeRectangle(hasil,t_atas,t_bawah);
	return *hasil;
}

/* Prosedur untuk menampilkan informasi Rectangle dengan format
   titik_atas (x,y) dan titik_bawah (x,y) 
I.S. Informasi Rectangle belum ditampilkan ke layar
F.S. Informasi Rectangle sudah ditampilkan sesuai dengan format yang disebutkan   
*/
void PrintRectangle(RECTANGLE rect){
	printf("\n================ OUTPUT ================\n");
	printf("Rectangle berhasil dibuat dengan posisi : \n");
	printf("Titik Atas : (%d,%d)\n",rect.titik_atas.x,rect.titik_atas.y);
	printf("Titik Bawah : (%d,%d)\n",rect.titik_bawah.x,rect.titik_bawah.y);
	printf("Panjang : %d\n",getPanjang(rect));
	printf("Lebar   : %d\n",getLebar(rect));
	printf("\n");
	printf("Luas Persegi Panjang : %d\n",LuasRectangle(rect));
	printf("Keliling Persegi Panjang : %d\n",KelilingRectangle(rect));
}

/* Fungsi untuk mengetahui panjang dari rectangle
   p  = titik_bawah.x - titik_atas.x;
*/
int getPanjang(RECTANGLE rect){
	int p;
	p = rect.titik_bawah.x-rect.titik_atas.x;
	return p;
}

/* Fungsi untuk mengetahui lebar dari rectangle
   l  = titik_bawah.y - titik_atas.y;
*/
int getLebar(RECTANGLE rect){
	int l;
	l = rect.titik_bawah.y-rect.titik_atas.y;
	return l;
}

/* Fungsi untuk menghitung luas Rectangle*/
int LuasRectangle(RECTANGLE rect){
	int luas;
	luas = getPanjang(rect)*getLebar(rect);
	return luas;
}

/* Fungsi untuk menghitung keliling Rectangle*/
int KelilingRectangle(RECTANGLE rect){
	int keliling;
	keliling = ((2*getPanjang(rect)) + 2*getLebar(rect));
	return keliling;
}
