/*---------------------------
File Program : PTR4.cpp
Contoh operasi pemakaian pointer
Tujuan : Melakukan operasi pada nilai yang ditunjuk pada pointer
----------------------------*/

#include <stdio.h>

int main()
{
  int z, s, *pz, *ps;
  z = 20;
  s = 30;
  pz = &z;
  ps = &s;
  int result = *pz + *ps;
  printf("z = %d, s = %d, s + z = %d\n", z, s, result);

  return 0;
}