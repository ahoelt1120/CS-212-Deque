#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 256


typedef struct Node 
{
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque
{
   Node *front;
   Node *back;
   int count;
} Deque;

typedef void (*printData)(void *);
Node *newNode(void *data, size_t dataSize);
Deque *createDeque();
void insertFront(Deque *deque, void *data, size_t dataSize);
void insertBack(Deque *deque, void *data, size_t dataSize);
void removeFront(Deque *deque, void *data, size_t dataSize);
void removeBack(Deque *deque, void *data, size_t dataSize);
void freeDeque(Deque *deque);
void printDeque(Deque *deque, printData print);


#endif //DEQUE_H
