#include "fungsi.h"

int main() {
    Queue* antrean = createQueue(); 
    Stack* riwayat = createStack();
    int nomorAntrean = 1; // nomor antrian awal di mulai dari satu

    int choice;
    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            
            while (getchar() != '\n');
            printf("Input tidak valid! Hanya pilihan (1-6)\n");
            continue;
        }
        getchar();

        switch (choice) {
            case 1: 
                tambahantrean(antrean, &nomorAntrean);
                break;
            case 2: 
                dequeue(antrean, riwayat);
                break;
            case 3: 
                displayQueue(antrean);
                break;
            case 4: 
                displayStack(riwayat);
                break;
            case 5: 
                undo(riwayat, antrean);
                break;
            case 6:
                printf("Exiting...!\n");
                freeQueue(antrean); 
                freeStack(riwayat);
                break;
            default:
                printf("Input tidak valid! Hanya pilihan (1-6)\n");
                break;
        }
        
    } while (choice != 6);

    return 0;
}
