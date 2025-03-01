#include <stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top=-1;

int isFull()
{
    return (top==MAX_SIZE-1);
}

int isEmpty()
{
    return(top==-1);
}

void push(char c)
{
    if(!isFull())
    {
         stack[++top]=c;
    }
    else
    {
        printf("Stack is full, cannot enter data");
      
    }
}
char pop()
{
    if(!isEmpty())
    {
        return stack[top--];
    }
    else
    {
        printf("Stack is empty, cannot retrive data");
        return '\0';
    }

}
int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if (c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    else 
    {
        return 0;
    }
    
}

void reverseString(char * str)
{
    int i=0,j=strlen(str)-1;
    while (i<j)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    
}
char infixToPrefix(char infix[],char prefix[])
{
    int i,j;
     i=j=0;
    int infixlength=strlen(infix);

    reverseString(infix);
    while (i<infixlength)
    {
        char current=infix[i];
        if(isalnum(current))
        {
            prefix[j++]=current;
        }
        else if (current==')')
        {
            push(current);
        }
        else if (current =='(')
        {
            while (top!=-1 && stack[top]!=')')
            {
                prefix[j++]=pop();
            }
            if (top!=-1 && stack[top]==')')
            {
                pop();
            } 
        } 
        else 
        {
            while (precedence(current)<=precedence(stack[top]))
            {
                if(top==-1)
                {
                    break;
                }
                else
                {
                    prefix[j++]=pop();
                }
            }
            push(current);
        }
        i++;
        
    }
    


}
int main()
{
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    infixToPrefix(infix,prefix);
    printf("Infix Expression :%s",infix);
    printf("\nPrefix Expression:%s",prefix);
}