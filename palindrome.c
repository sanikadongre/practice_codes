#include <stdio.h>
#include <string.h>

void palindrome_find(char* s)
{

if(s== NULL)
{
printf("invalid string \n");
}
uint8_t char_start, char_end;
uint8_t stringlength = strlen(s);

for(char_start = 0, char_end = stringlength-1; char_start < char_end; char_start++, char_end--)
{
if s[char_start] != s[char_end]
{
printf("Not a palindrome\n");
}
}
printf(" %s is palindrome", s);
}
void main()
{
char *s = "madam";
palindrome_find(s);
}
