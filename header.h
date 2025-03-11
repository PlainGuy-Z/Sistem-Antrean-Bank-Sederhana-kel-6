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

// Struktur Queue
typedef struct queue{
    Node* front;
    Node* rear;
}Queue;


typedef struct nodeStack{
    int noAntrean;
    char nama[50];
    char layanan[50];
    struct nodeStack* next;
}nodeStack; 

typedef struct stack{
    nodeStack* top;
}Stack;
