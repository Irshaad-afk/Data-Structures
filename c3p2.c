#include<stdio.h>
#include<stdlib.h>
#define MAX_VAL 20
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
void print(Stack s1);

int main()
{
    Stack s1,s2;
    s1=createstack();
    s2=createstack();
    int n,a;
    printf("enter n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a=rand()%10;
        if(a%2==0)
        {
            push(&s2,a);
        }
        else
        {
           push(&s1,a);
        }
    }
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

Bool pop(Stack *s,int *val)
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

void Copy(Stack or,Stack co)
{
    while(!isEmpty(or))
    {
        push(&co,peek(or));
        pop(&or,peek(or));
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



