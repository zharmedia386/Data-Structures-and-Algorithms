#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
  int First;
  int Next;
  int data[SIZE];
}List;

void CreateList(List *L){
  L->First = -1;
}

bool isEmpty(List L){
  if(L.First == -1)
    return true;
  else
    return false;
}

bool isFull(List L){
  if(L.First == 4)
    return true;
  else
    return false;
}

int CountElement(List L)
{
  int result = 0;
  if (L.First != -1)
  {
    int temp = L.First;
    while (temp != -1)
    {
      result = result + 1;
      temp = L.data[temp]++;
    }
  }

  return result;
}

// Menambah node di Node Pertama 
void addFirst(List *L, int value){
  if(isFull(*L))
    printf("List is Full!!\n");
  else{
    int temp = L->First; // Indeks di depan L->First
    temp++;
    L->data[temp] = value;
    printf("Penambahan Node Berhasil! %d sudah ditambahkan\n",L->data[temp]);
  }
}

// Menambah Node Terakhir
void addLast(List *L, int value){
  // if(isFull(*L))
  //   printf("List is Full!!\n");
  // else{
    int temp = 0;
    int n = CountElement(*L);
    while(temp < n){ // Selangkah di depan Node Terakhir
      temp++; 
    }
    L->data[temp] = value;
    printf("Penambahan Node Berhasil! %d sudah ditambahkan\n",L->data[temp]);
  // }
}

void PrintElement(List L){
  // if(isEmpty(L))
  //   printf("List is Empty!!\n");
  // else{
    int temp = 0;
    int i = 0;
    int n = CountElement(L);
    printf("%d adasd",n);
    printf("List Elements :\n");
    while(temp < n){
      printf("%d ",L.data[i]);
      temp++; 
      i++;
    }
  // }
}

int main(){
  List L;

  // Membuat List Baru
  CreateList(&L);

  // Menambah Node Baru pada List 
  addFirst(&L,1);
  
  // Menambah Node Baru pada List 
  // addLast(&L,2);

  // // Menambah Node Baru pada List 
  // addLast(&L,3);

  // Menambah Node Baru pada List 
  addFirst(&L,4);

  // Menambah Node Baru pada List 
  addFirst(&L,3);

  // Menghapus Node Baru pada List 

  // Menampilkan isi Seluruh node
  PrintElement(L);
  
  return 0;
}