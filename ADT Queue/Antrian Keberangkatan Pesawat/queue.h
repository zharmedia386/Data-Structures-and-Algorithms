/* Nama : Muhammad Azhar Alauddin
 * Kelas : 1A - D4 Teknik Informatika
 * NIM : 201524013 
 * File : Queue.h
 * Compiler : GCC 4.9.2
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

// Variabel Global
int CHECK_IN = 5; // Waktu Check in = 5 menit
int WAKTU_KOPER = 3; // Waktu Pemindahan Koper = 3 menit

/* Definisi elemen dan address */

typedef struct{
  char nama[255]; // Nama Penumpang
  int waktu_datang; // Waktu Kedatangan Penumpang
  int jum_koper; // Jumlah koper

  int waktu_antrian; // Waktu Tunggu Antar Penumpang = Prev.Selesai - Cur.waktu_daftar
  int waktu_selesai; // Estimasi Waktu Selesai = (Jumlah Koper x 3 menit) + Check_in + Waktu_daftar + Waktu_antrian
}Infotype;

typedef struct NodeQueue *addrNQ;

typedef struct NodeQueue{
  Infotype info;
  addrNQ next;
}NodeQueue; // Pointer yang ada pada Node dan Infotype-nya

typedef struct{
  addrNQ Front;
  addrNQ Rear;
}Queue; 

/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
* Jika alokasi berhasil, modul mengembalikan P; Info(P) = X, Next(P) = NULL.
* P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
* Jika alokasi gagal, modul mengembalikan NULL.
*/
addrNQ Alokasi(Infotype X);

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
*/
void Dealokasi(addrNQ *P);

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) = Nil
I.S. Belum terbentuk Queue
F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q);

/* Mengetahui apakah Queue kosong atau tidak.
mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear
(Q) = Nil
Sebaliknya 0 (Queue tidak kosong)
*/
bool IsQueueEmpty(Queue Q);

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear yang lama mengaitkan pointernya ke node yang baru */
void enQueue(Queue *Q, Infotype data);

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari
Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info yang diambil = nilai elemen Front pd I.S. */
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q
mungkin kosong */
void deQueue(Queue *Q);

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau mengirimkan 0 jika Q kosong
*/
int NBElmt(Queue Q);

/* Menghitung estimasi waktu selesai, yakni (Jumlah Koper x 3 menit) + Check_in + Waktu_daftar + Waktu_antrian
 */
int HitungWaktuSelesai(Queue* Q);

/* Menghitung waktu tunggu antar penumpang, jika berpaspasan = Prev.Selesai - Cur.waktu_daftar
 */
int HitungWaktuAntrian(Queue* Q);

/* Menampilkan seluruh infotype pada node yang ada di dalam queue 
 */
void PrintQueue(Queue Q);

/* Menghapus Antrian pada Queue bagian Front
 */
void HapusAntrian(Queue *Q);

#endif