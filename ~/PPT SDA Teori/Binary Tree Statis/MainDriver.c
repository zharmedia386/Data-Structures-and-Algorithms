#include "binarytree.h"
#include "binarytree.c"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void output(binaryTree BT[MaxEl+1]);
void preorder(binaryTree BT[MaxEl+1], int posisi);
void inorder(binaryTree BT[MaxEl+1], int posisi);
void postorder(binaryTree BT[MaxEl+1], int posisi);
void levelorder(binaryTree BT[MaxEl+1], int posisi);
int height(binaryTree x[MaxEl+1], int posisi);
void printCurrentLevel(binaryTree x[MaxEl+1], int posisi, int level);

void output(binaryTree BT[MaxEl+1]){
	char choice;
	do{
		system("cls");
		printf("--------Menampilkan Elemen--------\n");
		printf("1. Pre Order \n");
		printf("2. In Order \n");
		printf("3. Post Order \n");
		printf("4. Level Order \n");
		printf("5. Keluar \n");
		fflush(stdin);
		printf("\nMasukkan Pilihan: ");
		scanf("%c",&choice);
		switch(choice){
			case '1' : 
				preorder(BT, 1);
				getch();
				break;
			case '2' :
				inorder(BT, 1);
				getch();
				break;
			case '3' : 
				postorder(BT, 1);
				getch();
				break;
			case '4' : 
				levelorder(BT, 1);
				getch();
				break;
		}
	}while(choice!='5');
	
}

void preorder(binaryTree x[MaxEl+1], int posisi){
	if(x[posisi].info!=0){
        printf(" %d ", x[posisi].info);//akar
        preorder(x, x[posisi].left);//kiri
        preorder(x, x[posisi].right);//kanan
    }
}

void inorder(binaryTree x[MaxEl+1], int posisi){
    if(x[posisi].info!=0){
        inorder(x, x[posisi].left);//kiri
        printf(" %d ", x[posisi].info);//akar
        inorder(x, x[posisi].right);//kanan
    }
}

void postorder(binaryTree x[MaxEl+1], int posisi){
    if(x[posisi].info!=0){
        postorder(x, x[posisi].left);
        postorder(x, x[posisi].right);
        printf(" %d ", x[posisi].info);
    }
}

int height(binaryTree x[MaxEl+1], int posisi){
    if(x[posisi].info==0)
        return 0;
    else{
        /* compute the height of each subtree */
        int lheight = height(x, x[posisi].left);
        int rheight = height(x, x[posisi].right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void levelorder(binaryTree x[MaxEl+1], int posisi){
    int h = height(x,posisi);
    int i;
    for (i=1; i<=h; i++)
        printCurrentLevel(x, posisi, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(binaryTree x[MaxEl+1], int posisi, int level){
    if (x[posisi].info==Nil)
        return;
    if (level == 1)
        printf("%d ", x[posisi].info);
    else if (level > 1){
        printCurrentLevel(x, x[posisi].left, level-1);
        printCurrentLevel(x, x[posisi].right, level-1);
    }
}

int main() {
	//kamus
	binaryTree BT[MaxEl+1];
	int x, checkpoint;
	char choice;
	
	//algoritma
	createBinaryTree(BT);
	checkpoint = 0;
	while (choice != '3') {
		system("cls");
		printf("Demo Binary Tree\n");
		printBinaryTreeInfo(BT); 
		printf("\nJumlah elemen = %d \n", NBElmt(BT));
		printf("Nilai Height = %d \n", height(BT,1));
		printf("-------- Menu --------\n");
		printf("1. Menambah Elemen \n");
		printf("2. Menampilkan Elemen \n");
		printf("3. Keluar \n");
		fflush(stdin);
		printf("\nPilihan : ");
		scanf("%c",&choice);
		switch(choice){
			case '1' : 
				printf("\n-------- Add --------\n");
				printf("Masukkan angka: ");
				scanf("%d",&x);
				fflush(stdin);
				insert(BT, x, &checkpoint);
				break;
			case '2' :
				output(BT);
				break;
			case '3' : 
				break;
		}
	}
	
	printf("selesai..");
	
	
	return 0;
}



