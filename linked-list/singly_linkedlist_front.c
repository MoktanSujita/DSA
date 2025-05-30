#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct linkedlist
{
    struct Node* head;
};

struct linkedlist* createlinkedlist()
{
    struct linkedlist* list=(struct Node*)malloc(sizeof(struct Node));
    list->head=NULL;
    return list;
}

void insertFront(struct linkedlist* list,int data)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=list->head;
    list->head=newnode;
    printf("%d inserted at the front of the list\n",data);
    printf("Current head:%d",list->head->data);
}

void deleteFront(struct linkedlist* list)
{
    if(list->head==NULL)
    {
        printf("The list is already empty");
        return;
    }
    else
    {
        struct Node* temp=list->head;
        list->head=list->head->next;
        printf("Deleted %d from the list\n",temp);
        free(temp);
    }
}

void display(struct linkedlist* list)
{
    if(list->head==NULL)
    {
        printf("list is empty");
        return;
    }
    else
    {
        struct Node* current=list->head;
        printf("list:");
        while (current!=NULL)
        {
            printf("%d",current->data);
            current=current->next;
        }
        printf("\n");
        
    }
}

int main()
{
    struct linkedlist* list=createlinkedlist();

    insertFront(list,10);
    insertFront(list,22);
    insertFront(list,41);

    display(list);

    deleteFront(list);
    display(list);
}

