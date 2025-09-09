#include<stdio.h>
struct student
{
    char name[10];
    int roll;
    char div[2];
    int sem;
    char usn[10];
    float cgpa;
    long  long int phone;

};
void main()
{
    struct student *s;
   int n;
   printf("N value:");
   scanf("%d",&n);
   s=(struct stduent *)malloc(n*sizeof(struct student));
   read(s,n);
   display(s,n);

}
void read(struct student *s,int n)
{
    printf("Enter the name,rollno,division,sem,usn,phone number and CGPA\n");
    for(int i=0;i<n;i++)
  {
      printf("Student %d:\n",i+1);
      scanf("%s %d %s %d %s %lld %f",(s+i)->name,&(s+i)->roll,(s+i)->div,&(s+i)->sem,(s+i)->usn,&(s+i)->phone,&(s+i)->cgpa);
  }

}
void display(struct student *s,int n)
{
      for(int i=0;i<n;i++)
    {
        if((s+i)->cgpa>8)
        {
        printf(" name:%s roll:%d div:%s sem:%d usn:%s %lld",(s+i)->name,(s+i)->roll,(s+i)->div,(s+i)->sem,(s+i)->usn,(s+i)->phone,(s+i)->cgpa);
        }

    }

}