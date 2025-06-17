#include<stdio.h>
#include<stdbool.h>

int swapp(int *fp,int *bp)
{
    int temp=*fp;
     *fp=*bp;
     *bp=temp;
    
}
int bubblesort(int arr[],int n)
{
    int i,j;
    bool swap;
    for(i=0;i<n-1;i++)
    {
        swap=false;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapp(&arr[j],&arr[j+1]);
                swap=true;
            }
        }
        if(swap==false)
        break; 
    }
}

void printarr(int arr[],int n)
{
    int i;
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int arr[]={12,4,3,66,77,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array:\n");
    printarr(arr,n);
    printf("sorted array:\n");
    bubblesort(arr,n);
    printarr(arr,n);
}