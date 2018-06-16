#include <stdio.h>
unsigned int swap_bits(unsigned int num)
{

	unsigned int even = num & 0xAAAAAAAA;
	unsigned int odd = num & 0x55555555;
	even >>= 1;
	odd <<= 1;
	unsigned int out = even|odd;
        return out;
}

void main()
{

	unsigned int num = 56;
	unsigned int output = swap_bits(num);
	printf("After swapping the bits the result is %u", output);
}

