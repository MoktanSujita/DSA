#include<stdio.h>

int rem,revnum=0;
int findReverse(int num)
{
    if(num)
    {
        rem=num%10;
        revnum=(revnum*10)+rem;
         findReverse(num/10);
    }
    else
     return revnum;

    return revnum;
}
int main()
{
    int num;
    printf("Enter any number:");
    scanf("%d",&num);

    printf("The reverse of the number:%d",findReverse(num));
    return 0;
}
