#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Определение структуры данных Equip
typedef struct {
    int num;
    char type[50];
    char brand[50];
    char color[20];
    struct {
        int day;
        int month;
        int year;
    } insp_date;
    union {
        char company_id[20];
        struct {
            char first_name[30];
            char last_name[30];
        } owner_name;
    } owner;
} Equip;

// Определение структур данных для стека и очереди
#define MAX_SIZE 100

typedef struct {
    Equip data;
} Node;

typedef struct {
    Node items[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Node items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Прототипы функций для работы с структурами Equip, Stack и Queue
void input(Equip *e);
void display(const Equip *e);
void displayMenu();

void initStack(Stack *s);
void initQueue(Queue *q);

void push(Stack *s, Equip e);
void enqueue(Queue *q, Equip e);

Equip pop(Stack *s);
Equip dequeue(Queue *q);

Equip searchStackByPosition(const Stack *s, int position);
Equip searchStackByValue(const Stack *s, int value);

Equip searchQueueByPosition(const Queue *q, int position);
Equip searchQueueByValue(const Queue *q, int value);

Equip popByPosition(Stack *s, int position);
Equip popByValue(Stack *s, int value);

Equip dequeueByPosition(Queue *q, int position);
Equip dequeueByValue(Queue *q, int value);

void displayStack(const Stack *s);
void displayQueue(const Queue *q);


#endif // EQUIPMENT_H
