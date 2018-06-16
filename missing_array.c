#include <stdio.h>

int8_t missing_numbers(uint8_t array, uint8_t n)
{
uint8_t i;
uint8_t x1=0, x2=0;
for(i=0; i<n; i++)
{
  x2 = x2^ array[i];
}
 
for(i=0; i<n; i++)
{

x1 = x1^i;

}

return (x1^x2);
}

void main()
{

printf("enter the number of elements:", \n);
scanf("%d", n);
uint8_t array[] = {1,2,4,5,6,7,8,9,10};
printf("Result:%d", missing_numbers(array,n));

}
