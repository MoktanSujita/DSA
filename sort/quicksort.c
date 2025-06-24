#include<stdio.h>

void swap(int* fe,int* be)
{
    int temp=*fe;
    *fe=*be;
    *be=temp;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{
    int arr[]={44,21,12,66,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}