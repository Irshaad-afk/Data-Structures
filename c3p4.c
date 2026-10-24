#include<stdio.h>
#define MAX_VAL 5
typedef enum{FALSE,TRUE}Bool;
typedef struct
{
    char arr[MAX_VAL];
    int top;
}Stack;

Stack createstack();
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s, char val);
Bool pop(Stack *s, char *val);
char peek(Stack s);


int main()
{
    Stack s1;
    char str[MAX_VAL];
    s1=createstack();
    char ch;
    int i;
    printf("enter string:");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
        push(&s1,str[i]);
    }
    printf("reverse:\n");
    while(!isEmpty(s1))
    {
        pop(&s1,&ch);
        printf("%c ",ch);
    }

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

Bool push(Stack *s, char val)
{
    if(isFull(*s))
        return FALSE;
    s->arr[s->top]=val;
    s->top=s->top+1;

    return TRUE;
}

Bool pop(Stack *s, char *val)
{
    if(isEmpty(*s))
        return FALSE;
    s->top=s->top-1;
    *val=s->arr[s->top];
    return TRUE;
}

char peek(Stack s)
{
    if(isEmpty(s))
        return -9999;
    return s.arr[s.top-1];
}






