#include<stdio.h>
#define SIZE 10

int q[SIZE];
int front=0, rear=0;

void insertq(int item)
{
 if((rear+1)%SIZE==front)
  printf("Queue is full\n");
 else
 {
  rear=(rear+1)%SIZE;
  q[rear]=item;
  printf("Inserted %d \n",item);
 }
}

void deleteq()
{
 if(front==rear)
  printf("Queue is empty.\n");
 else
 {
  front=(front+1)%SIZE;
  printf("Deleted item %d\n",q[front]);
 }
}

void searchq(int item)
{
 int i=(front+1)%SIZE;
 int pos=1;
 while(i!=(rear+1)%SIZE)
 {
  if(q[i]==item)
  {
   printf("Found at pos %d\n",pos);
   return;
  }
  i=(i+1)%SIZE;
  pos++;
 }
 printf("Not found\n");
}

int main()
{
 int item,opt=0;
 while(opt!=4)
 {
  printf("1.Insert\n2.Delete\n3.Search\n4.Exit\nOption:");
  scanf("%d", &opt);
  switch(opt)
  {
   case 1:
    printf("Data:");
    scanf("%d",&item);
    insertq(item);
    break;
    
   case 2:
    deleteq();
    break;
    
   case 3:
    printf("Number to search:");
    scanf("%d",&item);
    searchq(item);
    break;
   case 4:
    printf("Program ended.\n");
    break;
    
   default: printf("Invalid Option..\n");
  }
 }
 return 0;
}

