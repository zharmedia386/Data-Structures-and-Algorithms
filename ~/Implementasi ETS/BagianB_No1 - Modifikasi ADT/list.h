#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
  char Nama[20];
  char Nilai[20];
} Mahasiswa;

typedef Mahasiswa Infotype;
typedef struct elmt *address;
typedef struct elmt
{
  Infotype data;
  address next;
} elemen;

typedef struct
{
  address first;
} List;
