#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[10];
    int roll_no;
    char div;
    int sem;
    char USN[10];
    long long int phone;

};
void read(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %c %d %s %lld", (s+i)->name,&(s+i)->roll_no,(s+i)->div,(s+i)->sem,(s+i)->USN,&(s+i)->phone);
    }
}


void display(struct student *s, int n)
{
    for (int i = 0; i < n; i++){
        printf("%s %d %c %d %s %lld\n",&(s+i)->name,(s+i)->roll_no,(s+i)->div,(s+i)->sem,(s+i)->USN,(s+i)->phone);
    }
}



int main()
{
    struct student *s;
    int n;
    printf("enter the student number\n");
    scanf("%d",&n);
    s = (struct student*)malloc(n*sizeof(struct student)) ;
    read(s,n);
    display(s,n);
    free(s);
    return 0;
} 