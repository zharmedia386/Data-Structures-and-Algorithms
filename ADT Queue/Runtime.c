/* ATURAN FIFO(First In First Out)
EnQueue(Menambah Node) = Rear
DeQueue(Menghapus Node) = Front
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Kamus Data
typedef struct{
  int Front;
  int Rear;
  int data[SIZE];
}Queue;

// Algoritma
void EnQueue(Queue *Q,int value){ // Menambah Node Baru di Rear
  if(Q->Rear == SIZE-1){  // If Queue is Full
    printf("Queue is Full!!\n");
  }
  else { 
    if(Q->Front == -1) // Jika Queue Kosong, Front == Rear == -1
      Q->Front = 0;
    Q->Rear++; // Pindah ke Elemen Selanjutnya di Rear (FIFO)
    Q->data[Q->Rear] = value; 
    printf("EnQueue Berhasil!! %d sudah ditambahkan\n",value);
  }
}

void DeQueue(Queue *Q){ // Menghapus Node di Front
  if(Q->Front == -1){ // Jika Queue Kosong
    printf("Queue is Empty!!\n");
  }
  else{
    printf("DeQueue Berhasil!! %d sudah dihapus\n",Q->data[Q->Front]);
    Q->Front++; // Pindah ke elemen selanjutnya
    if(Q->Front == Q->Rear) // Jika Elemen Terakhir
      Q->Front = Q->Rear = -1;
  }
}

void PrintElement(Queue Q){
  if(Q.Rear == -1){
    printf("Queue is Empty!!\n");
  }
  else{
    int i;
    printf("Queue Elements :\n");
    for(i = Q.Front; i <= Q.Rear ; i++)
      printf("%d ",Q.data[i]);
    printf("\n");
  }
}

int main(){
  Queue Q;
  Q.Front = -1; Q.Rear = -1;
  
  //DeQueue is not possible on empty queue
  DeQueue(&Q);

  EnQueue(&Q,1);
  EnQueue(&Q,2);
  EnQueue(&Q,3);
  EnQueue(&Q,4);
  EnQueue(&Q,5);

  // 6th element can't be added to because the queue is full
  EnQueue(&Q,6);

  PrintElement(Q);

  //DeQueue removes element entered first i.e. 1
  DeQueue(&Q);

  //Now we have just 4 elements
  PrintElement(Q);

  return 0;
}