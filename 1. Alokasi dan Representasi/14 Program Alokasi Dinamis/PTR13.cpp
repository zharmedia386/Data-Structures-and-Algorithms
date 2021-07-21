/* --------------------------------------------------------- */
/* File Program : PTR13.CPP */
/* Contoh Pointer yang menunjuk ke Procedure dengan parameter input/output*/
/* Tujuan : memahami operasi pointer yang menunjuk ke prosedur yang memiliki
parameter. Melakukan offset terhadap tabel tergantung fungsi f */
/* --------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
/* Prototype */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succI(void *i); /* suksessor, berupa procedure by ref */
void predI(void *i); /* predesessor */
void succC(void *c); /* suksessor, berupa procedure by ref */
void predC(void *c); /* predesessor */
/* Prosedur dengan parameter sebuah fungsi */
void geser(int *TT, void (*f)(void *));
/* print tabel yang belum ketahuan typenya */
void printtab(void *T, enum MyType Ty);
/* kamus Global */
int N; /* ukuran efektif */
enum MyType
{
  bulat,
  karakter
};
int main()
{
  void *MyTabInt;
  void *MyTabC;
  int i;
  /* program */
  N = 10;
  MyTabInt = (int *)malloc(N * sizeof(int));
  MyTabC = (char *)malloc(N * sizeof(char));
  /* assignment pointer bertipe data void* harus dilakukan
  casting agar compiler tahu berapa byte yang harus
  diubah. */
  *(int *)MyTabInt = 1;
  for (i = 0; i < N; i++)
  {
    *(int *)((int *)MyTabInt + i) = i;
    *(char *)((char *)MyTabC + i) = 'Z';
  }
  printf("Isi tabel dalam main sebelum pemanggilan : \n");
  printf(" Tabel integer \n");
  printtab((int *)MyTabInt, bulat);
  printf(" Tabel charakter \n");
  printtab((char *)MyTabC, karakter);
  printf("\n");
  /* Pakai geser dengan parameter succ */
  printf("Geser dengan succ \n");
  geser((int *)MyTabInt, succI);
  geser(reinterpret_cast<int *>(MyTabC), succC);
  printf(" dalam main \n");
  printf(" Tabel integer \n");
  printtab((int *)MyTabInt, bulat);
  printf(" Tabel charakter \n");
  printtab((char *)MyTabC, karakter);
  printf("\n");
  /* Pakai geser dengan parameter pred */
  printf("Geser dengan pred \n");
  geser((int *)MyTabInt, predI);
  geser((int *)MyTabC, predC);
  printf(" dalam main \n");
  printf(" Tabel integer \n");
  printtab((int *)MyTabInt, bulat);
  printf(" Tabel charakter \n");
  printtab((char *)MyTabC, karakter);
  printf("\n");
  return 0;
}
/*Body Function */
void succI(void *i)
{
  *(int *)i = *(int *)i + 1;
}
void predI(void *i)
{
  *(int *)i = *(int *)i - 1;
}
void succC(void *c)
{
  *(char *)c = *(char *)c + 1;
}
void predC(void *c)
{
  *(char *)c = *(char *)c - 1;
}
void geser(int *TT, void (*f)(void *))
{
  /* Kamus Lokal */
  int i;
  /*Program*/
  printf(" dalam geser \n");
  for (i = 0; i < N; i++)
  {
    /* i bertambah sebanyak 4 byte karena TT bertipe data
 int*. Sehingga untuk penggeseran char* akan bergeser
 tiap 4 karakter (4 byte) */
    f(&TT[i]);
    printf(" %d ", TT[i]);
  }
  printf("\n");
}
void printtab(void *T, enum MyType Ty)
{
  int i;
  for (i = 0; i < N; i++)
  {
    switch (Ty)
    {
    case bulat:
      printf("%d ", (int *)*((int *)T + i));
      break;
    case karakter:
      printf("%c ", (char *)*((char *)T + i));
      break;
    }
  }
}
