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
