/*---------------------------
File Program : PTR8b.cpp
Contoh Pointer dan String bagian ke-3
Tujuan : Memahami operasi menukarkan isi dua buah string yang ditunjuk oleh pointer
----------------------------*/

#include <stdio.h>

int main()
{
  // Kamus Data(Deklarasi, inisialisasi nilai variabel)
  char *nama1 = "DEWI SARTIKA";      // Pendeklarasian dan Pengisian variabel bertipe Array Of Character
  char *nama2 = "SULTAN HASANUDDIN"; // Pendeklarasian dan Pengisian variabel bertipe Array Of Character
  char *namaX;                       // Pendeklarasian variabel bertipe Array Of Character
  puts("Nama semula : ");            // Menampilkan suatu format/teks dengan fungsi puts

  printf("Nama 1 --> %s\n", nama1); // Menampilkan variabel bertipe Array of Character
  printf("Nama 2 --> %s\n", nama2); // Menampilkan variabel bertipe Array of Character

  // Pertukaran string
  namaX = nama1; // Pengisian namaX dengan address nama1
  nama1 = nama2; // Pengisian nama1 dengan address nama2
  nama2 = namaX; // Pengisian nama2 dengan address namaX

  puts("Nama sekarang : ");         // Menampilkan suatu format/teks dengan fungsi puts
  printf("Nama 1 --> %s\n", nama1); // Menampilkan variabel bertipe Array of Character
  printf("Nama 2 --> %s\n", nama2); // Menampilkan variabel bertipe Array of Character

  return 0;
}