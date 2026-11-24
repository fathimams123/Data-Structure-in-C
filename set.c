#include<stdio.h>
struct bit
{
 unsigned char x : 1;
};

int uset[]={1,2,3,4,5,6,7,8,9};
int size=9;

void readset(struct bit a[],int n)
{
 int i,x,k;
 printf("Enter %d element:",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  for(k=0;k<size;k++)
  {
   if(uset[k]==x)
   {
    a[k].x=1;
    break;
   }
  }
 }
}

void printset(struct bit a[])
{
 int k;
 printf("{");
 for(k=0;k<size;k++)
 {
  if(a[k].x==1)
   printf("%d",uset[k]);
 }
 printf("}\n");
}

void unionset(struct bit a[],struct bit b[],struct bit c[])
{
 int k;
 for(k=0;k<size;k++)
  c[k].x=a[k].x | b[k].x;
}

void intersect(struct bit a[],struct bit b[],struct bit c[])
{
 int k;
 for(k=0;k<size;k++)
  c[k].x=a[k].x & b[k].x;
}

void difference(struct bit a[],struct bit b[],struct bit c[])
{
 int k;
 for(k=0;k<size;k++)
  c[k].x=a[k].x & !b[k].x;
}

int main()
{
 struct bit a[9]={0},b[9]={0},c[9]={0};
 int n;
 printf("Number of elements in Set A:");
 scanf("%d",&n);
 readset(a,n);
 printf("Number of elements in Set B:");
 scanf("%d",&n);
 readset(b,n);
 printf("\nSET A");
 printset(a);
 printf("\nSET B");
 printset(b);
 unionset(a,b,c);
 printf("AUB=");
 printset(c);
 intersect(a,b,c);
 printf("A intersect B=");
 printset(c);
 difference(a,b,c);
 printf("A-B=");
 printset(c);
 return 0;
}
