SinglyLinkedListNode* insertNode(SinglyLinkedListNode* head, int data)
{
      SinglyLinkedListNode* new_node= (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
      SinglyLinkedListNode* last = head;
      new_node->data = data;
      new_node->next = NULL;
      if(head==NULL)
      {
          head= new_node;
          return head;
          
        }
        
        while(last->next!=NULL)
        {
            last=last->next;
             
          }
          last->next = new_node;
          
      return head;
      
      }
