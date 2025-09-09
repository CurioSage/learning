#include <stdio.h>
#include <stdlib.h>
#define MAX 7


typedef struct queue{
    int age[MAX];
    int f;
    int r;
}que;

int isfull(que *q){
    if(q->r==MAX-1){
        return 1;
    }
    else{
        return 0;
        
    }
}

int isempty(que *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
        
    }
}



int enqueue(que *q, int Age){
    if(isfull(q)==1){
        printf("The queue is full\n");
        return 0;
    }
    else{

    q->r++;
    q->age[q->r]=Age;
    return 1;
    }
}



int dequeue(que *q){
    int temp=-1;
    if(isempty(q)==1){
        printf("The queue is empty\n");
        return 0;
    }
else{
    int i;
    q->f++;
    // temp=;
    return q->age[q->f];
    }
    
}



int display(que *q){
    int temp=-1;
    if(isempty(q)==1){
        printf("The queue is empty\n");
        return 0;
    }
else{
    int i;
    for(i=q->f+1;i <= q->r;i++){
        printf("The custmoers with there age %d\n",q->age[i]);
    }
    }
    return 0;
}





int main(){
    
    int choice,temp;
    int Age;
    int amt=0,discount=0,t_amt=0;

    que *s= (que*)malloc(sizeof(que));
    s->f = s->r = -1;
    

    while(1){

    printf("Enteerr the choice\n1-Enter the age of customer\n2-Print your total cost of journey\n3-display Customers with their age\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 :printf("Enter customers age\n");
        scanf("%d",&Age);
        enqueue(s,Age);
        break;

        case 2 : printf("Enter the total cost of journey\n");
                scanf("%d",&amt);
        
        temp = dequeue(s);
        if(temp>60){
        discount = amt*0.5;
        t_amt=amt-discount;
        printf("Your total bill after discount is %d\n",t_amt);
        }
        else if (temp<6){
        printf("Your journey is free of cost\n");           
        }
        else{
        printf("Your total bill is %d\n",amt);
        }
        break;
        case 3 :display(s);
        break;
        default :printf("Enter the correct choice\n");
        exit(0);
        break;

}

}
}