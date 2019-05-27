#include <stdio.hh>
#include <stdlib.h>
struct Node
{
     int data;
     struct Node* next;
 };
 void push(struct Node** head_ref, int new_data)
 {
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      new_node->data = new_data;
      new_node->next = (*head_ref);
      (*head_ref) = new_node;
      
 }
  
 void insertafter(struct Node* prevnode, int new_data)
 {
    if(prevnode==NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
     }
     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      new_node->data = new_data;
      new_node->next = prev_node->next;
      prev_node->next = new_node;
    }
    
  void insertend(struct Node** head_ref, int new_data)
  {
  
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      struct Node* last = *head_ref;
      new_node->data = new_data;
      new_node->next = NULL;
      if(*head_ref==NULL)
      {
          *head_ref = new_node;
          return;
       }
       while(last->next!=NULL)
       {
            last = last->next;
            
         }
         last->next = new_node;
         return;
         
      }
   
      void print_list(struct Node* node)
      {
          while(node!=NULL)
          {
              printf("%d ", node->data);
              node= node->next;
              
            }
            
        }
        
        int main()
        {
            struct Node* head = NULL;
            insertend(&head,6);
            push(&head, 2);
            push(&head,4);
            insertend(,3);
            insertafter(head->next,7);
            print_list(head);
            return 0;
            
          }
