#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left,*right;
};

struct node* insert(struct node *root,int x)
{
 if(root==NULL)
 {
  root=malloc(sizeof(struct node));
  root->data=x;
  root->left=root->right=NULL;
 }
 else if(x<root->data)
  root->left=insert(root->left,x);
 else if(x>root->data)
  root->right=insert(root->right,x);
 else
  printf("Duplicate Value\n");
  
 return root;
}

void display(struct node *root)
{
 if(root!=NULL)
 {
  display(root->left);
  printf("%d\t",root->data);
  display(root->right);
 }
}

void search(struct node *root,int x)
{
 if(root==NULL)
  printf("Not Found..\n");
 else if(root->data==x)
  printf("Found..\n");
 else if(x<root->data)
  search(root->left,x);
 else
  search(root->right,x);
}

struct node* minimum(struct node *root)
{
 while(root->left!=NULL)
  root=root->left;
 return root;
}

struct node* delete(struct node *root,int x)
{
 if(root==NULL)
  return NULL;
 if(x<root->data)
  root->left=delete(root->left,x);
 else if(x>root->data)
 root->right=delete(root->right,x);
 else
 {
  struct node *temp;
  if(root->left==NULL)
  {
   temp=root->right;
   free(root);
   return temp;
  }
  if(root->right==NULL)
  {
   temp=root->left;
   free(root);
   return root;
  }
  temp=minimum(root->right);
  root->data=temp->data;
  root->right=delete(root->right,temp->data);
 }
 return root;
}

int main()
{
 struct node *root=NULL;
 int ch,x;
 while(1)
 {
  printf("\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit\nEnter Choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
        printf("Enter Value:");
        scanf("%d",&x);
        root=insert(root,x);
        break;
   case 2:
        display(root);
        break;
   case 3:
        printf("Enter Value:");
        scanf("%d",&x);
        search(root,x);
        break;
   case 4:
        printf("Enter Value:");
        scanf("%d",&x);
        root=delete(root,x);
        break;
   case 5:
        exit(0);
   default:printf("Wrong Choice...\n");
  }
 }
 return 0;
}
