#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define queue_name 		"/my_queue"
#define queue_size		8

typedef struct{
    char my_string[20];
    int my_string_length;
    int LED_Control;
}data;

typedef enum
{
	LED_ON,
	LED_OFF
}LED_Enum;

int main()
{
	mqd_t myqueue;

	struct mq_attr myqueue_attr;
	myqueue_attr.mq_maxmsg = queue_size;
	myqueue_attr.mq_msgsize = sizeof(data);

	myqueue = mq_open(queue_name, O_CREAT | O_RDWR, 0666, &myqueue_attr);		//open queue

	if(myqueue == (mqd_t)-1)
	{
		perror("Queue opening error");
		exit(1);
	}

	char msg[] = "Hello from Process1";
    	data Sent_data;

    	strcpy(Sent_data.my_string,msg);
    	Sent_data.my_string_length = strlen(Sent_data.my_string);
    	Sent_data.LED_Control = LED_OFF;

	int ret = mq_send(myqueue, (char*)&Sent_data, sizeof(Sent_data),0);		//send message
	if(ret == -1)
	{
		perror("Send error");
		exit(1);
	}
	printf("Message sent to process2 is:\n");
	printf("Message: %s\nMessage Length: %d\nLED: %d\n",Sent_data.my_string,Sent_data.my_string_length,Sent_data.LED_Control);
	printf("\n");

    	data Received_data;

	ret = mq_receive(myqueue, (char*)&Received_data, sizeof(Received_data), 0);	//receive message
	if(ret == -1)
	{
		perror("Receive error");
		exit(1);
	}
	printf("Message received from process2 is:\n");
    	printf("Message: %s\nMessageLen: %d\nLED: %d\n",Received_data.my_string,Received_data.my_string_length,Received_data.LED_Control);
	printf("\n");

	mq_close(myqueue);
	mq_unlink(queue_name);								//close queue
	return 0;
}
