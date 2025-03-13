#include <stdio.h>

int fact(int );

int main()
{
    int num;
    int f=1;
    printf("Enter the number:\n");
    scanf("%d",&num);
    f=fact(num);
    
    printf("\nFactorial:%d",f);
    return 0;
}
 int fact(int a)
 {
    if(a<=1)
       return 1;
    else
       return (a*fact(a-1));
 }
