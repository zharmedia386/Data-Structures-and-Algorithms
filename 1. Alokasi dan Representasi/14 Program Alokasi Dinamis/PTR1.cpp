/*---------------------------
File Program : PTR1.cpp
Contoh pemakaian pointer
Tujuan : Mengetahui panjang dan posisi variabel di memory
----------------------------*/

#include <stdio.h>

int main()
{
  int x, y;                                          //deklarasi variable bertipe integer
  int *px;                                           //deklarasi variable bertipe pointer
  x = 87;                                            //pengisian variabel bertipe integer
  px = &x;                                           //pengisian variabel bertipe alamat
  y = *px;                                           //pengisian variabel bertipe integer dari alamat yang ditunjuk pointer
  printf("Alamat x = %p\n", &x);                     //menampilkan alamat x
  printf("Isi px = %d\n", x);                        //menampilkan variabel x yang ditunjuk pointer px
  printf("Nilai yang ditunjuk oleh px = %d\n", *px); // menampilkan value yang ada dalam suatu alamat
  printf("Nilai y = %d\n", y);                       //menampilkan variable y

  return 0;
}
