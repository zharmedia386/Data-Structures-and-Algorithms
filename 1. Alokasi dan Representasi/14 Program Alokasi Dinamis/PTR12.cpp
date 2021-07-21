/* --------------------------------------------------------- */
/* File Program : PTR12.CPP */
/* Contoh Pointer yang menunjuk ke Procedure dengan parameter input/output*/
/* Tujuan : memahami operasi pointer yang menunjuk ke prosedur yang memiliki
parameter. Melakukan offset terhadap tabel tergantung fungsi f */
/* --------------------------------------------------------- */

#include <stdio.h>

/* Prototype */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succ(int *i); /* suksessor, berupa procedure by ref */
void pred(int *i); /* predesessor */

/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, void (*f)(int *));

/* kamus Global */
int N; /* ukuran efektif */
int main()
{
  /* kamus lokal */
  int MyTab[10];
  int i;
  /* program */
  N = 10;
  for (i = 0; i < N; i++)
    MyTab[i] = i;
  printf("Isi tabel dalam main sebelum pemanggilan : \n");
  for (i = 0; i < N; i++)
    printf(" %d ", MyTab[i]);
  printf("\n");

  /* Pakai geser dengan parameter succ */
  printf("Geser dengan succ \n");
  /* Memanggil modul geser dan menjadikan alamat array MyTab 
 dan alamat dari modul int succ(int*) sebagai parameter. */
  geser(MyTab, succ);
  printf(" dalam main \n");
  for (i = 0; i < N; i++)
    printf(" %d ", MyTab[i]);
  printf("\n");

  /* Pakai geser dengan parameter pred */
  printf("Geser dengan pred \n");
  /* Memanggil modul geser dan menjadikan alamat array MyTab 
 dan alamat dari modul int pred(int*) sebagai parameter. */
  geser(MyTab, pred);
  printf(" dalam main setelah aplikasi pred \n");
  for (i = 0; i < N; i++)
    printf(" %d ", MyTab[i]);
  printf("\n");

  return 0;
}
/*Body Function */
void succ(int *i)
{
  *i = *i + 1;
}
void pred(int *i)
{
  *i = *i - 1;
}
void geser(int *TT, void (*f)(int *))
{
  /* Kamus Lokal */
  int i;
  /*Program*/
  printf(" dalam geser \n");
  for (i = 0; i < N; i++)
  {
    /* Menjalankan fungsi f dengan passing alamat dari TT[i], fungsi 
  f adalah parameter kedua dari modul geser. */
    f(&TT[i]);
    printf(" %d ", TT[i]);
  }
  printf("\n");
}