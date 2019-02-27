#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
 
int flag = 0;

typedef struct
{
    char my_string[20];
    int my_string_length;
    int LED_Control;
}mystruct_t;

typedef enum
{
    LED_ON = 0,
    LED_OFF = 1
}led_enum;

int main()
{
    pid_t p;
    int pipe_p2c[2];			//parent to child
    int pipe_c2p[2];			//child to parent
 
    if (pipe(pipe_p2c)==-1)
    {
        perror("Pipe error\n");
        return 1;
    }
    if (pipe(pipe_c2p)==-1)
    {
        perror("Pipe error\n");
        return 1;
    }
 
    p = fork();
 
    if (p < 0)
    {
        perror("Fork error\n");
        return 1;
    }
 
    else if (p > 0)
    {
	printf("In Parent Process\n");
        char msg[] = "Hello from Parent";
        mystruct_t my_obj;

        strcpy(my_obj.my_string,msg);
        my_obj.my_string_length = strlen(my_obj.my_string);
        my_obj.LED_Control = LED_ON;
 
        write(pipe_p2c[1], &my_obj, sizeof(my_obj));		//write p to c
        printf("Message sent to child\n");
 	printf("\n");
        wait(NULL);

 	printf("Again In Parent Process\n");
        char my_buffer[sizeof(mystruct_t)];
        mystruct_t *my_ptr;

        read(pipe_c2p[0], my_buffer, sizeof(mystruct_t));	//read from child

        my_ptr = (mystruct_t*)my_buffer;
        printf("Message from Child\n");
	printf("Message: %s\nMessage Length: %d\nLED: %d\n",my_ptr->my_string,my_ptr->my_string_length,my_ptr->LED_Control);
	printf("\n");
    }
    else
    {
        printf("In Child Process\n");
 
        char my_buffer[sizeof(mystruct_t)];
        mystruct_t *my_ptr;

        read(pipe_p2c[0], my_buffer, sizeof(mystruct_t));	//read from parent
 
        my_ptr = (mystruct_t*)my_buffer;
        printf("Message from Parent\n");
	printf("Message: %s\nMessage LengTH: %d\nLED: %d \n",my_ptr->my_string,my_ptr->my_string_length,my_ptr->LED_Control);
	printf("\n");

        char msg[] = "Hello from Child";
        mystruct_t my_obj;

        strcpy(my_obj.my_string,msg);
        my_obj.my_string_length = strlen(my_obj.my_string);
        my_obj.LED_Control = LED_OFF;
 
        write(pipe_c2p[1], &my_obj, sizeof(my_obj));		//write
        printf("Message sent to parent\n");
	printf("\n");
 	flag = 1;
        exit(0);
    }
}
