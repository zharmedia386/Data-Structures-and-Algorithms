/*
 *	File : jam.h
 *	Nama : Asri Maspupah
 *	deskripsi : Header file dari prototype Time
 *
 */

#ifndef TIME_H
#define TIME_H
#include "boolean.h"

typedef struct {
int Hour ; /* Hour [0..23] */
int Minute; /* Minute [0..59] */
int Second; /* Second [0..59] */
} TIME;

/* Prototype ADT Time */

/** Konstruktor membentuk ADT TIME **/
void CreateTIME (TIME *J, int HH, int MM, int SS);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid 
     Pre condition : HH,MM,SS valid untuk membentuk TIME
     I.S : J tidak terdefinisi, tidak diketahui nilainya
     F.S : membentuk sebuah TIME dari komponen-komponennya dengan J diinisialisasi nilainya dengan 
	   Hour = HH, Minute = MM, Second = SS 
*/
/*****************************************************************/

/** { Operasi terhadap komponen : selektor Get dan Set } **/
/* Selektor TIME **/
int GetHour(TIME J);
// Mengirimkan komponen Hour dari J
int GetMinute(TIME J);
// Mengirimkan komponen Hour dari J
int GetSecond(TIME J);
// Mengirimkan komponen Hour dari J

/* Set nilai komponen */
void SetHour(TIME *J, int newHour);
// Mengirimkan komponen Hour dari J
void SetMinute(TIME *J, int newMinute);
// Mengirimkan komponen Hour dari J
void SetSecond(TIME *J, int newSecond);
// Mengirimkan komponen Hour dari J
/*****************************************************************/

/** {Kelompok Baca/Tulis} **/
void ReadTIME (TIME *J);
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan TIME yang valid */
/* Proses : mengulangi membaca komponen H,M,S sehingga membentuk J yang valid.*/
/* Tidak mungkin menghasilkan J yang tidak valid */

void PrintTIME (TIME J);
/* I.S. : J sembarang */
/* F.S. : Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar */ 
/*****************************************************************/

/** { kelompok Validasi Type } **/
boolean IsJValid (int H, int M, int S);
/* Mengirim true jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah TIME */
/* Konstruktor: Membentuk sebuah TIME dari komponen-komponennya */
/*****************************************************************/

/** {Operator Relasional} **/
boolean JEQ(TIME J1, TIME J2);
/* Mengirimkan true jika Jl=J2, false jika tidak */
boolean JNEQ(TIME J1, TIME J2);
/* Mengirimkan true jika Jl tidak sama dengan J2 */
boolean JLT(TIME J1, TIME J2); 
/* Mengirimkan true jika J1<J2 , false jika tidak */
boolean JGT(TIME J1, TIME J2); 
/* Mengirimkan true jika Jl>J2, false jika tidak*/
/*****************************************************************/

/** { operator aritmatika } **/
void Reset (TIME *J);
/* I.S. J sembarang; F.S. J bernilai �nol� yaitu semua komponennya bernilai 0*/
/* Me-reset nilai J menjadi 0:0:0 */

TIME NextDetik (TIME J);
/* Mengirim 1 detik setelah J dalam bentuk TIME */
TIME PrevDetik (TIME J);
/* Mengirim 1 detik sebelum J dalam bentuk TIME */
TIME JPlus(TIME J1, TIME J2);
/* Menghasilkan Jl+J2, clalam bentuk TIME */

TIME JMinus(TIME J1, TIME J2); 
/* Menghasilkan Jl�J2, dalam bentuk TIME */
/* Precond : Jl<:J2 */

TIME NextNDetik (TIME J, int N);
/* Mengirim N detik setelah J dalam bentuk TIME */

TIME PrevNDetik (TIME J, int N);
/* Mengirim N detik sebelum J dalam bentuk TIME */

long int Durasi (TIME Jaw , TIME JAkh);
/* Mengirim JAkh �JAw dlm Detik, dengen kalkulasi */
/* Hasilnya negatif jika Jaw > JAkhir */
/*****************************************************************/

/** {Kelompok Konversi Terhadap Type} **/
long int TimeToDetik (TIME J);
/* Diberikan sebuah TIME, mengkonversi menjadi Detik */
/* Rumus : detik = 3600*hour+menit*60 + detik */
/* nilai maksimum = 3600*23+59*60+59*60 */
/* hati-hati dengan representasi integer pada bahasa implementasi */
/* kebanyakan sistem mengimplementasi integer, */
/* bernilai maksimum kurang dari nilai maksimum hasil konversi */

void DetikToTIME (long int N); 
/* Mengirim konversi detik ke TIME. Pada beberapa bahasa, representasi integer tidak cukup untuk menampung N */
/*****************************************************************/

#endif

