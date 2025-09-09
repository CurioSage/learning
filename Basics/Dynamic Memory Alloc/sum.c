#include<stdio.h>
#include<stdlib.h>
void sum(int *,int *,int *,int *);
void sum(int *p,int *q,int *r,int *adds){
    *adds=*p+*q+*r;
    printf("sum is %d",*adds);

}

void main(){
    int *p,*q,*r,*adds;
    p=(int *)calloc(1,sizeof(int));
    q=(int *)calloc(1,sizeof(int));
    r=(int *)calloc(1,sizeof(int));
    adds=(int *)calloc(1,sizeof(int));
    scanf("%d%d%d",p,q,r);
    sum(p,q,r,adds);
    free(p);
    free(q);
    free(r);
    free(adds);


}



