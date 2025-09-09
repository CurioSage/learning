//PhonePay is an application for money transition online. The application stores „n‟ transaction
//details of users.As every user is very much interested to know his transaction details, write
//a program to display transactions performed by a user and transaction details of a particular
//transaction.
//Given: Transaction_ID, User_ID, Amount, Beneficiary_ID//

#include<stdio.h>
#include<stdlib.h>
typedef struct user
{
    int ti_d;
    char user_id[10];
    int amount;
    char ben_id[10];
}apar;
void main()
{
    apar *s;
    int n, tid;
    printf("value of n");
    scanf("%d",&n);
    s=(apar*)calloc(n,sizeof(apar));
    read(s,n);
    printf("enter the t id");
    scanf("%d",&tid);
    display(s,n,tid);
    free(s);


}
void read(apar *s,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the t_id %d\n",i+1);
        scanf("%d",&(s+i)->ti_d);
        printf("enter user id %d\n",i+1);
        scanf("%s",(s+i)->user_id);
        printf("enter amt %d\n",i+1);
        scanf("%d",&(s+i)->amount);
        printf("enter ben id %d\n",i+1);
        scanf("%s",(s+i)->ben_id);

    }
}
void display (apar *s,int n,int tid)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(tid==(s+i)->ti_d)
        {
        printf(" the t_id %d:%d\n",i+1,(s+i)->ti_d);
        printf("user id %d:%s\n",i+1,(s+i)->user_id);
        printf("amt %d:%d\n",i+1,(s+i)->amount);
        printf("ben id %d:%s\n",i+1,(s+i)->ben_id);
        exit(0);
        }

    }
}