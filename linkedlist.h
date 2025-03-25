#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First
#define Last(L) (L).Last

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address First;
    address Last;
} List;

boolean ListEmpty(List L);
void CreateList(List *L);
address Alokasi(infotype X);
void DeAlokasi(address P);
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);
void DelVFirst(List *L, infotype *X);
void DelVLast(List *L, infotype *X);
void PrintInfo(List L);

#endif
