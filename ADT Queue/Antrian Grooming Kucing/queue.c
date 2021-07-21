/* Nama : Muhammad Azhar Alauddin
 * Kelas : 1A - D4 Teknik Informatika
 * NIM : 201524013 
 */

#include "queue.h"

addrNQ Alokasi(Infotype X){
  // Mengalokasikan suatu node dengan parameter Infotype-nya
  addrNQ P = (addrNQ)malloc(sizeof(NodeQueue));
  P->next = NULL;

  // Meng-copy-kan Infotype ke node yang baru dibuat
  strcpy(P->info.nama,X.nama);
  P->info.ukuran = X.ukuran;
  P->info.waktu_daftar = X.waktu_daftar;
  P->info.waktu_grooming = X.waktu_grooming;
  P->info.waktu_selesai = X.waktu_selesai;
  P->info.waktu_tunggu = X.waktu_tunggu;

  return P;
}

// Men-dealokasi suatu node
void Dealokasi(addrNQ *P){
  if((*P) != NULL)
    free((*P));
}

// Inisialisasi Queue
void CreateQueue(Queue *Q){
  (*Q).Front = NULL;
  (*Q).Rear = NULL;
}

// Mengembalikan True jika Queue kosong, dan false jika ada isian
bool isQueueEmpty(Queue Q){
  if(Q.Front == NULL)
    return true;
  else
    return false;
}

// Menambah node ke Rear pada Queue dengan aturan FIFO
void enQueue(Queue *Q, Infotype data){
  addrNQ P = Alokasi(data);
  if(isQueueEmpty((*Q))){
    (*Q).Front = P;
    (*Q).Rear = P;
  }
  else{
    (*Q).Rear->next = P;
    (*Q).Rear = P;
  }
  P->info.waktu_tunggu = HitungWaktuTunggu(Q);
  P->info.waktu_selesai = HitungWaktuSelesai(Q);
}

// Menghapus node dari Front pada Queue dengan aturan FIFO
void deQueue(Queue *Q, Infotype *data){
  if(!isQueueEmpty((*Q))){
    if((*Q).Front->next == NULL)
      (*Q).Front = NULL;
      (*Q).Rear = NULL;
    }
    else
      (*Q).Front = (*Q).Front->next;
}

// Menghitung berapa banyak node yang ada pada Queue
int NBElmt(Queue Q){
  addrNQ P;
  int hasil = 0;
  P = Q.Front;

  while(P != NULL){
    P = P->next;
    hasil++;
  }
  return hasil;
}

// Menghitung Waktu Selesai, hasil penjumlahan waktu Grooming dan waktu Daftar
int HitungWaktuSelesai(Queue *Q){

  if(isQueueEmpty((*Q)))
    return 0;
  // Jika antrian pertama, maka tidak ada waktu tunggu
  if(Q->Front == Q->Rear){
    return (Q->Front->info.waktu_daftar + Q->Front->info.waktu_grooming);
  }
  else{
    // Jika sudah ada pelanggan lain, maka ada waktu tunggu
    return (Q->Rear->info.waktu_daftar + Q->Rear->info.waktu_grooming + Q->Rear->info.waktu_tunggu);
  }
}

// Menghitung waktu tunggu, menggunakan 2 pointer
int HitungWaktuTunggu(Queue *Q){
  addrNQ previous = Q->Front;
  addrNQ current = Q->Rear;

  // Jika Queue masih kosong atau hanya ada 1 nodeQueue
  if((isQueueEmpty((*Q))) || Q->Front == current)
    return 0;

  // Mengarahkan pointer prev ke node sebelah pointer current
  while(previous != NULL && previous->next != current){
    previous = previous->next;
  }

  // Setelah node pada pointer prev berbelahan dengan node pada pointer current
  // Waktu Selesai di node pointer current dikurang dengan waktu waktu daftar node pointer prev
  int hasil = 0;
  hasil = previous->info.waktu_selesai - current->info.waktu_daftar;

  return hasil;
}

// Waktu Grooming berdasarkan ukuran kucing
int HitungWaktuGrooming(char ukuran){
  if(ukuran == 'K' || ukuran == 'k')
    return 30;
  else if(ukuran == 'S' || ukuran == 's')
    return 45;
  else if(ukuran == 'B' || ukuran == 'b')
    return 60;
}

// Menampilkan Seluruh node pada Queue dengan aturan FIFO
void PrintQueue(Queue Q){
  addrNQ current = Q.Front;
  int i = 1;
  system("cls");
  printf("CAT GROOMING APPLICATION\n");
  if(!isQueueEmpty((Q))){
    while(current != NULL) {
      printf("  Urutan         : %d\n",i);
      printf("  Nama           : %s\n",current->info.nama);
      printf("  Waktu Daftar   : %d\n",current->info.waktu_daftar);
      printf("  Ukuran         : %c\n",current->info.ukuran);
      printf("  Waktu Grooming : %d\n",current->info.waktu_grooming);
      printf("  Waktu Tunggu   : %d\n",current->info.waktu_tunggu);
      printf("  Waktu Selesai  : %d\n\n",current->info.waktu_selesai);
      i++;
      current = current->next;
    }
  }
  else
    printf("Antrian Kosong\n");
}