#include <stdio.h>
#include<ctype.h>
#define MAX 50
typedef enum
{
    FALSE,TRUE
}Bool;

typedef struct
{
    char val[MAX];
    int top;
}Stack;

Stack createStack()
{
    Stack s;
    s.top=0;
    return s;
}

Bool isEmptyS(Stack s)
{
    return s.top==0;
}

Bool isFullS(Stack s)
{
    return s.top==MAX;
}

Bool push(Stack *s,char ch)
{
    if(isFullS(*s))
        return FALSE;


    s->val[s->top]=ch;
    s->top=s->top+1;
    return TRUE;
}

Bool pop(Stack *s,char *ch)
{
    if(isEmptyS(*s))
        return FALSE;

    s->top=s->top-1;
    *ch=s->val[s->top];

    return TRUE;
}
int validation(char *c)
{
    Stack s;
    s=createStack();

    for(int i=0;c[i]!='\0';i++)
    {
        char ch= c[i];

        if(isupper(ch))
        {
            push(&s, ch);
        }
        else if(islower(ch))
        {
            if(isEmptyS(s))
            {
                return FALSE;
            }
            char call;
            pop(&s,&call);
            if(call+32 != ch)
            {
                return FALSE;
            }
        }
    }
    return isEmptyS(s);
}

int main()
{
    char alpha[MAX];
    printf("Enter the sequence of alphabets:");
    scanf("%s",alpha);

    if(validation(alpha))
         printf("Valid");
    else
         printf("Not Valid");

    return 0;
}

