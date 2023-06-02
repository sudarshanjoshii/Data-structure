//STACKS USING ARRAY IMPLEMENTATION

#define MAX 5
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data[MAX];
    int top;
};
typedef struct stack stack;

int full(stack s)
{
    if(s.top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty(stack s)
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *s, int num)
{
    if(full(*s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top]=num;
    return;
}

int pop(stack *s)
{
    int temp;
    if(empty(*s))
    {
        printf("Stack Underflow\n");
    }
    temp=s->data[s->top];
    s->top--;
    return(temp);
}

void display(stack s)
{
    int x, i;
    if(empty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    for(i=s.top;i>=0;i--)
    {
        printf("\n%d\t",s.data[i]);
    }
}

int main()
{
    stack s;
    int ch, done=1, num, temp;
    s.top=-1;
    while(1)
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter the element to be pushed : ");
                scanf("%d",&num);
                push(&s,num);
            break;
        case 2:temp=pop(&s);
                if(temp==-1)
                {
                    printf("\n%d is popped\n",temp);
                }
            break;
        case 3: display(s);
            break;
        case 4: exit(0);
            break;
        default: done=0;
            break;
        }
    }
    return 0;
}
