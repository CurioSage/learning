#include<stdio.h>
#include<stdlib.h>
int read(int *ptr,int n)
{
    
    for(int i=0;i<n;i++)
    {
        scanf("%d", (ptr+i));
    }
    return 0;
}

int display(int *ptr,int n)
{
    
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(ptr+i));
    }
    return 0;
}

int count(int *ptr,int n)
{
    int i,even=0,odd=0;
    for(i=0;i<n;i++)
    {
        if(*(ptr+i)%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("even=%d and odd=%d\n",even,odd);
    return 0;
}



int main()
{
    int n,*ptr;
    scanf("%d",&n);
    int a[n];
    ptr = (int *)malloc(n*sizeof(int));
    read(ptr,n);
    count(ptr,n);
    display(ptr,n);
    free(ptr);

}
