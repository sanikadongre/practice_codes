#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

static void reverse(Struct Node** head_ref)
{
    struct Node* prev= NULL;
    struct Node* next = NULL;
    struct Node* current = *head_ref;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
       
      }
      *head_ref = prev;
     }
     
     void push(struct Node** head_ref, int new_data)
     {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node=>next = (*head_ref);
        (*head_ref)= new_node;
        
       }
       
       void print_list(struct Node* head)
       {
          struct Node* temp= head;
          while(temp!=NULL) \
          {
            printf("%d ", temp->data);
            temp = temp_>next;
            
            }
            
         }
         
         int main()
         {
            struct Node* head = NULL;
            push(&head,20);
            push(&head,5);
            push(&head,25);
            push(&head,77);
            printf("The linked list is \n");
            print_list(head);
            printf("|n reverse linked list \n");
            print_list(head);
            getchar();
            
          }
