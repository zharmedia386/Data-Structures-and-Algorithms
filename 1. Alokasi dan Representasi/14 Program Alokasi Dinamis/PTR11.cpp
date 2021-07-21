/*---------------------------
File Program : PTR11.cpp
Contoh Pointer yang menunjuk ke fungsi yang memiliki parameter
Tujuan : Memahami operasi pointer yang menunjuk ke fungsi. Melakukan
offset terhadap tabel tergantung fungsi f
----------------------------*/

#include <stdio.h>

// Prototype
// Prototype, fungsi yang diberikan sebagai parameter aktual

int succ(int i); // succ -> singkatan dari suksessor
int pred(int i); // pred -> singkatan dari predesessor

// Prosedur dengan parameter sebuah fungsi
void geser(int *TT, int (*f)(int));

// Kamus Global
int N; // Ukuran Efektif

int main()
{
  // Kamus Lokal
  int MyTab[10];
  int i;

  // Program
  N = 10;
  for (i = 0; i < N; i++)
  {
    MyTab[i] = i;
  }

  printf("\nIsi tabel dalam main sebelum pemanggilan : \n");

  for (i = 0; i < N; i++)
  {
    printf(" %d ", MyTab[i]);
  }

  printf("\n");

  // Pakai geser dengan parameter succ
  printf("\nGeser dengan succ \n");
  geser(MyTab, succ);
  printf(" dalam main \n");

  for (i = 0; i < N; i++)
  {
    printf(" %d ", MyTab[i]);
  }
  printf("\n");

  // Pakai geser dengan parameter pred
  printf("\nGeser dengan pred \n");
  geser(MyTab, pred);
  printf(" dalam main setelah aplikasi pred \n");
  for (i = 0; i < N; i++)
  {
    printf(" %d ", MyTab[i]);
  }
  printf("\n");
  return 0;
}

// Body Function
int succ(int i)
{
  return (i + 1);
}

int pred(int i)
{
  return (i - 1);
}

void geser(int *TT, int (*f)(int))
{
  // Kamus Lokal
  int i;

  // Program
  printf(" dalam geser \n");
  for (i = 0; i < N; i++)
  {
    TT[i] = f(TT[i]);
    printf(" %d ", TT[i]);
  }
  printf("\n");
}