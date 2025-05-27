#include <stdio.h>
int hanoi(int n,int from,int to,int via)
{
    if(n==1)
    {
        printf("Move disk 1 from rod %d to %d",from,to);
        return;
    }
    else
    {
        hanoi(n-1,from,via,to);
        printf("\nMove disk from %d to %d\n",from,to);
        hanoi(n-1,via,to,from);
    }
}
int main()
{
    int n=3;
    int from=1,to=3,via=2;
    hanoi(n,from,to,via);

}