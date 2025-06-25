#include<stdio.h>
int search(int arr[],int low,int high,int e)
{
    if(high>=low)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==e)
        return mid;

        if(arr[mid]>e)
        return search(arr,low,mid-1,e);

        return search(arr,mid+1,high,e);
    }
    return -1;
}

int main()
{
    int arr[]={12,44,88,99,100};
    int n=sizeof(arr)/sizeof(arr[0]);
    int e=44;
    int i=search(arr,0,n-1,e);
    (i == -1)
    ? printf("Element couldn't be found")
    : printf("Element found at %d",i);
    return 0;
}