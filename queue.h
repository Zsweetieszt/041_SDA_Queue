/*File header untuk ADT Queue*/

#ifndef queue_h
#define queue_h
#include "boolean.h"
#include "linkedlist.h" //nama header disesuaikan dengan program linked list pribadi

#define MAXQUEUE 10
#define MAXTELLER 3

typedef List Queue;

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q);

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q);

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q);

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X);

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X);

infotype HitungAntrian(Queue Q);

void AmbilAntrianTeller(Queue **Q, Queue Teller[MAXTELLER], infotype *NoTeller);

void printQueue(Queue Q);

#endif

