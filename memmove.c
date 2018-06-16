#include< stdio.h>
void my_memmove(uint8_t* dst, uint8_t* src, uint8_t n)
{

	if((src!= NULL ) && (dst != NULL) && (n>=0)
{
	 uint8_t i, flag=0;
	 for(i=0;i<n;i++)
	 {
	   if(dst==src+i)
	  {
		flag=1;
	   }
          
          }
          for(i=0; i<n; i++)
          {
           if(dst+length-1 == src+i)
	  {
	   flag=0;
	  }
          }
	  if(flag==0)
          {
	   for(i=0; i<n; i++)
	   {
            *(dst+i) = *(src+i);
           }
           }
           if(flag==1)
           {
             for(i=0;i<n;i++)
            {
              *(dst+length-1-i)= *(src+length-1-i);
	    }
            }
         
}
}

void main()
{

   char str[100];
  char *src = "Welcome home";
  my_memmove(str,src, strlen(src));
  printf("%s", str);

}
   
