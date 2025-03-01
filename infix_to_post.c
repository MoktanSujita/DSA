#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100
char stack[MAX_SIZE];
int top=-1;

int isEmpty()
{
    return (top==-1);
}
int isFull()
{
    return (top == MAX_SIZE -1);
}
char pop()
{
    if(!isEmpty())
    {
        return stack[top--];
    }
    else
    {
        printf("The stack is empty, could not pop!");
        return '\0';
    }
}
void push(char c)
{
    if(!isFull())
    {
        stack[++top]=c;
    }
    else
    {
        printf("The stack is full, couldn't enter!");
    }
}
int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if (c=='*' || c== '/')
    {
        return 2;
    }
    else if (c=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    
    
}
void infixToPostfix(char infix[], char postfix[])
{
   int i,j;
   i=j=0;
   int infixlength=strlen(infix);
   while (i<infixlength)
   {
   
       char current=infix[i];
       if(isalnum(current))
    {
        postfix[j++]=current;
    }
    else if(current =='(')
    {
        push(current);
    }
    else if (current ==')')
    {
        
        while (top!=-1 && stack[top] !='(')
        {
            postfix[j++]=pop();
        }
        if(top !=-1 && stack[top]=='(')
        {
            pop();
        }
    }
    
    else
    {
        while (precedence(current)<=precedence(stack[top]))
        {
            if (top==-1)
            {
                break;
            }
            else
            {
                postfix[j++]=pop();
            }
            
        }
        push(current);

    }
    i++;
   }
   while(top !=-1)
   {
     postfix[j++]=pop();
   }
   postfix[j]='\0';
   
   
}
int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter the infix operation:");
    scanf("%s",&infix);
    infixToPostfix(infix, postfix);
    printf("Infix expression:%s\n",infix);
    printf("Postfix expression:%s\n",postfix);
    return 0;
}