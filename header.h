#ifndef TUGAS_ANTREANBANK_HEADER_H
#define TUGAS_ANTREANBANK_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Struktur untuk node Queue
typedef struct Node{
    int noAntrean;
    char nama[50];
    char layanan[50];
    struct Node* next;
}Node;
