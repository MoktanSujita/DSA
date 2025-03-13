#include<stdio.h>

int fibo(int a);//declaration of a fibonacci function


int main()
{
  int num;
  printf("Enter the number of terms:\n");
  scanf("%d",&num);
  
  for (int i = 0; i <= num; i++)
  {
    printf("/n %d\n",fibo(i));//function call
  }
  return 0;
}

int fibo(int a)
{
    if (a==0)
        return 0;
    else if (a==1)
        return 1;
    else
        return (fibo(a-1)+fibo(a-2));
}