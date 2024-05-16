#include "equipment.h"
#define MAX_SIZE 100


int main() {
    Stack myStack;
    Queue myQueue;
    initStack(&myStack);
    initQueue(&myQueue);
    int choice, stackOrQueue;
    Equip equipment;
    int position, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Stack operations:\n");
                printf("1. Create stack\n");
                printf("2. Display stack\n");
                printf("3. Insert element\n");
                printf("4. Search by position/value\n");
                printf("5. Delete element\n");
                scanf("%d", &stackOrQueue);

                switch (stackOrQueue) {
                    case 1:
                        initStack(&myStack);
                        break;
                    case 2:
                        displayStack(&myStack);
                        break;
                    case 3:
                        input(&equipment);
                        push(&myStack, equipment);
                        break;
                    case 4:
                        printf("Enter position or value to search: ");
                        scanf("%d", &value);
                        Equip found = searchStackByValue(&myStack, value);
                        display(&found);
                        break;
                    case 5:
                        printf("Enter position or value to delete: ");
                        scanf("%d", &value);
                        Equip removed = popByValue(&myStack, value);
                        display(&removed);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 2:
                printf("Queue operations:\n");
                printf("1. Create queue\n");
                printf("2. Display queue\n");
                printf("3. Insert element\n");
                printf("4. Search by position/value\n");
                printf("5. Delete element\n");
                scanf("%d", &stackOrQueue);

                switch (stackOrQueue) {
                    case 1:
                        initQueue(&myQueue);
                        break;
                    case 2:
                        displayQueue(&myQueue);
                        break;
                    case 3:
                        input(&equipment);
                        enqueue(&myQueue, equipment);
                        break;
                    case 4:
                        printf("Enter position or value to search: ");
                        scanf("%d", &value);
                        Equip found = searchQueueByValue(&myQueue, value);
                        display(&found);
                        break;
                    case 5:
                        printf("Enter position or value to delete: ");
                        scanf("%d", &value);
                        Equip removed = dequeueByValue(&myQueue, value);
                        display(&removed);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

