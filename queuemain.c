#include "linkedlist.h"
#include "queue.h"
#include <stdio.h>

int main() {
    Queue Teller[MAXTELLER];
    infotype nomorAntrian[MAXTELLER];
    Queue *QueuePil = NULL;

    for (int i = 0; i < MAXTELLER; i++) {
        CreateQueue(&Teller[i]);
        nomorAntrian[i] = 1;
    }

    infotype pilihan, NoTeller = -1, no, pil;

    for (;;) {
        printf("\nPilihlah Menu Berikut : \n");
        printf("1. Ambil Antrian\n");
        printf("2. Hapus Antrian\n");
        printf("3. Lihat Semua Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihanmu : ");
        scanf("%d", &pilihan);
        printf("\n========================= \n");

        switch (pilihan) {
        case 1:
            AmbilAntrianTeller(&QueuePil, Teller, &NoTeller);

            if (QueuePil == NULL || NoTeller == -1) {
                printf("Gagal mengambil antrian! Semua teller penuh.\n");
                break;
            }

            no = nomorAntrian[NoTeller];
            nomorAntrian[NoTeller] = nomorAntrian[NoTeller] + 1;

            printf("Nomor antrian %d Di Teller %d\n", no, NoTeller + 1);
            EnQueue(QueuePil, no);

            printf("======================== \n");

            break;
            case 2:
            printf("Pilih Teller: \n");
            for (int i = 1; i <= MAXTELLER; i++) {
                printf("%d. Teller %d\n", i, i);
            }
        
            // Validasi input: pastikan user memasukkan angka dalam rentang yang benar
            printf("Pilih = ");
            if (scanf("%d", &pil) != 1 || pil < 1 || pil > MAXTELLER) {
                printf("Input tidak valid! Masukkan angka antara 1 dan %d.\n", MAXTELLER);
                while (getchar() != '\n'); // Membersihkan buffer input agar tidak terjadi loop infinite
                break;
            }
        
            printf("\n========================= \n");
        
            QueuePil = &Teller[pil - 1];  
            if (is_Empty(*QueuePil)) {
                printf("Teller %d tidak memiliki antrian.\n", pil);
            } else {
                deQueue(QueuePil, &no);
                printf("Nomor antrian %d telah selesai dari teller %d\n", no, pil);
            }
        
            printf("======================== \n");
            break;
        
        case 3:
            for (int i = 0; i < MAXTELLER; i++) {
                printQueue(Teller[i]);
                printf("Jumlah Antrian %d orang\n", HitungAntrian(Teller[i]));
                printf("======================== \n");
            }
            
            break;
        case 4:
            return 0;
        default:
            printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
