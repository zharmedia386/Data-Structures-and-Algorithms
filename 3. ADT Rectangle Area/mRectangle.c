/* File             : mrectangle.h
 * Deskripsi        : alur program sesuai dengan kasus ADT Rectangle
 * Dibuat oleh      : Team Teaching SDA
 * Dimodifikasi oleh:  1A - 201524013 - Muhammad Azhar Alauddin
 * Tanggal/versi    : 22 April 2021/ 01
 * ================================================================
 */

#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	RECTANGLE rect;
	POINT t_atas, t_bawah;
	
	printf("Input Titik Atas (x,y): ");
    scanf("%d %d", &t_atas.x,&t_atas.y);
    printf("Input Titik Bawah (x,y): ");
    scanf("%d %d",&t_bawah.x,&t_bawah.y);
	MakeRectangle(&(rect),t_atas,t_bawah);
	PrintRectangle(rect);
	
	return 0;
}
