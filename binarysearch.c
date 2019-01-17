#include <stdio.h>
int binary_search(int arr[], int l, int r, int x)
{
    if(r>=l)
    {
      int mid;
      mid = l+ (r-l)/2;
      if(arr[mid] == x)
       {
        return mid;
       }
       if(arr[mid] > x)
       {
         return binary_search(arr, l, mid-1, x);
       }
       return binary_search(arr, mid+1, r, x);
       }
       return -1;
   }
   
   int main()
   {
      int arr[] = {2,4,10,20,50,78,54,100,3};
      int n= sizeof(arr)/ sizeof(arr[0]);
      int x = 54;
      int result =  binary_search(arr,0, n-1, x);
      if(result == -1)
      {
        printf("%d is not present in the array",x);
       }
       else
       {
          printf("%d is present at the position %d in the array", x, result);
       }
       return 0;
       
      }
