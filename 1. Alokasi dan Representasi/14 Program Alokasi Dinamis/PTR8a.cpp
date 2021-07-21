/*---------------------------
File Program : PTR8a.cpp
Contoh Pointer dan String bagian ke-2
Tujuan : Memahami operasi menukarkan isi dua buah string tanpa pemakaian pointer
----------------------------*/

#include <stdio.h>
#include <string.h>
#define PANJANG 20

int main()
{
  // Kamus Data(Deklarasi, inisialisasi nilai variabel)
  char nama1[PANJANG] = "DEWI SARTIKA";      // Pendeklarasian dan Pengisian variabel bertipe Array Of Character
  char nama2[PANJANG] = "SULTAN HASANUDDIN"; // Pendeklarasian dan Pengisian variabel bertipe Array Of Character
  char namaX[PANJANG];                       // Pendeklarasian variabel bertipe Array Of Character
  puts("Nama semula : ");                    // Menampilkan suatu format/teks dengan fungsi puts
  printf("Nama 1 --> %s\n", nama1);          // Menampilkan variabel bertipe Array of Character
  printf("Nama 2 --> %s\n", nama2);          // Menampilkan variabel bertipe Array of Character

  strcpy(namaX, nama1); // Menyalin String namaX ke nama1
  strcpy(nama1, nama2); // Menyalin String nama1 ke nama2
  strcpy(nama2, namaX); // Menyalin String nama2 ke namaX

  puts("Nama sekarang : ");          // Menampilkan suatu format/teks dengan fungsi puts
  printf("Nama 1 --> %s\n", nama1);  // Menampilkan variabel bertipe Array of Character
  printf("Nama 2 -- > %s\n", nama2); // Menampilkan variabel bertipe Array of Character
  return 0;
}
