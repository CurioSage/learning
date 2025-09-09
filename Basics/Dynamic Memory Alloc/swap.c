#include<stdio.h>
#include<stdlib.h>
// int read(int *ptr,int n)
// {
    
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d", (ptr+i));
//     }
//     return 0;
// }
void swap(int *p, int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
    printf("A=%d amd B= %d",*p,*q);

}

int main(){
    int *p,*q;
    p=(int *)malloc(1*sizeof(int));
    q=(int *)malloc(1*sizeof(int));
    scanf("%d%d",p,q);
    printf("A = %d and B = %d\n",*p,*q);
    printf("After swapping\n");
    swap(p,q);
    free(p);
    free(q);
    return 0;
}



