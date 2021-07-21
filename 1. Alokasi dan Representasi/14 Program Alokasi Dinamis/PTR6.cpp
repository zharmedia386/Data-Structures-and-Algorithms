/*---------------------------
File Program : PTR6.cpp
Contoh pointer menunjuk ke array
Tujuan : Memahami operasi pointer yang menunjuk kepada array
----------------------------*/

#include <stdio.h>

int main()
{
  // Kamus Data(Deklarasi, inisialisasi nilai variabel)
  static int tgl_lahir[] = {18, 6, 1989};
  int *ptgl;

  ptgl = tgl_lahir;
  printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
  ptgl += 1;
  printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
  ptgl += 1;
  printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
  printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);

  return 0;
}