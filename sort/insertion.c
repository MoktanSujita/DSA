#include<stdio.h>
int insertionsort(int arr[],int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
}
int printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int arr[]={23,1,10,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    printf("sorted array:\n");
    printarr(arr,n);
}