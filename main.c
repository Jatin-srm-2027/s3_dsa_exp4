#include <stdio.h>

#define MAX_SIZE 100  // Define the maximum size of the array

typedef struct {
    int arr[MAX_SIZE];
    int size;
} ListADT;

// Function to initialize the list
void initialize(ListADT *list) {
    list->size = 0;
}

// Function to insert an element at the end of the list
void insert(ListADT *list, int element) {
    if (list->size >= MAX_SIZE) {
        printf("List is full. Cannot insert more elements.\n");
        return;
    }
    list->arr[list->size++] = element;
}

// Function to print the list
void printList(ListADT *list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

// Function to delete an element from the list
void delete(ListADT *list, int element) {
    int i, j;
    int found = 0;

    for (i = 0; i < list->size; i++) {
        if (list->arr[i] == element) {
            found = 1;
            // Shift elements to the left to remove the element
            for (j = i; j < list->size - 1; j++) {
                list->arr[j] = list->arr[j + 1];
            }
            list->size--;
            i--;  // Adjust index after deletion
        }
    }

    if (found) {
        printf("Element %d deleted from the list.\n", element);
    } else {
        printf("Element %d not found in the list.\n", element);
    }
}

// Function to search for an element in the list
void search(ListADT *list, int target) {
    int found = 0;

    for (int i = 0; i < list->size; i++) {
        if (list->arr[i] == target) {
            found = 1;
            printf("Element %d found at index %d.\n", target, i);
        }
    }

    if (!found) {
        printf("Element %d not found. Inserting it at the end of the list.\n", target);
        insert(list, target);
    }
}

int main() {
    ListADT list;
    initialize(&list);
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Insert an element\n");
        printf("2 - Print the list, delete an element, print the list\n");
        printf("3 - Print the list, search for an element, print the list\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(&list, element);
                break;

            case 2:
                printList(&list);
                printf("Enter element to be deleted: ");
                scanf("%d", &element);
                delete(&list, element);
                printList(&list);
                break;

            case 3:
                printList(&list);
                printf("Enter element to be searched: ");
                scanf("%d", &element);
                search(&list, element);
                printList(&list);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
