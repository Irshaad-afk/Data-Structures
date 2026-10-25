#include<stdio.h>
#include<stdlib.h>
#define MAX_VAL 10
typedef enum{FALSE,TRUE}Bool;
typedef struct
{
    int arr[MAX_VAL];
    int top;
}Stack;

Stack createstack();
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s, int val);
Bool pop(Stack *s, int *val);
int peek(Stack s);
void copy(Stack *or,Stack *co);
void print(Stack s1);



int main()
{
    Stack s1,s2;
    s1=createstack();
    s2=createstack();
    int x;
   // printf("enter n:");
    //scanf("%d",n);
    for(int i=0;i<10;i++)
    {
       x=rand()%10;
       push(&s1,x);
    }
    copy(&s1,&s2);
    print(s1);
    print(s2);

    return 0;

}
Stack createstack()
{
    Stack s;
    s.top=0;
    return s;
}
Bool isEmpty(Stack s)
{
    return s.top==0;
}

Bool isFull(Stack s)
{
    return s.top==MAX_VAL;
}

Bool push(Stack *s, int val)
{
    if(isFull(*s))
        return FALSE;
    s->arr[s->top]=val;
    s->top=s->top+1;

    return TRUE;
}

Bool pop(Stack *s, int *val)
{
    if(isEmpty(*s))
        return FALSE;
    s->top=s->top-1;
    *val=s->arr[s->top];
    return TRUE;
}

int peek(Stack s)
{
    if(isEmpty(s))
        return -9999;
    return s.arr[s.top-1];
}

void copy(Stack *or,Stack *co)
{
    Stack temp;
    int x;
    temp=createstack();
    while(!isEmpty(*or))
    {
        x=peek(*or);
        push(&temp,x);
        pop(or,&x);
    }
    while(!isEmpty(temp))
    {
        x=peek(temp);
        push(co,x);
        push(or,x);
        pop(&temp,&x);
    }
}

void print(Stack s1)
{
    int x;
    while(!isEmpty(s1))
    {
        x=peek(s1);
        printf("%d ",x);
        pop(&s1,&x);
    }
    printf("\n");
}




