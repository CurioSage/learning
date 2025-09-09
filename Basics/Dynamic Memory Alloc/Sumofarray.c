#include<stdio.h>
#include<stdlib.h>
void read(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
}
void display(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(a+i));
    }
}
void add(int *a,int n,int *add)
{
    for(int i=0;i<n;i++)
    {
        (add)=(add) + *(a+i);
    }
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);

    int *a;
    a=(int*)calloc(n,sizeof(int));
    read(a,n);
    display(a,n);
    add(a,n,&sum);
    printf("\n%d",sum);
}