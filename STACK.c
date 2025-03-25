/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "stack.h"

/**** Perubahan nilai komponen struktur  ****/
// void SetTop (Stack *S, Stack NewTop )
// /* Memberi Nilai TOP yang baru dengan NewTop */
// {
// 	if (NewTop != NULL) {
//         *S = NewTop; // Menggeser top ke alamat yang baru
//     }
// }





/*    PROTOTYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */
{
	First(*S) = NULL;  
}

/**** Predikat untuk test keadaan KOLEKSI ****/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack Kosong */
{
	return (ListEmpty(S));
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	InsVFirst(S, X);  // nama modul disesuaikan dengan pseudocode linked list pribadi
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	DelVFirst(S, X); // nama modul disesuaikan dengan pseudocode linked list pribadi
}

void KonversiDesimalBiner(infotype X)
{
    Stack S, temp;
    int sisa;

    CreateEmpty(&S);

    while (X > 0) {
        sisa = X % 2;
        Push(&S, sisa);
        X /= 2;
    }

    printf("Hasil konversi biner: ");

    while (!IsEmpty(S)) {
        Pop(&S, &sisa);
        printf("%d", sisa);
    }
    printf("\n");
    printf("======================== \n");
}