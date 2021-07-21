/*---------------------------
File Program : PTR2.cpp
Contoh pemakaian pointer yang salah
Tujuan : Mengetahui panjang dan posisi variabel di memory
----------------------------*/

#include <stdio.h>

int main()
{
  float *pu;               //deklarasi variable pointer bertipe float
  float nu;                //deklarasi variable yang bertipe float
  int u = 1234;            //pengisian variable bertipe integer
  pu = (float *)&u;        //pengisian alamat dari variable u bertipe float
  nu = *pu;                //pengisian value nu dengan pointer pu
  printf("u = %d\n", u);   //menampilkan variable u bertipe integer
  printf("nu = %f\n", nu); //menampilkan variable nu bertipe float

  return 0;
}