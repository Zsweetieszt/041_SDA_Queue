#include "linkedlist.h"

boolean ListEmpty(List L) {
    return (First(L) == Nil);
}

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DeAlokasi(address P) {
    free(P);
}

void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        address Last = First(*L);
        if (Last == Nil) {
            First(*L) = P;
        } else {
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirst(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        DeAlokasi(P);
    }
}

void DelVLast(List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L), Prec = Nil;
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        *X = Info(P);
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
        DeAlokasi(P);
    }
}

void PrintInfo(List L) {
    address P = First(L);
    while (P != Nil) {
        printf("%d -> ", Info(P));
        P = Next(P);
    }
    printf("NULL\n");
}
