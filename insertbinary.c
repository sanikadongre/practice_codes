#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node* newnode(int value)
{
      struct node* temp = (struct node*)malloc(sizeof(struct node));
      node->key = value;
      node->right= NULL;
      node->left = NULL;
      return temp;
}
void traverse_func(struct node* root)
{
      if(root!=NULL)
      {
           traverse_func(root->left);
           printf("%d \n", root->key);
           traverse_func(root->right);
       }
}

struct node* insert_func(struct node* node, int key)
{
        if(node==NULL)
        {
            return newnode(key);
        }
        if(key > node->key)
        {
            node->right = insert_func(node->right, key);
        }
        else if(key< node->key)
        {
              node->left = insert_func(node->left, key);
        }
        return node;
  }
  
 void main()
  {
          struct mode* root = NULL;
          root = insert_func(root, 45);
          insert(root, 70);
          insert(root,65);
          insert(root, 80);
          insert(root, 95);
          insert(root, 12);
          insert (root, 25);
          traverse_func(root);
  }
  
  
  
          
        
      
