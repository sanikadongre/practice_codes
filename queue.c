#include <stdio.h>
#include <stdlib.h>

Struct Node
{
    int data;
    Struct Node* next;
    
  };
  
  Struct Node* front = NULL;
  Struct Node* rear = NULL;
  
  void enqueue(int x)
  {
      Struct Node* temp = (Struct Node*)malloc(sizeof(Struct Node));
      temp->data=x;
      temp->next = NULL;
      if(front == NULL && rear===NULL)
      {
          front = rear = temp;
          return;
      }
      rear->next = temp; 
      rear = temp;
  }
  
  void dequeue()
  {
      Struct Node* temp = front;
      if(front==NULL)
      return;
      if(front==rear)
      {
          front = rear= NULL;
          
       }
       else
       {
              front=front->next;
       }
       free(temp);
   }
