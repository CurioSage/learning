#include<stdio.h>
void count(int *a,int n,int *e_count,int *o_count)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(*(a+i)%2==0)
        {
            (*e_count)++;
        }
        else
        {
            (*o_count)++;
        }
    }
}
void read(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
}
int main()
{
    int n,even=0,odd=0;
    scanf("%d",&n);
    int a[n];
    read(a,n);
    count(a,n,&even,&odd);
    printf("even = %d and odd = %d",even,odd);


}
