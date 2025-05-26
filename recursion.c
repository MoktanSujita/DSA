#include<stdio.h>

int checkPrime(int i,int num);
int main()
{
    int num;
    printf("Enter your number:");
    scanf("%d",&num);

    if((checkPrime(2,num))==0)
    printf("The number is prime!");
    else
    printf("The number is not prime!");
}

int checkPrime(int i,int num)
{
    if(num==1)
    return 0;

    else if ((num%i)==0)
        return 1;
    
    else
    checkPrime(i+1,num);
    
}