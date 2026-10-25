#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

typedef enum
{
    FALSE,TRUE
}Bool;

typedef struct
{
    char V[MAX];
    int top;
}Stack;

void init(Stack *s)
{
    s->top=0;
}
Bool isEmpty(Stack *s)
{
    return s->top==0;
}
Bool isFull(Stack *s)
{
    return s->top==MAX;
}
Bool push(Stack *s,char c)
{
    if(isFull(s))
    {
        return FALSE;
    }
    s->V[s->top]=c;
    s->top++;
}
char pop(Stack *s)
{
    if(isEmpty(s))
        return FALSE;

    s->top--;
    return s->V[s->top];
}

char peek(Stack *s)
{
    if(isEmpty(s))
    {
        return FALSE;
    }
    return s->V[s->top-1];
}

Bool isOp(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='?'||c=='^'||c=='!'||c==':');
}

void intopost(char *infix,char *postfix)
{
    Stack s;
    init(&s);
    int i=0,k=0;
    char c;
    for(i=0;infix[i]!='\0';i++)
    {
        c=infix[i];
        if(isalnum(c))
        {
            postfix[k++]=c;
        }
         else if(c=='(')
        {
            continue;
        }
        else if(isOp(c))
        {
            push(&s,c);
        }
        else if(c==')')
        {
            if(!isEmpty(&s))
            {
                 postfix[k++] = pop(&s);
            }
        }
    }
    while(!isEmpty(&s))
    {
        postfix[k++]=pop(&s);
    }
    postfix[k]='\0';

}

int main()
{
    char in[MAX],post[MAX];
    printf("Enter the infix:");
    scanf("%s",in);

    intopost(in,post);
    printf("Postfix: %s",post);
    return 0;
}