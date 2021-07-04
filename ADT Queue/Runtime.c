/* Antrian Masuk Ruangan */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

// Kamus data
typedef struct{
  char nama[20];
}Pelanggan;

typedef Pelanggan Infotype;
typedef struct elmt *address;

typedef struct elmt{
  Infotype data;
  address Next;
}Node;

typedef struct{
  address Front;
  address Rear;
}Queue;

// Algoritma
void CreateQueue(Queue *Q){
  Q->Front = NULL;
  Q->Rear = NULL;
}

address Alokasi(Infotype X){
  address P = (address)malloc(sizeof(Node));
  strcpy(P->data.nama,X.nama);
  P->Next = NULL;
  return P;
}

bool isEmpty(Queue Q){
  if(Q.Front == NULL)
    return true;
  else
    return false;
}

int CountElement(Queue Q){
  int result = 0;
  address P = Q.Front;
  while(Q.Front != NULL){
    Q.Front = Q.Front->Next;
    result++;
  }
  return result;
}

void EnQueue(Queue *Q, Infotype input){
  address P = Alokasi(input);
  if(isEmpty(*Q) == true)
    Q->Front = P;
  else
    Q->Rear->Next = P;
  Q->Rear = P;
}

void DeQueue(Queue *Q){
  address P = Q->Front;
  Q->Front = Q->Front->Next;
  P->Next = NULL;
  free(P);
}

void ReadElement(Infotype *input){
  fflush(stdin);
  printf("Nama Pelanngan : ");
  scanf("%[^\n]c",input->nama);
  
  fflush(stdin);
}

void PrintElement(Queue Q){
  address P = Q.Front;
  int i = 1;
  printf("PRINT ELEMENT\n");
  while(P != NULL){
    printf("Pelanggan ke-%d : %s\n",i,P->data.nama);
    P = P->Next;
    i++;
  }
}

int main(){
  Queue Q;
  Infotype data;

  // Membuat Antrian Baru
  CreateQueue(&Q);

  printf("READ ELEMENT\n");

  // Menambah Antrian Baru di Rear
  ReadElement(&data);
  EnQueue(&Q,data);

  // Menambah Antrian Baru di Rear
  ReadElement(&data);
  EnQueue(&Q,data);

  // Menambah Antrian Baru di Rear
  ReadElement(&data);
  EnQueue(&Q,data);

  // Menghapus Antrian di Front
  DeQueue(&Q);

  printf("\n");
  
  // Menampilkan Seluruh Isi Antrian Baru
  PrintElement(Q);

  return 0;
}