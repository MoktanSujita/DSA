#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

int countNode(struct Node* head)
{
    int count=0;
    struct Node* current=head;

    while (current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int main()
{
    struct Node* head=createNode(10);
    head->next=createNode(20);
    head->next=createNode(14);

    int length=countNode(head);

    printf("The length of the nodes is %d",length);
    return 0;
}
