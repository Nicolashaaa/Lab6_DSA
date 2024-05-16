#ifndef FUNC_H
#define FUNC_H

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

// Структура узла односвязного списка
typedef struct Node {
    Equip data;
    struct Node* next;
} Node;

// Структура двусвязного списка
typedef struct DoubleNode {
    Equip data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

// Структура циклического списка
typedef DoubleNode CircularNode;

void input(Equip *e);
void display(const Equip *e);
void displayMenu();


Node* createSingleLinkedList();
void displaySingleLinkedList(Node* head);
Node* insertNodeSingleLinkedList(Node* head, Equip data, int position);
Node* deleteNodeSingleLinkedList(Node* head, int position);
Node* searchSingleLinkedList(Node* head, int value);


DoubleNode* createDoubleLinkedList();
void displayDoubleLinkedList(DoubleNode* head);
DoubleNode* insertNodeDoubleLinkedList(DoubleNode* head, Equip data, int position);
DoubleNode* deleteNodeDoubleLinkedList(DoubleNode* head, int position);
DoubleNode* searchDoubleLinkedList(DoubleNode* head, int value);


CircularNode* createCircularLinkedList();
void displayCircularLinkedList(CircularNode* head);
CircularNode* insertNodeCircularLinkedList(CircularNode* head, Equip data, int position);
CircularNode* deleteNodeCircularLinkedList(CircularNode* head, int position);
CircularNode* searchCircularLinkedList(CircularNode* head, int value);

#endif