/* Nama : Muhammad Azhar Alauddin
 * Kelas : 1A - D4 Teknik Informatika
 * NIM : 201524013 
 * File : Queue.c
 * Compiler : GCC 4.9.2
 */

#include "queue.h"

addrNQ Alokasi(Infotype X){
  // Mengalokasikan suatu node dengan parameter Infotype-nya
  addrNQ P = (addrNQ)malloc(sizeof(NodeQueue));
  P->next = NULL;

  // Meng-copy-kan Seluruh Infotype ke node yang baru dibuat
  strcpy(P->info.nama,X.nama);
  P->info.jum_koper = X.jum_koper;
  P->info.waktu_antrian = X.waktu_antrian;
  P->info.waktu_selesai = X.waktu_selesai;
  P->info.waktu_datang = X.waktu_datang;

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

// Mengembalikan True jika Queue kosong, dan false jika ada isi pada Queue
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
  P->info.waktu_antrian = HitungWaktuAntrian(Q);
  P->info.waktu_selesai = HitungWaktuSelesai(Q);
}

// Menghapus node dari Front pada Queue dengan aturan FIFO
void deQueue(Queue *Q){
  if(!isQueueEmpty((*Q))){
    if((*Q).Front->next == NULL){
      (*Q).Front = NULL;
      (*Q).Rear = NULL;
    }
    else{
      addrNQ P;
      P = (*Q).Front;
      (*Q).Front = P->next;
      P->next = NULL;
      free(P);
    }
  } 
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
  int hasil = 0;
  if(isQueueEmpty((*Q)))
    return 0;

  // Jika antrian pertama, maka waktu check_in + (jum_koper x waktu_koper)
  if(Q->Front == Q->Rear){
    return (CHECK_IN + Q->Front->info.waktu_datang + (Q->Front->info.jum_koper * WAKTU_KOPER));
  }
  else{
    // Jika sudah ada pelanggan lain, maka (Jumlah Koper x 3 menit) + Check_in + Waktu_daftar + Waktu_antrian
    if(Q->Rear->info.waktu_antrian > 0)
      return (Q->Rear->info.waktu_datang + Q->Rear->info.waktu_antrian + CHECK_IN + (Q->Rear->info.jum_koper * WAKTU_KOPER));
    else{
      // Jika tidak ada waktu_antrian
      return (Q->Rear->info.waktu_datang + CHECK_IN + (Q->Rear->info.jum_koper * WAKTU_KOPER));
    }
  }
}

// Menghitung waktu Antrian antar penumpang
int HitungWaktuAntrian(Queue *Q){
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
  hasil = previous->info.waktu_selesai - current->info.waktu_datang;

  return hasil;
}

// Menampilkan Seluruh node pada Queue 
void PrintQueue(Queue Q){
  addrNQ current = Q.Front;
  int i = 1;
  system("cls");
  printf("ANTRIAN KEBERANGKATAN PESAWAT - DAFTAR ANTRIAN\n");
  if(!isQueueEmpty((Q))){
    // Berpindah ke node selanjutnya jika ada, hingga NULL
    while(current != NULL) { 
      printf("  Urutan            : %d\n",i);
      printf("  Nama              : %s\n",current->info.nama);
      printf("  Waktu Datang      : %d\n",current->info.waktu_datang);
      printf("  Jumlah Koper      : %d\n",current->info.jum_koper);
      if(current->info.waktu_antrian > 0)
        printf("  Waktu Mengantri   : %d\n",current->info.waktu_antrian);
      else
        printf("  Waktu Mengantri   : Tidak Mengantri\n");
      printf("  Estimasi Selesai  : %d\n\n",current->info.waktu_selesai);
      i++;
      current = current->next; 
    }
    printf("Tekan APAPUN pada keyboard untuk kembali ke Main Menu\n");
  }
  else
    printf("  Antrian Kosong\n");
}

/* Menghapus Antrian pada Queue bagian Front */
void HapusAntrian(Queue *Q){
  if(!isQueueEmpty((*Q))){
    system("cls");
    printf("ANTRIAN KEBERANGKATAN PESAWAT - HAPUS ANTRIAN\n");
    printf("  This will permanently delete the data. Are you sure? (Y/N) ");
    char confirm;
    scanf("%c",&confirm);
    if(confirm == 'Y' || confirm == 'y')
      deQueue(Q);
    else
      return;
  }
}