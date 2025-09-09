#include<stdio.h>
struct student{
    char name[10];
    int roll_no;
    char div;
    int sem;
    char USN[10];
    long long int phone;

};
void read(struct student s1[], int n)
{
    for (int i = 0; i < n; i++){
        scanf("%s%d%c%d%s%d", &s1[i].name,&s1[i].roll_no,&s1[i].div,&s1[i].sem,&s1[i].USN,&s1[i].phone;
    }
}


void display(struct student s1[], int n)
{
    for (int i = 0; i < n; i++){
        printf("%s%d%c%d%s%d", s1[i].name,s1[i].roll_no,s1[i].div,s1[i].sem,s1[i].USN,s1[i].phone;
    }
}



int main(){
    struct student s[10];
    int n=2;
    read(s,n);
    display(s,n);

}