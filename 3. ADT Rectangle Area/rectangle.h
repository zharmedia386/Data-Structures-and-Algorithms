/* File             : rectangle.h
 * Deskripsi        : Spesifikasi ADT Rectangle
 * Dibuat oleh      : Team Teaching SDA
 * Dimodifikasi oleh:  1A - 201524013 - Muhammad Azhar Alauddin
 * Tanggal/versi    : 22 April 2021/ 01
 * ================================================================
 */
 
#include<stdio.h>
#include "point.h"
#ifndef  RECTANGLE_H
#define  RECTANGLE_H


/*

 titik_atas (x,y)  
       +-----------+
       |           |
       |           |
       +-----------+
             titik_bawah (x,y)
             
*/

typedef struct{
	POINT titik_atas;
	POINT titik_bawah;
} RECTANGLE;


/* Prosedur membuat Rectangle berdasarkan titik atas dan titik bawah
I.S. Rectangle belum terdefinisi
F.S. Rectangle sudah terdefinisi
*/
void MakeRectangle(RECTANGLE *rect, POINT t_atas, POINT t_bawah);

/* Fungsi untuk menghasilkan sebuah Rectangle berdasarkan titik atas dan titik bawah*/
RECTANGLE CreateRectangle(POINT t_atas, POINT t_bawah);

/* Prosedur untuk menampilkan informasi Rectangle dengan format
   titik_atas (x,y) dan titik_bawah (x,y) 
I.S. Informasi Rectangle belum ditampilkan ke layar
F.S. Informasi Rectangle sudah ditampilkan sesuai dengan format yang disebutkan   
*/
void PrintRectangle(RECTANGLE rect);

/* Fungsi untuk mengetahui panjang dari rectangle
   p  = titik_bawah.x - titik_atas.x;
*/
int getPanjang(RECTANGLE rect);

/* Fungsi untuk mengetahui lebar dari rectangle
   l  = titik_bawah.y - titik_atas.y;
*/
int getLebar(RECTANGLE rect);

/* Fungsi untuk menghitung luas Rectangle*/
int LuasRectangle(RECTANGLE rect);

/* Fungsi untuk menghitung keliling Rectangle*/
int KelilingRectangle(RECTANGLE rect);

#endif
