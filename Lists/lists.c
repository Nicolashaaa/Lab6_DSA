#include "func.h"
#define MAX_SIZE 100

int main() {
    int choice, listType;
    Node* singleLinkedList = NULL;
    DoubleNode* doubleLinkedList = NULL;
    CircularNode* circularLinkedList = NULL;
    Equip equipment;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("SIMPLE LINKED LIST operations:\n");
                printf("1. Create list\n");
                printf("2. Display list\n");
                printf("3. Insert node\n");
                printf("4. Search by position/value\n");
                printf("5. Delete node\n");
                scanf("%d", &listType);

                switch (listType) {
                    case 1:
                        singleLinkedList = createSingleLinkedList();
                        break;
                    case 2:
                        displaySingleLinkedList(singleLinkedList);
                        break;
                    case 3:
                        input(&equipment);
                        printf("Enter position to insert: ");
                        int position;
                        scanf("%d", &position);
                        singleLinkedList = insertNodeSingleLinkedList(singleLinkedList, equipment, position);
                        break;
                    case 4:
                        printf("Enter value to search: ");
                        int value;
                        scanf("%d", &value);
                        Node* found = searchSingleLinkedList(singleLinkedList, value);
                        if (found != NULL) {
                            display(&found->data);
                        }
                        break;
                    case 5:
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        singleLinkedList = deleteNodeSingleLinkedList(singleLinkedList, position);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 2:
                printf("DOUBLE LINKED LIST operations:\n");
                printf("1. Create list\n");
                printf("2. Display list\n");
                printf("3. Insert node\n");
                printf("4. Search by position/value\n");
                printf("5. Delete node\n");
                scanf("%d", &listType);

                switch (listType) {
                    case 1:
                        doubleLinkedList = createDoubleLinkedList();
                        break;
                    case 2:
                        displayDoubleLinkedList(doubleLinkedList);
                        break;
                    case 3:
                        input(&equipment);
                        printf("Enter position to insert: ");
                        int position;
                        scanf("%d", &position);
                        doubleLinkedList = insertNodeDoubleLinkedList(doubleLinkedList, equipment, position);
                        break;
                    case 4:
                        printf("Enter value to search: ");
                        int value;
                        scanf("%d", &value);
                        DoubleNode* found = searchDoubleLinkedList(doubleLinkedList, value);
                        if (found != NULL) {
                            display(&found->data);
                        }
                        break;
                    case 5:
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        doubleLinkedList = deleteNodeDoubleLinkedList(doubleLinkedList, position);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 3:
                printf("CIRCULAR LINKED LIST operations:\n");
                printf("1. Create list\n");
                printf("2. Display list\n");
                printf("3. Insert node\n");
                printf("4. Search by position/value\n");
                printf("5. Delete node\n");
                scanf("%d", &listType);

                switch (listType) {
                    case 1:
                        circularLinkedList = createCircularLinkedList();
                        break;
                    case 2:
                        displayCircularLinkedList(circularLinkedList);
                        break;
                    case 3:
                        input(&equipment);
                        printf("Enter position to insert: ");
                        int position;
                        scanf("%d", &position);
                        circularLinkedList = insertNodeCircularLinkedList(circularLinkedList, equipment, position);
                        break;
                    case 4:
                        printf("Enter value to search: ");
                        int value;
                        scanf("%d", &value);
                        CircularNode* found = searchCircularLinkedList(circularLinkedList, value);
                        if (found != NULL) {
                            display(&found->data);
                        }
                        break;
                    case 5:
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        circularLinkedList = deleteNodeCircularLinkedList(circularLinkedList, position);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}