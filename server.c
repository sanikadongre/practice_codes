#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

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

void main()
{
	int sock;
	struct sockaddr_in server, client;
	int mysock;
	char buff[1024];
	int rval;
	mystruct_t my_obj;
	mystruct_t * ptr;

	//create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("Failed to create a socket");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);
	
	//bind
	if(bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("Didn't bind");
		exit(1);

	}

	//Listen
	if(listen(sock, 5) < 0)
	{
		perror("Listening error");
		exit(1);
	}

	//Accept
	mysock = accept(sock, (struct sockaddr *)0, 0);
	if(mysock == -1)
	{
		perror("accept failed");
		exit(1);
	}

	int data_in = read(mysock,buff,sizeof(mystruct_t));
     
	if (data_in < 0)
	{ 
		perror("Error reading");
		exit(1);
	}
	ptr = (mystruct_t*)(buff);
	printf("Hello from server\n");
        printf("Message: %s, Message length = %d, LED: %d\n", ptr->my_string, ptr->my_string_length, ptr->LED_Control);
	ptr = &my_obj;

    	strcpy(my_obj.my_string, "Message sent by server\n");
    	my_obj.my_string_length = strlen(my_obj.my_string);
    	my_obj.LED_Control = 1;

    	int data_out = write(mysock,ptr,sizeof(mystruct_t));
	if (data_out < 0)
	{
		perror("Error writing");
		exit(1);
	}
	exit(1);
}
