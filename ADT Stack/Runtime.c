/* ADT Stack :
Push -> Menambah Elemen di Top
Pop -> Menghapus Elemen di Top
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
  int Top;
  int data[SIZE];
}Stack;

void CreateStack(Stack *S){
  S->Top = -1;
}

bool isEmpty(Stack S){
  if(S.Top == -1)
    return true;
  else
    return false;
}

bool isFull(Stack S){
  if(S.Top == 4)
    return true;
  else
    return false;
}

void Push(Stack *S,int value){
  if(isFull(*S))
    printf("Stack is Full!!\n");
  else{
    S->Top++;
    S->data[S->Top] = value;
    printf("Push Berhasil!! %d sudah ditambahkan\n",S->data[S->Top]);
  }
}

void Pop(Stack *S){
  if(isEmpty(*S))
    printf("Stack is Empty!!\n");
  else{
    printf("\n\nPop Berhasil!! %d sudah dihapus\n",S->data[S->Top]);
    S->Top--;
  }
}

void PrintElement(Stack S){
  if(isEmpty(S))
    printf("Stack is Empty!!\n");
  else{
    int i;
    printf("\nQueue Elements :\n");
    for(i = S.Top; i >= 0; i--)
      printf("%d ",S.data[i]);
  }
}

int main(){
  Stack S;

  // Membuat Stack Baru
  CreateStack(&S);

  // Node Kosong 
  PrintElement(S);

  // Menambah Node Baru pada Stack - Push
  Push(&S,1);

  // Menambah Node Baru pada Stack - Push
  Push(&S,2);

  // Menambah Node Baru pada Stack - Push
  Push(&S,3);

  // Menambah Node Baru pada Stack - Push
  Push(&S,4);

  // Menambah Node Baru pada Stack - Push
  Push(&S,5);

  // Menampilkan Seluruh isi node pada Stack
  PrintElement(S);

  // Menghapus Node pada Stack - Pop
  Pop(&S);

  // Menampilkan Seluruh isi node pada Stack
  PrintElement(S);

  return 0;
}