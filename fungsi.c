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

// Fungsi tidak memvalidkan angka dan simbol
int isValidName(char name[]) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') { // Hanya huruf dan spasi yang diperbolehkan
            return 0; 
        }
    }
    return 1; 
}

// Fumgsi tammbahan untuk vallidasi input   
void trimLeadingSpaces(char *str) {
    // Periksa apakah string NULL atau kosong, jika iya langsung keluar dari fungsi
    if (str == NULL || *str == '\0') return;
    
    // menghitung jumlah spasi di awal string
    int count = 0;
    while (str[count] == ' ') {
        count++;
    }
    
    // Jika ada spasi di awal string, geser string ke kiri untuk menghapus spasi
    if (count > 0) {
        memmove(str, str + count, strlen(str) - count + 1); 
        // memmove() digunakan untuk menyalin string mulai dari karakter pertama non-spasi
        // strlen(str) - count + 1 memastikan '\0' tetap ada di akhir string
    }
}

// Fumgsi tammbahan untuk vallidasi input   
int isStringEmptyOrWhitespace(const char *str) {
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return 0; // Kembalikan 0 jika string mengandung karakter lain selain whitespace
        }
        str++;
    }
    return 1; // Jika hanya ditemukan whitespace atau string kosong, kembalikan 1
}

int tambahantrean(Queue* antrean, int* nomorAntrean) {
    char nama[50];
    char layanan[50]; 

    while (1) {
        printf("\nMasukkan Nama Nasabah (atau '0' untuk keluar): ");
        
        if (fgets(nama, sizeof(nama), stdin) == NULL) {
            printf("\nError membaca input.\n");
            break;
        }

        // Hapus newline dari input
        nama[strcspn(nama, "\n")] = 0;

        // kalau karakter dalam variabel nama bernilai 0 maka kembalikan 0
        if (strcmp(nama, "0") == 0) break;

        // cek panjang string
        if  (strlen(nama)>= sizeof(nama)-1){
            printf("Nama terlalu panjang! Masukkan maks %d karakter", sizeof(nama)-1);
            continue;
        }

        // Hapus spasi di awal (jika ada)
        trimLeadingSpaces(nama);

        // Periksa apakah input kosong( jika hanya klik enter) atau hanya berisi spasi 
        if (isStringEmptyOrWhitespace(nama)) {
            printf("\nInput tidak boleh kosong!\n");
            continue;  
        }
        
        // jika berisi angka atau simbol. Tidak valid
        if (!isValidName(nama)) {
            printf("\nInput tidak valid. Tidak boleh mengandung angka atau simboll!\n");
            continue;
        }

        //  Masukkan ke pilih layanan
        pilihLayanan(layanan);

        // Masukkan ke antrean
        enqueue(antrean, (*nomorAntrean)++, nama, layanan, 0);
        break;
    }
    return 0;
}

//============================++++ Fungsi untuk stack ++++====================================
Stack* createStack() {
    Stack* newS = (Stack*) malloc(sizeof(Stack)); // buat Stack kosong, alokasi memori
    if (newS == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
    newS->top = NULL; // Inisialisasi stack kosong
    return newS;
}

bool isEmptyStack(Stack* newS) {
    return (newS->top == NULL);
}

void push(Stack *newS,  int nomor, char* name, char* layanann){
    nodeStack* St = (nodeStack*) malloc(sizeof(nodeStack)); // Alokasi memori untuk node baru
    if (St == NULL){
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }

    St->noAntrean = nomor;

    strncpy(St->nama, name, sizeof(St->nama)-1); // Memastikan string berakhir dengan null terminator
    St->nama[sizeof(St->nama)-1] = '\0';

    strncpy(St->layanan, layanann, sizeof(St->layanan)-1);
    St->layanan[sizeof(St->layanan)-1] = '\0';

    // Tambahin node baru ke dalam stack
    St->next = newS->top;
    newS->top = St;
}

void undo(Stack* newS, Queue* newQ) {
    if (isEmptyStack(newS)){
        printf("Tidak ada transaksi untuk dibatalakan!\n");
        return;
    }

    nodeStack* temp = newS->top;
    newS->top = temp->next;

    printf("Transaksi terakhir: %s - %s\n", temp->nama, temp->layanan);
    printf("Transaksi dibatalkan. Nasabah dikembalikan ke antrean");

    // Mengembalikan data dari stack(riwayat layanan) ke antrean
    enqueue(newQ, temp->noAntrean, temp->nama, temp->layanan, 1); // '1' membaca parameter silent di fungsi enqueue
    free(temp); // kita free kan
}

void displayStack(Stack* newS) {

    printf("\n+====================== Daftar Riwayat =======================+\n");
    printf("| %-5s | %-30s | %-18s |\n", "No.", "Nama Nasabah", "Layanan");
    printf("+-------+--------------------------------+--------------------+\n");
    // Kalo kosong print - di setiap kolom
    if (isEmptyStack(newS)) {
        printf("| %-5s | %-30s | %-18s |\n", "-", "-", "-");
        printf("+-------+--------------------------------+--------------------+\n");
        printf("Belum ada transaksi yang di proses.\n");
        return; 
    } 
    
    // kalo ada isi, masukkan setiap data dalam kolom masing masing
    int totalStack = 0;
    nodeStack* temp2 = newS->top;
    while (temp2 != NULL) {
        printf("| %-5d | %-30.30s | %-18.18s |\n", temp2->noAntrean, temp2->nama, temp2->layanan);
        temp2 = temp2->next;
        totalStack++;
    }

    printf("+-------+--------------------------------+--------------------+\n");
    printf("Total Transaksi: %d\n", totalStack);
}

// membebaskan seluruh memori yang digunakan
void freeStack(Stack* newS){
    nodeStack* temp;
    while(!isEmptyStack(newS)){
        temp = newS->top;
        newS->top = newS->top->next;
        free(temp);
    }
    free(newS);
}


void printMenu() {
    printf("\n+---------------------------------------+\n");
    printf("|        SISTEM ANTREAN BANK            |\n");
    printf("+---------------------------------------+\n");
    printf("| 1. Tambah Nasabah ke Antrean          |\n");
    printf("| 2. Proses Nasabah                     |\n");
    printf("| 3. Tampilkan Antrean Saat Ini         |\n");
    printf("| 4. Tampilkan Riwayat Layanan          |\n");
    printf("| 5. Batalkan Transaksi Terakhir (Undo) |\n");
    printf("| 6. Keluar                             |\n");
    printf("+---------------------------------------+\n");
    printf("Pilihan: ");
}
