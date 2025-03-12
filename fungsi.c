#include "fungsi.h"


//============================++++ Fungsi untuk Queue ++++====================================

// membuat node untuk struct queue
Node* createNodeQueue(int nomor, char* name, char* layanann){
    Node* newNode = (Node*) malloc(sizeof(Node)); // membuat node baru
    if (newNode == NULL){
        printf("GAGAL MENGALOKASIKAN MEMORI\n");
        return NULL;
    }

    newNode->noAntrean = nomor; // simpan data variabel dalam struct node  ke variabel baru
    
    strncpy(newNode->nama, name, sizeof(newNode->nama)-1);
    newNode->nama[sizeof(newNode->nama)-1] = '\0';

    strncpy(newNode->layanan, layanann, sizeof(newNode->layanan)-1);
    newNode->layanan[sizeof(newNode->layanan)-1] = '\0';

    newNode->next = NULL;  // inisialisasikan pointer next ke NULL

    return newNode; 
}

// Alokasi memori dan inisialisasi Queue dengan nillai NULL
Queue* createQueue(){
    Queue* newQ = (Queue*) malloc(sizeof(Queue)); // Buat data Queue
    if (newQ == NULL){
        printf("GAGAL MENGALOKASIKAN MEMORI!\n");
        exit(EXIT_FAILURE);
    }
    newQ->front = newQ->rear = NULL; // Buat Queue kosong
    return newQ;
}

// Fungsi tambahan untuk cek apakah queue kosong
bool isEmptyQueue(Queue* newQ){
    return (newQ->front == NULL); // Periksa jika queue kosong kemballikan true
}

// Fungsi untuk pilih layanan
void pilihLayanan(char* layanan) {
    int pilihan;

    do {    
        printf("\nPilih jenis layanan:\n");
        printf("  1. Setor Tunai\n");
        printf("  2. Tarik Tunai\n");
        printf("  3. Pembukaan Rekening\n");
        printf("Pilihan (1-3): ");
        if (scanf("%d", &pilihan) != 1){                       // Scanf menggunakan perulanagn if  agar input hanya berupa angkaa
            while(getchar() != '\n');                          // bersihkan input dari jika input selain angka
            printf("Input tidak valid! Hanya pilih opsi 1-3"); 
            continue;                                          // ulangi 
        }
        getchar();  // BERSIHKAN  newline dari BUFFER
        
        switch (pilihan) {
            case 1:
            strcpy(layanan, "Setor Tunai");
            break;
            case 2:
            strcpy(layanan, "Tarik Tunai");
            break;
            case 3:
            strcpy(layanan, "Pembukaan Rekening");
            break;
            default:
            printf("Input tidak valid! Hanya pilih opsi 1-3\n");
            break;
        } 
    } while (pilihan < 1 || pilihan >3); // Perulangan while terjadi jika input selain rentang 1-3
}

// Menambahkan dan menyimpan antrian
void enqueue(Queue* newQ, int nomor, char* name, char* layanann, int Silent) { 
    Node* newNode2 = createNodeQueue(nomor, name, layanann); 
    if (isEmptyQueue(newQ)){
        newQ->front = newQ->rear = newNode2;
    }
    else{
        newQ->rear->next = newNode2;
        newQ->rear = newNode2;
    }
    if(!Silent){ // Silent  mode agar saat di pop menggunakan fungsi undo pesan tidak lagi print 
    printf("\nNasabah %s berhasil ditambahkan ke antrean dengan layanan %s\n", name, layanann);
    }
}

// Menghapus, memproses, atau memindahkan antrean ke riwayat
void dequeue(Queue* newQ, Stack* newS) {
    if (isEmptyQueue(newQ)) {
        printf("Tidak ada antrean untuk diproses!\n");
        return;
    }

    Node* temp = newQ->front; // Isi nilai dari front ke variabel sementer(temp)
    printf("\nMemproses nasabah: %s - %s!\n", temp->nama, temp->layanan);

    // Push data yang diproses ke riwayat
    push(newS,  temp->noAntrean, temp->nama, temp->layanan);

    // pindahkan data front ke antrean dibelakangnya
    newQ->front = newQ->front->next;
    if (newQ->front == NULL) {
        newQ->rear = NULL;  
    }
    free(temp); // free kan
    printf("Layanan selesai diproses dan dipindahkan ke riwayat..\n");
}

void displayQueue(Queue* newQ) {
    
    printf("\n+====================== Daftar Antrean =======================+\n");
    printf("| %-5s | %-30s | %-18s |\n", "No.", "Nama Nasabah", "Layanan");
    printf("+-------+--------------------------------+--------------------+\n");
    
    
    if (isEmptyQueue(newQ)) {
        printf("| %-5s | %-30s | %-18s |\n", "-", "-", "-");
        printf("+-------+--------------------------------+--------------------+\n");
        printf("Total nasabah dalam antrean 0\n");
        return;
    } 

        int total = 0;
        Node* temp = newQ->front; // Simpan nilai terdepan di variabel sementara temp
        while (temp != NULL) {
        printf("| %-5d | %-30.30s | %-18.18s |\n", temp->noAntrean, temp->nama, temp->layanan); // isi data dalam tabel
        temp = temp->next;
        total++; // Hitung total antrean

        }
    printf("+-------+--------------------------------+--------------------+\n");
    printf("Total nasabah dalam antrean: %d\n", total);
}

// Fungsi membebaskan memori queue
void freeQueue(Queue* newQ) {
    if (newQ == NULL) 
    return;  

    while (!isEmptyQueue(newQ)) {
        Node* temp = newQ->front;
        newQ->front = newQ->front->next;
        free(temp);  
    }
    free(newQ);  
}
