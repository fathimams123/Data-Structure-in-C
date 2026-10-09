#include<stdio.h>
int main()
{
 int a,b,temp;
 printf("Enter two numbers:");
 scanf("%d %d",&a,&b);
 printf("Before Swapping, First Number: %d\nSecond Number:%d",a,b);
 temp=a;
 a=b;
 b=temp;
 printf("\nAfter Swapping, First Number: %d\nSecond Number:%d",a,b);
 return 0;
}
