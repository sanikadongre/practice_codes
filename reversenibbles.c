#include <stdio.h>
#include <stdint.h>

uint32_t reverse_nibbles (uint32_t x)
{
    
    uint32_t output=0,i;
    for(i=0;i<4;++i)
    {
        const uint8_t byte_val = (x>>8*i)&0xff;
        output|=(byte_val << (24-8*i));
    }
    return output;
}

void main()
{
    uint32_t t=15, output=0;
    output=reverse_nibbles(t);
    printf("output is %ld\n",output);
}
