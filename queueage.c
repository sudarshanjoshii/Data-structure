#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct temple
{
    int age;
    struct temple *next;
};
typedef struct temple *q;

q create();
q enqueue(q head);
q dequeue(q head);
void display(q head);
void age(q head);

int main()
{
    q head=NULL;
    int i,n;
    printf("Enter the number of people : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=enqueue(head);
    }
    display(head);
    age(head);
}
q create()
{
    q n1;
    n1=(q)malloc(sizeof(struct temple));
    if(n1==NULL)
       {
           printf("Invalid");
           exit(0);
       }
       printf("enter the age : ");
       scanf("%d",&n1->age);
       n1->next=NULL;
       return n1;
}

q enqueue(q head)
{
    q temp,newNode;
    newNode=create();
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

q dequeue(q head)
{
    q cur, prev;
    prev=NULL;
    cur=head;
    if (head==NULL)
    {
      printf("Queue is empty\n");
    }
    else if (head->next==NULL)
    {
        printf("Deleted %d\n",head->age);
        free(head);
        head==NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=NULL;
        printf("Deleted %d\n",cur->age);
        free(cur);
    }
    return head;
}

void display(q head)
{
    q temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->age);
            temp=temp->next;
        }
        printf("\n");
    }
}

void age(q head)
{
    q temp;
    temp=head;
    if(head==NULL)
    {
        printf("Queue is empty\n");
    }
    while(temp!=NULL)
    {
        if((temp->age)>=60)
        {
            printf("People with age above 60 : %d \n",temp->age);

        }
        else if((temp->age)<60)
        {
            printf("People with age below 60 : %d \n",temp->age);

        }
        temp=temp->next;
    }
    printf("\n");
}
