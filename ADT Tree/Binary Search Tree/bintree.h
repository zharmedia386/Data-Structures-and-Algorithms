#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

typedef int Infotype;
typedef struct Node *address;
typedef struct Node{
  Infotype data;
  address Right;
  address Left;
}Node;

// Membuat node pertama pada tree
address createNode(Infotype X);

// Menambah node, jika lebih besar ditambahkan ke node kanan, jika lebih kecil ditambahkan ke kiri
void insertNode(address *node, address P);

// Mencari node dengan menggunakan rekursi, jika lebih besar pencarian dilakukan ke node kanan, jika lebih kecil pencarian dilakukan ke node Kiri. Jika tidak ditemukan maka mengembalikan node NULL, jika ditemukan mengembalikan node yang dicari
address findNode(address node, Infotype X);

// Menampilkan Binary Search Tree secara PreOrder
void preOrder(address node);

// Menampilkan Binary Search Tree secara inOrder
void inOrder(address node);

// Menampilkan Binary Search Tree secara postOrder
void postOrder(address node);

#endif
