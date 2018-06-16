 
CC=gcc
 
CFLAGS= -O3 -lpthread -lrt

SWAP_BITS_EXE= swap_bits_code

CFILES= swap_bits.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

build:	${SWAP_BITS_EXE}

clean:	-rm -f ${SWAP_BITS_EXE} 

swap_bits_code:		swap_bits.o
	$(CC) $(CFLAGS) -o swap_bits_code swap_bits.o


 


