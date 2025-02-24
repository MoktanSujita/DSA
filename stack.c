#include <stdio.h>
int MAXSIZE =8;
int stack[8];
int top=-1;
int isFull()
{
    if(top==MAXSIZE-1)
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
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data)
{
    if(!isFull)
    {
        top=top+1;
        stack[top]=data;
    }
    else
    {
        printf("Stack is full, Could not insert!");
    }
}
int pop()
{
    int data;
    if(!isEmpty)
    {
        data=stack[top];
        top=top-1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty");
    }
}
int peek()
{
    return stack[top];
}
void display()
{
    int i;
    if(!isEmpty)
    {
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
    else
    {
        printf("Empty stack!");
    }
}
void search(int element)
{
    for(int i=0;i<top;i++)
    {
        if(stack[i]==element)
        {
            printf("Element found at index no %d",i);
            return;
        }
        else
        {
            printf("Element not found!");
        }
    }
    
}
int main()
{
    push(5);
    push(10);
    push(15);
    push(10);
    push(55);
    push(44);
    push(12);
    push(6);
    push(33);
    printf("\n Element at the top :%d",peek());
    printf("\nElements of stack:\n " );
    display();
    printf("\n Popped element:%d",pop());
    printf("\nElement at top of the stack:%d",peek());
    printf("\nElements of the stack:\n");
    display();
    search(12);
    return 0;

}