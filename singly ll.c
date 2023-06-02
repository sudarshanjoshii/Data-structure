#include<stdio.h>
#include<stdlib.h>

struct web
{
    char webser[20];
    int yr;
    struct web *next;
};
typedef struct web *NODE;
NODE insert_end(NODE head);
void display(NODE head);
void count_display_year(NODE head);
int main()
{
    NODE head=NULL;
    int i,n;
    printf("enter the number of web series \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    display(head);
    count_display_year(head);
    return 0;
}
NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct web));
    if(newn==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("enter the name and year of release\n");
    scanf("%s%d",newn->webser,&newn->yr);
    newn->next=NULL;
    return newn;
}
NODE insert_end(NODE head)
{
    NODE cur=head;
    NODE newn=getnewnode();
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
            cur->next=newn;
    }
    return head;
}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("webseries list is empty\n");
        exit(0);
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%s %d\n",cur->webser,cur->yr);
            cur=cur->next;
        }
    }
}
void count_display_year(NODE head)
{
    NODE cur=head;
    int count=0,syear;
    printf("enter year to search\n");
    scanf("%d",&syear);
    if(head==NULL)
    {
        printf("webseries list is empty");
    }
    else
    {
        while(cur!=NULL)
        {
            if(cur->yr==syear)
            {
                printf("%s %d\n",cur->webser,cur->yr);
                count++;
            }
            cur=cur->next;
        }
        printf("%d\n",count);
    }
}
