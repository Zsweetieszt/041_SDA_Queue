/*File body untuk ADT Queue*/
//Dibuat tanggal 28-3-2013

#include "queue.h"

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q)
{
	CreateList(Q);
}

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q)
{
	 return (ListEmpty(Q));
}

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q)
{
    if (HitungAntrian(Q) >= MAXQUEUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X)
{
	InsVLast(Q, X);
}

/*Melakukan deletion pada queue*/
void deQueue(Queue *Q, infotype *X) {
    if (is_Empty(*Q)) {
        printf("Antrian kosong! Tidak ada yang dihapus.\n");
        return;
    }
    DelVFirst(Q, X);
}


// menghitung antrian
infotype HitungAntrian(Queue Q) {
    infotype count = 0;
    address P = First(Q);

    while (P != NULL) {
        count++;
        P = Next(P);
    }

    return count;
}

// mengecek antrian dan teller
void AmbilAntrianTeller(Queue **Q, Queue Teller[MAXTELLER], infotype *NoTeller) {
    *Q = NULL;
    *NoTeller = -1;
    int maxKosong = -1;

    for (int i = 0; i < MAXTELLER; i++) {
        int kosong = MAXQUEUE - HitungAntrian(Teller[i]);

        if (kosong > maxKosong) { 
            maxKosong = kosong;
            *Q = &Teller[i];  
            *NoTeller = i;  
        }
    }

    if (maxKosong <= 0) {  // Semua teller penuh
        *Q = NULL;
        *NoTeller = -1;
        printf("Semua teller penuh! Silakan tunggu.\n");
    }
}


void printQueue(Queue Q) 
{
    if (is_Empty(Q)) {
        printf("Antrian kosong.\n");
        return;
    }

    PrintInfo(Q);
}
