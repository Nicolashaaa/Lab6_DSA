#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

void input(Equip *e) {
    printf("Enter number: ");
    scanf("%d", &e->num);
    printf("Enter type: ");
    scanf("%s", e->type);
    printf("Enter brand: ");
    scanf("%s", e->brand);
    printf("Enter color: ");
    scanf("%s", e->color);
    printf("Enter last inspection date (day month year): ");
    scanf("%d %d %d", &e->insp_date.day, &e->insp_date.month, &e->insp_date.year);
    printf("Enter owner type (1 for company, 2 for individual): ");
    int owner_type;
    scanf("%d", &owner_type);
    if (owner_type == 1) {
        printf("Enter company ID: ");
        scanf("%s", e->owner.company_id);
    } else {
        printf("Enter owner's first name: ");
        scanf("%s", e->owner.owner_name.first_name);
        printf("Enter owner's last name: ");
        scanf("%s", e->owner.owner_name.last_name);
    }
}

void display(const Equip *e) {
    printf("Number: %d\n", e->num);
    printf("Type: %s\n", e->type);
    printf("Brand: %s\n", e->brand);
    printf("Color: %s\n", e->color);
    printf("Last inspection date: %d-%d-%d\n", e->insp_date.day, e->insp_date.month, e->insp_date.year);
    printf("Owner: ");
    if (isdigit(e->owner.company_id[0])) {
        printf("Company ID: %s\n", e->owner.company_id);
    } else {
        printf("Individual: %s %s\n", e->owner.owner_name.first_name, e->owner.owner_name.last_name);
    }
}

void displayMenu() {
    printf("Choose an option:\n");
    printf("1. SIMPLE LINKED LIST operations\n");
    printf("2. DOUBLE LINKED LIST operations\n");
    printf("3. CIRCULAR LINKED LIST operations\n");
    printf("4. Exit\n");
}

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

Node* createSingleLinkedList() {
    return NULL; // Создаем пустой список
}

void displaySingleLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        display(&current->data);
        current = current->next;
    }
}

Node* insertNodeSingleLinkedList(Node* head, Equip data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* deleteNodeSingleLinkedList(Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

Node* searchSingleLinkedList(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.num == value) {
            return current;
        }
        current = current->next;
    }
    printf("Element with value %d not found in list.\n", value);
    return NULL;
}

DoubleNode* createDoubleLinkedList() {
    return NULL; // Создаем пустой список
}

void displayDoubleLinkedList(DoubleNode* head) {
    DoubleNode* current = head;
    while (current != NULL) {
        display(&current->data);
        current = current->next;
    }
}

DoubleNode* insertNodeDoubleLinkedList(DoubleNode* head, Equip data, int position) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    DoubleNode* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

DoubleNode* deleteNodeDoubleLinkedList(DoubleNode* head, int position) {
    if (head == NULL) {
        return NULL;
    }

    if (position == 0) {
        DoubleNode* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    DoubleNode* current = head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    DoubleNode* temp = current;
    if (current->next != NULL) {
        current = current->next;
    } else {
        current = current->prev;
    }
    free(temp);
    return head;
}

DoubleNode* searchDoubleLinkedList(DoubleNode* head, int value) {
    DoubleNode* current = head;
    while (current != NULL) {
        if (current->data.num == value) {
            return current;
        }
        current = current->next;
    }
    printf("Element with value %d not found in list.\n", value);
    return NULL;
}

CircularNode* createCircularLinkedList() {
    return NULL; // Создаем пустой список
}

void displayCircularLinkedList(CircularNode* head) {
    if (head == NULL) {
        return;
    }

    CircularNode* current = head;
    do {
        display(&current->data);
        current = current->next;
    } while (current != head);
}

CircularNode* insertNodeCircularLinkedList(CircularNode* head, Equip data, int position) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    CircularNode* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Invalid position!\n");
            return head;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

CircularNode* deleteNodeCircularLinkedList(CircularNode* head, int position) {
    if (head == NULL) {
        return NULL;
    }

    CircularNode* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current->next == head) {
            printf("Invalid position!\n");
            return head;
        }
    }

    CircularNode* temp = current->next;
    current->next = temp->next;
    if (temp == head) {
        head = current->next;
    }
    free(temp);
    return head;
}

CircularNode* searchCircularLinkedList(CircularNode* head, int value) {
    if (head == NULL) {
        return NULL;
    }

    CircularNode* current = head;
    do {
        if (current->data.num == value) {
            return current;
        }
        current = current->next;
    } while (current != head);

    printf("Element with value %d not found in list.\n", value);
    return NULL;
}
