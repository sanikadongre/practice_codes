#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
  );
  
  void recursiverev(struct Node** head_ref)
  {
        struct Node* first;
        struct Node* rest;
        if(*head_ref==NULL)
          return;
         first = *head_ref;
         rest = first->next;
         if(rest==NULL)
            return;
          recursiverev(&rest);
          first->next->next = first;
          first->next= NULL;
          *head_ref= rest;
          
    }
      
