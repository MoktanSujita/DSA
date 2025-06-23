#include<stdio.h>

int selectionsort(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index=i;
        for (int j = i+1; j<n; j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
        
    }
    
}
int printarr(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
}

int main()
{
    int arr[]={66,34,55,12,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    printf("Sorted array:\n");
    printarr(arr,n);
}