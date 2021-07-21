/* Nama : Muhammad Azhar Alauddin
 * Kelas : 1A - D4 Teknik Informatika
 * NIM : 201524013 
 */

#include "queue.h"
#include "queue.c"

// Menginput data pelanggan dan kucing
void InputData(Queue *Q){
  Infotype data = {};

  system("cls");
  printf("CAT GROOMING APPLICATION - INPUT DATA\n");
  printf("  Nama           : ");
  if(data.nama[0] == '\0'){
    scanf("%[^\n]%*c",data.nama);
    fflush(stdin);
  }
  else
    printf("%s\n", data.nama);

  printf("  Waktu Daftar   : ");
  if(data.waktu_daftar <= 0){
    scanf("%d",&data.waktu_daftar);
    fflush(stdin);
  }
  else
    printf("%d\n", data.waktu_daftar);
  
  printf("  Ukuran Kucing  : ");
  if(data.waktu_grooming <= 0){
    scanf("%c",&data.ukuran);
    fflush(stdin);
    data.waktu_grooming = HitungWaktuGrooming(data.ukuran);
  }
  else 
    printf("%c\n", data.ukuran);
  
  enQueue(Q,data);
}

int main(){
  /* Deklarasi */
  Queue Q;
  Infotype data;
  int choice = -1;

  // Buat Antrian
  CreateQueue(&Q);

  while(choice != 3){
    system("cls");
    printf("CAT GROOMING APPLICATION\n");
    printf("  1. Daftar Antrian\n");
    printf("  2. Lihat Antrian\n");
    printf("  3. Keluar Aplikasi\n");
    printf("Choose : ");
    scanf("%d",&choice);
    fflush(stdin);

    switch(choice){
      case 1 :
        InputData(&Q);
        // Q.Rear->info.waktu_selesai = HitungWaktuSelesai(&Q);
        // Q.Rear->info.waktu_tunggu = HitungWaktuTunggu(&Q);
        break;
      case 2 :
        PrintQueue(Q);
        getch();
        break;
      case 3 :
        exit(0);
    }
  }
  return 0;
}