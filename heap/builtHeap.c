#include <stdio.h>
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]<largest)
    largest=left;

    if(right<n && arr[right]<largest)
    right=right;

    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=largest;
        largest=temp;

        heapify(arr,n,i);
    }
}
void builtheap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i++)
    {
        heapify(arr,n,i);
    }
}
void printHeap(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int arr[]={1,4,5,8,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    printHeap(arr,n);

    printf("Max-heap:");
    printHeap(arr,n);

    return 0;
}
