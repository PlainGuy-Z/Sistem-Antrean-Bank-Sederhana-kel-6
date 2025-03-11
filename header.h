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

// fumgsi fungsi queue
Queue* createQueue();
bool isEmptyQueue(Queue* newQ);
Node* createNodeQueue(int nomor, char* name, char* layanann);
void pilihLayanan(char* layanan);
void enqueue(Queue* newQ, int nomor, char* name, char* layanann, int Silent);
void dequeue(Queue* newQ, Stack* newS);
//void peek(Queue* newQ);
void displayQueue(Queue* newQ);
void freeQueue(Queue* newQ);

// fungsi fungsi stack
Stack* createStack();
bool isEmptyStack(Stack* newS);
void push(Stack *newS,  int nomor, char* name, char* layanann);
void displayStack(Stack* newS);
void undo(Stack* newS, Queue* newQ);
void freeStack(Stack* newS);

// Fitur tambahaan
int isValidName(char name[]);
void trimLeadingSpaces(char *str);
int isStringEmptyOrWhitespace(const char *str);
int tambahantrean(Queue* antrean, int* nomorAntrean);
void printMenu();

#endif

