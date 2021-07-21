/* Nama : Muhammad Azhar Alauddin
 * Kelas : 1A - D4 Teknik Informatika
 * NIM : 201524013 
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

/* Definisi elemen dan address */

typedef struct{
  char nama[255]; // Nama Pelanggan
  int waktu_daftar; // Waktu Kedatangan
  char ukuran; // Ukuran kucing (Kecil, Sedang, Besar)

  int waktu_grooming; // Waktu Grooming
  int waktu_tunggu; // Waktu Tunggu Antar Pelanggan
  int waktu_selesai; // Estimasi Waktu Selesai
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
void deQueue(Queue *Q, Infotype *data);

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau mengirimkan 0 jika Q kosong
*/
int NBElmt(Queue Q);

/* Menghitung estimasi waktu selesai, yakni penjumlahan waktu kedatangan dengan waktu grooming
 */
int HitungWaktuSelesai(Queue* Q);

/* Menghitung waktu tunggu antar pelanggan, jika berpaspasan
 */
int HitungWaktuTunggu(Queue* Q);

/* Menghitung waktu grooming berdasarkan ukuran kucing yang diberikan apakah kecil, sedang, atau besar
 */
int HitungWaktuGrooming(char ukuran);

/* Menampilkan seluruh node yang ada di dalam queue 
 */
void PrintQueue(Queue Q);

#endif