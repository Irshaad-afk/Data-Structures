#include<stdio.h>
#define MAX_VAL 10
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
Bool balanced(char str[]);

int main()
{
    Stack s1;
    char str[MAX_VAL];
    s1=createstack();


    printf("enter string:");
    scanf("%s",str);

    if (balanced(str))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;

}

Bool balanced(char str[])
{
    Stack s = createstack();
    char ch;
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            push(&s, '(');
        }
        else if(str[i] == ')')
        {
            if(isEmpty(s))
                return FALSE;

            pop(&s, &ch);
        }
    }

    return isEmpty(s);
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








