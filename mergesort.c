/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
  int i,j,k, paraml, paramr;
  paraml = m-l+1;
  paramr = r-m;
  int L[paraml], R[paramr]; 
  for(int i=0; i<paraml; i++)
  {
      L[i] = arr[l+i];
  }
  for(int j=0; j<paramr; j++)
  {
      R[j] = arr[m+1+j];
  }
  i=0, j=0, k=l;
  while(i< paraml && j< paramr)
  {
     if(L[i] <= R[j])
     {
         arr[k] = L[i];
         i++;
     }
     else
     {
        arr[k] = R[j];
        j++;
      }
      k++;
   }
   while(i< paraml)
   {
      arr[k] = L[i];
      i++;
      k++;
    }
    while(j< paramr)
    {
        arr[k] = R[j];
        j++;
        k++;
     }
   }
   
   void mergesort(int arr[], int l, int r)
   {
      if(l<r)
      {
          int m;
          m= l+(r-l)/2;
          mergesort(arr,l,m);
          mergesort(arr,m+1, r);
          merge(arr,l,m,r);
          
         }
         
     }
     
     void print_array(int A[], int n)
     {
        for(int i=0; i<n; i++)
        {
          printf("%d ", A[i]);
        }
        printf("\n");
      }
      
      int main()
      {
          int arr[] = {12,11,87,6,5,4};
          int size_arr = (sizeof(arr)/sizeof(arr[0]));
          printf("The array before sorting is\n");
          print_array(arr, size_arr);
          mergesort(arr, 0, size_arr-1);
          printf("The sorted array is\n");
          print_array(arr,size_arr);
          return 0;
       }
