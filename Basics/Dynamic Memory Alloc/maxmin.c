#include<stdio.h>
#include<stdlib.h>
void read(int *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
}
void max_min(int *p,int n)
{
    int i,max=0,min=*p;
    for(i=0;i<n;i++)
    {
        if(max<*(p+i)) //*(p+i)>max
        {
            max=*(p+i);
        }
        else
        {
            min=*(p+i);
        }
    }
    printf("the min =  %d and max = %d ",min,max);
}
int main()
{
    int n,*p;
    printf("enter the array size");
    scanf("%d",&n);
    p=(int *)calloc(n,sizeof(int));
    read(p,n);
    max_min(p,n);
    free(p);
    return 0;
}