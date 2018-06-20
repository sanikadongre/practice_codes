#include <stdio.h>

#include <stdint.h>

 

int16_t add_1(int16_t num)

{
   return (-(~num));

}
 



void main()

{
  
printf("%d\n", addOne(-15));
 
printf("%d", addOne(15));
  

}
