#include <stdio.h>
#include <ctype.h>

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

void displayMenu() {
    printf("Choose an option:\n");
    printf("1. Stack operations\n");
    printf("2. Queue operations\n");
    printf("3. Exit\n");
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

// Структура для элемента стека или очереди
typedef struct {
    Equip data;
} Node;

// Структура стека
typedef struct {
    Node items[MAX_SIZE];
    int top; // индекс вершины стека (последний добавленный элемент)
} Stack;

// Структура очереди
typedef struct {
    Node items[MAX_SIZE];
    int front; // индекс начала очереди (первый элемент)
    int rear; // индекс конца очереди (следующее место для добавления элемента)
} Queue;

// Функция инициализации стека
void initStack(Stack *s) {
    s->top = -1; // инициализируем вершину стека как пустую
}

// Функция инициализации очереди
void initQueue(Queue *q) {
    q->front = -1; // инициализируем начало очереди
    q->rear = -1; // инициализируем конец очереди
}

// Функция добавления элемента в стек
void push(Stack *s, Equip e) {
    if (s->top < MAX_SIZE - 1) {
        s->top++;
        s->items[s->top].data = e;
    } else {
        printf("Stack is full!\n");
    }
}

// Функция добавления элемента в очередь
void enqueue(Queue *q, Equip e) {
    if (q->rear < MAX_SIZE - 1) {
        if (q->front == -1) {
            q->front = 0; // установка начала очереди при первом добавлении элемента
        }
        q->rear++;
        q->items[q->rear].data = e;
    } else {
        printf("Queue is full!\n");
    }
}

// Функция поиска элемента по позиции в стеке
Equip searchStackByPosition(const Stack *s, int position) {
    if (position >= 0 && position <= s->top) {
        return s->items[position].data;
    } else {
        printf("Invalid position!\n");
        Equip emptyEquip = {0};
        return emptyEquip;
    }
}

// Функция поиска элемента по значению в стеке
Equip searchStackByValue(const Stack *s, int value) {
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i].data.num == value) {
            return s->items[i].data;
        }
    }
    printf("Element with value %d not found in stack.\n", value);
    Equip emptyEquip = {0};
    return emptyEquip;
}

// Функция поиска элемента по позиции в очереди
Equip searchQueueByPosition(const Queue *q, int position) {
    if (position >= q->front && position <= q->rear) {
        return q->items[position].data;
    } else {
        printf("Invalid position!\n");
        Equip emptyEquip = {0};
        return emptyEquip;
    }
}

// Функция поиска элемента по значению в очереди
Equip searchQueueByValue(const Queue *q, int value) {
    for (int i = q->front; i <= q->rear; i++) {
        if (q->items[i].data.num == value) {
            return q->items[i].data;
        }
    }
    printf("Element with value %d not found in queue.\n", value);
    Equip emptyEquip = {0};
    return emptyEquip;
}


// Функция удаления элемента по позиции из стека
Equip popByPosition(Stack *s, int position) {
    Equip removedEquip = {0};
    if (position >= 0 && position <= s->top) {
        removedEquip = s->items[position].data;
        for (int i = position; i < s->top; i++) {
            s->items[i].data = s->items[i + 1].data;
        }
        s->top--;
    } else {
        printf("Invalid position!\n");
    }
    return removedEquip;
}

// Функция удаления элемента по значению из стека
Equip popByValue(Stack *s, int value) {
    Equip removedEquip = {0};
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i].data.num == value) {
            removedEquip = s->items[i].data;
            for (int j = i; j < s->top; j++) {
                s->items[j].data = s->items[j + 1].data;
            }
            s->top--;
            return removedEquip;
        }
    }
    printf("Element with value %d not found in stack.\n", value);
    return removedEquip;
}

// Функция удаления элемента из очереди
Equip dequeueByPosition(Queue *q, int position) {
    Equip removedEquip = {0};
    if (position >= q->front && position <= q->rear) {
        removedEquip = q->items[position].data;
        for (int i = position; i < q->rear; i++) {
            q->items[i].data = q->items[i + 1].data;
        }
        q->rear--;
    } else {
        printf("Invalid position!\n");
    }
    return removedEquip;
}

// Функция удаления элемента по значению из очереди
Equip dequeueByValue(Queue *q, int value) {
    Equip removedEquip = {0};
    for (int i = q->front; i <= q->rear; i++) {
        if (q->items[i].data.num == value) {
            removedEquip = q->items[i].data;
            for (int j = i; j < q->rear; j++) {
                q->items[j].data = q->items[j + 1].data;
            }
            q->rear--;
            return removedEquip;
        }
    }
    printf("Element with value %d not found in queue.\n", value);
    return removedEquip;
}


// Функция отображения содержимого стека
void displayStack(const Stack *s) {
    printf("Stack:\n");
    for (int i = s->top; i >= 0; i--) {
        display(&s->items[i].data);
    }
}

// Функция отображения содержимого очереди
void displayQueue(const Queue *q) {
    printf("Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        display(&q->items[i].data);
    }
}

// Функция для записи данных в файл
void registerToFile(const char *filename, const void *data, int size, int binaryMode) {
    FILE *file;
    if (binaryMode) {
        file = fopen(filename, "wb");
        if (!file) {
            printf("Error opening file!\n");
            return;
        }
        fwrite(data, size, 1, file);
    } else {
        file = fopen(filename, "w");
        if (!file) {
            printf("Error opening file!\n");
            return;
        }
        fprintf(file, "%s", (char *)data);
    }
    fclose(file);
}

// Функция для чтения адреса файла с клавиатуры
void readFileName(char *filename) {
    printf("Enter filename: ");
    scanf("%s", filename);
}