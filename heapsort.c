/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r= 2*i +2;
    if(l<n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r<n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != i) 
    {
       int temp = arr[i];
       arr[i] = arr[largest];
       arr[largest]= temp;
       heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n)
{
    for(int i= (n/2)-1; i>=0; i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp = arr[0];
        arr[0]= arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}
int main()
{
    int arr[] = {12,23,11,3,7,25,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,size);
    printf("The sorted array is \n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
