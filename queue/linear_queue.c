#include<stdio.h>
#define SIZE 5

int items[SIZE];
int front=-1,rear=-1;

int enQueue(int value)
{
    if(rear==SIZE-1)
    {
        printf("Overflow!Overflow!");
        return 0;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        items[rear]=value;
        printf("\nInserted:%d",value);
    }
}

int deQueue()
{
    if(front==-1)
    {
        printf("\nNo element in queue!\n");
    }
    else
    {
        printf("Deleted element:%d",items[front]);
        front++;
        if(front>rear)
        {
            front=rear-1;
        }
    }
}

void display()
{
    if (rear==-1)
    {
        printf("\nEmpty Queue\n");
    }
    else
    {
        int i;
        printf("\nQueue Elements:\n");
        for ( i = front; i <= rear; i++)
        {
            printf("\n%d\n",items[i]);
        }
        
    }
    
}
int main()
{
    //Since the queue is empty,nothing will be dequeued
    deQueue();

    enQueue(5);
    enQueue(10);
    enQueue(13);
    enQueue(33);
    enQueue(43);

    //Queue overflow!!
    enQueue(13);
    
    display();
    deQueue();

    display();
    enQueue(13);

    display();

}
