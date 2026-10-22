#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};

struct node *sp=NULL;

void push(int item)
{
 struct node *t=malloc(sizeof(struct node));
 t->data=item;
 t->next=sp;
 sp=t;
}

int pop(int *status)
{
 struct node *t;
 int item;
 if(sp==NULL)
 {
  *status=0;
  printf("Empty Stack..\n");
  return 0;
 }
 t=sp;
 item=t->data;
 sp=sp->next;
 free(t);
 *status=1;
 return item;
}

int search(int item)
{
 struct node *t=sp;
 int count=0;
 while(t!=NULL)
 {
  count++;
  if(t->data==item)
   return count;
  t=t->next;
 }
 return 0;
}

int main()
{
 int opt,item,ans,status;
 while(1)
 {
  printf("\n1.Push\n2.Pop\n3.Search\n4.Exit\n");
  printf("Option:");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:printf("Data:");
          scanf("%d",&item);
          push(item);
          printf("\nInserted %d\n",item);
          break;
          
  case 2:item=pop(&status);
         if(status)
          printf("\n%d is deleted \n",item);
         break;
         
  case 3:printf("Searching:");
         scanf("%d",&item);
         ans=search(item);
         if(ans==0)
          printf("\nItem not found..\n");
         else
          printf("\nFound at %d node\n",ans);
         break;
         
   case 4:return 0;
  }
 }
}
