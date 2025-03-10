#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;               // Data field to store the value
    struct Node* next;      // Pointer to the next node in the list
};
struct LinkedList 
{
    struct Node* head;
};
struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;      // Initialize head as NULL (empty list)
    return list;
};


void insertFront(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = data;   // Assign the given data to the new node
    newNode->next = list->head; // Point new node to current head
    list->head = newNode;   // Update head to new node
    printf("%d inserted at the front of the list.\n", data);
    printf("Current head: %d\n", list->head->data); // Print the new head
}


void insertEnd(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = data;   // Assign the given data to the new node
    newNode->next = NULL;   // Set new node's next to NULL (as it will be the last node)

    if (list->head == NULL) { // If list is empty, make newNode the head
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) { // Traverse to the last node
            current = current->next;
        }
        current->next = newNode; // Update last node's next pointer to new node
    }
    printf("%d inserted at the end of the list.\n", data);
    printf("Current head: %d\n", list->head->data); // Print the head
}

void update(struct LinkedList* list, int oldValue, int newValue) {
    struct Node* current = list->head;
    while (current != NULL) { // Traverse the list
        if (current->data == oldValue) { // If oldValue is found, update it
            current->data = newValue;
            printf("Value %d updated to %d\n", oldValue, newValue);
            printf("Current head: %d\n", list->head->data); // Print the head
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list.\n", oldValue);
}

void display(struct LinkedList* list) {
    if (list->head == NULL) { // If list is empty
        printf("List is empty.\n");
        return;
    }
    struct Node* current = list->head;
    printf("List: ");
    while (current != NULL) { // Traverse the list
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() 
{
    struct LinkedList* list = createLinkedList(); // Create an empty linked list

    insertFront(list, 5);     
    insertFront(list, 10);    // Insert 10 at the front
    insertEnd(list, 15);  
    display(list);
    
    update(list,5,20);
    return 0;
}