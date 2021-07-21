/* Nama : Muhammad Azhar Alauddin
 * Kelas : 1A - D4 Teknik Informatika
 * NIM : 201524013 
 * File : mainDriver.c
 * Compiler : GCC 4.9.2
 */

#include "queue.h"
#include "queue.c"

// Menginput data penumpang
void InputData(Queue *Q){
  Infotype data = {};

  system("cls");
  printf("ANTRIAN KEBERANGKATAN PESAWAT - INPUT DATA\n");

  // Nama Penumpang
  printf("  Nama           : ");
  scanf("%[^\n]%*c",data.nama);
  fflush(stdin);

  // Waktu Kedatangan
  printf("  Waktu Datang   : ");
  scanf("%d",&data.waktu_datang);
  fflush(stdin);
  
  // Jumlah Koper yang dibawa
  printf("  Jumlah Koper   : ");
  scanf("%d",&data.jum_koper);
  fflush(stdin);
  
  // Ditambahkan ke Queue
  enQueue(Q,data);
}

int main(){
  /* Deklarasi */
  Queue Q;
  Infotype data;
  int choice = -1;

  // Buat Antrian
  CreateQueue(&Q);

  while(choice != 4){
    system("cls");
    printf("ANTRIAN KEBERANGKATAN PESAWAT\n");
    printf("  1. Tambah Antrian \n");
    printf("  2. Hapus Antrian\n");
    printf("  3. Lihat Antrian\n");
    printf("  4. Keluar\n");
    printf("Choose : ");
    scanf("%d",&choice);
    fflush(stdin);

    switch(choice){
      case 1 :
        InputData(&Q);
        break;
      case 2 :
        HapusAntrian(&Q);
        break;
      case 3 :
        PrintQueue(Q);
        getch();
        break;
      case 4 :
        exit(0);
    }
  }
  return 0;
}