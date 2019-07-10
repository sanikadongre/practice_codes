#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    struct node* right;
    int key;
    
 };
 
struct node* search(struct node* root, int key)
{
    if(root==NULL|| root->key == key)
    {
          return root;
          
    }
    if(root->key > key)
    {
          return search(root->left, key);
          
    }
    else
    {
        return search(root->right, key);
        
     }
     
  }
