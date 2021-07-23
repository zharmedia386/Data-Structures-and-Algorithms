#include "bintree.h"
#include "bintree.c"

int main(){
  // Inisialisasi node pertama
  address P = createNode(10);

  // Penambahan 5 node
  insertNode(&P,createNode(11));
  insertNode(&P,createNode(12));
  insertNode(&P,createNode(13));
  insertNode(&P,createNode(14));
  insertNode(&P,createNode(15));

  while(true){
  	// Menampilkan secara PreOrder, InOrder, dan PostOrder
  	system("cls");
 	printf("PreOrder : ");
 	preOrder(P);
  
 	printf("\nInOrder : ");
 	inOrder(P);

 	printf("\npostOrder : ");
	postOrder(P);
  	printf("\n");
  
    int searchNum = 0;
    printf("\nNode yang ingin dicari : ");
    scanf("%d",&searchNum);

    // Mencari Node tertentu
    address temp1 = findNode(P,searchNum);
    if(temp1 != NULL)
      printf("\nNode %d ditemukan",searchNum);
    else
      printf("\nNode %d tidak ditemukan",searchNum);

    char batas;
    printf("\n\nLanjut Pencarian?(y/n) : ");
    fflush(stdin);
    scanf("%c",&batas);
    if(batas == 'Y' || batas == 'y')
      continue;
    else
      break;
  }
	
  return 0;
}
