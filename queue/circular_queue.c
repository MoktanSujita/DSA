#include <stdio.h>

#define SIZE 5

int item[SIZE];
int front =-1,rear=-1;

int isFull()
{
   if((front==rear+1)|| (front==0 && rear==SIZE-1))
   {
    return 1;
   }
   else
   {
    return 0;
   }
   
}

int isEmpty()
{
    if(front == -1)
    {
        return -1;
    }
    else
    return 0;
}
int deQueue()
{
    int element;
    if(isEmpty())
    {
        printf("\n Queue is empty!\n");
        return -1;
    }
    else
    {
        element=item[front];
        if(front == rear)
        {
            front =-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%SIZE;
        }
        printf("\nDeleted Element :%d",element);
        return (element);  
    } 
}

int enQueue()
{
    int element;
    if(isFull())
    {
        printf("\nQueue Overflow!");
        return -1;
    }
    else
    {
        if(front ==-1) front=0;
        rear=(rear+1)%SIZE;
        item[rear]=element;
        printf("\nInserted element:%d",element);
        
    }
    
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("\nBeep! Beep! Empty Queue");
    }
    else
    {
        printf("\n Front: %d",front);
        printf("\n Items :");
        for ( i = front; i!=rear;i=(i+1)%SIZE)
        {
            printf("%d\n",item[i]);
        }
        printf("%d",item[i]);
        printf("\n Rear :%d\n",rear);
        
    }
    
}
int main()
{
    //fails to dequeue as the queue is empty
    deQueue();

    enQueue(1);
    enQueue(3);
    enQueue(15);
    enQueue(44);
    enQueue(8);

   //fails to enQueue/insert element as the queue is full
    enQueue(12);

    display();
    deQueue();

    enQueue(12);
    display();

    return 0;


}