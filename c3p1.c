#include<stdio.h>
#define MAX_VAL 5
typedef enum{FALSE,TRUE}Bool;
typedef struct
{
    int val[MAX_VAL];
    int top;
}Stack;

Stack createstack();
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s, int val);
Bool pop(Stack *s, int *val);
int peek(Stack s);

int main()
{
    Stack s1;
    s1=createstack();
    isEmpty(s1);

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
    return s.top=MAX_VAL-1;
}

Bool push(Stack *s, int val)
{
    if(isFull(*s))
        return FALSE;
    s->top=s->top+1;
    s->val[s->top]=val;
    return TRUE;
}

Bool pop(Stack *s, int *val)
{
    if(isEmpty(*s))
        return FALSE;
    *val=s->val[s->top];
    s->top=s->top-1;
    return TRUE;
}

int peek(Stack s)
{
    if(isEmpty(s))
        return -9999;
    return s.val[s.top];
}




