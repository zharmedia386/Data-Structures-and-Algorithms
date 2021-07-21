/* Program		  : line.h
Deskripsi 		  : Spesifikasi ADTLine
Dibuat oleh       : Muhammad Azhar Alauddin
Tanggal     	  : 15 April 2021
Teks Editor       : DevC++
---------------------------------------------------------------*/

#include "point.h"

/* Definisi Type Line <Point_Start, Point_End> */

typedef struct {
	POINT startPoint;
	POINT endPoint;
}LINE;

/* Prosedur Membuat Line*/
void MakeLine(LINE *line, POINT p1, POINT p2);

/* Fungsi untuk menghasilkan sebuah LINE berdasarkan POINT yang diinput user*/
LINE CreateLine(POINT p1, POINT p2);

/* Mengembalikan nilai poin awal */
POINT getStartPoint(LINE line);

/* Mengembalikan nilai poin akhir */
POINT getEndPoint(LINE line);

/* Mengubah nilai poin awal */
void setStartPoint(LINE *line, POINT newStartPoint);

/* Mengubah nilai poin akhir */
void setEndPoint(LINE *line, POINT newEndPoint);

/* Prosedur untuk menginput line dari user*/
void ReadLine(LINE *line);

/* Prosedur untuk menampilkan informasi Line*/
void PrintLine(LINE line);

/* Fungsi untuk menghitung panjang antara 2 point pada sebuah line */
int PanjangLine(LINE line);
