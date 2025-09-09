#include<stdio.h>
#include<stdlib.h>
void fact(int *,int *);
void main()
{
    int *ptr,*c;
    ptr=(int *)calloc(1,sizeof(int));
    c=(int *)calloc(1,sizeof(int));
    printf("a=");
    scanf("%d",ptr);
    fact(ptr,c);
    printf("fact=%d\n",*c);
}
void fact(int *a,int*c)
{
  int i;
  *c=1;
  for(i=*a;i>=1;i--)
  {
     (*c)=(*c)*i;
  }
}