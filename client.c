#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

#define DATA "Hello world"

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

void main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char buff[1024];
	struct hostent *hp;
	char msg[] = "Hello from Client";
	
	mystruct_t my_obj;
	mystruct_t * myptr;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket failed");
		exit(1);
	}
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if(hp == 0)
	{
		perror("gethost failed");
		exit(1);
	}
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(5000);
	
	if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("connection failes");
		exit(1);
	}

	myptr = &my_obj;
        strcpy(my_obj.my_string,msg);
        my_obj.my_string_length = strlen(my_obj.my_string);
        my_obj.LED_Control = LED_ON;
	
	if(send(sock, (void*)&my_obj, sizeof(my_obj), 0) < 0)
	{
		perror("Send failed");
		exit(1);
	}
	printf("Sent : %s \n", msg);

	int data_in = read(sock,buff,sizeof(my_obj));
        if (data_in < 0)
	{	 
        	perror("Send failed");
		exit(1);
	}
	myptr = (mystruct_t*)(buff);
	printf("Message received by Client. \n");
    	printf("Message: %s, Message length = %d, LED: %d\n", myptr->my_string, myptr->my_string_length, myptr->LED_Control);

	close(sock);
}
