#include<stdio.h>
int search(int arr[],int n,int e)
{
    for(int i = 0;i < n; i++)
    {
        if(arr[i] == e)
        return i;
    }
    return -1;
}
int main()
{
    int arr[]={24,16,99,4};
    int e=99;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=search(arr,n,e);
    (i==-1)
    ?printf("Element not found")
    :printf("Element found at %d",i);
}