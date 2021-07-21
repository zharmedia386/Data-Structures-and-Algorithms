/* File        : list1.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Dimodifikasi oleh : Muhammad Azhar Alauddin */

#ifndef list_H
#define list_H
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct{
  char ktp[50];
  char nama[50];
  char telpon[50];
  char tanggal[50];
  char jam[50];
  char kategori[10];
  char instansi[20];
  char usia[5];
  char sekolah[50];
  char kampus[50];
}dataPendaftar;


typedef struct elmt *address;
typedef struct elmt{
  dataPendaftar info;
  address next;
}elemen;


typedef struct{
  elemen *first;
}list;

void createList(list *L);

int countElement(list L);

//void addFirst(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char instansi[], list *L);

//void addFirst1(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char usia[], list *L);
//
//void addFirst2(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char char sekolah[], list *L);
//
//void addFirst3(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char kampus[], list *L);


void addAfter(elemen *prec, char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char instansi[], char usia[], char kampus[], char sekolah[], list *L);

void addLast(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char instansi[], char usia[], char sekolah[], char kampus[], list *L);

//void addLast1(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char usia[], list *L);
//
//void addLast2(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char char sekolah[], list *L);
//
//void addLast3(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char kampus[], list *L);

void delFirst(list *L);

void delAfter(elemen *prec, list *L);

void delLast(list *L);

void printElement(list L);

void printElement1(list L);

void delAll(list *L);

int KategoriValue(dataPendaftar X);

#endif
