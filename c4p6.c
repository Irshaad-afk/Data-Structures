#include <stdio.h>
#define SIZE 50
typedef enum{FALSE,TRUE}Bool;
typedef struct{
    char val[SIZE];
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
    return s.top==SIZE;
}

Bool push(Stack *s,char c)
{
    if(isFullS(*s))
        return FALSE;


    s->val[s->top]=c;
    s->top=s->top+1;
    return TRUE;
}

Bool pop(Stack *s,char *c)
{
    if(isEmptyS(*s))
        return FALSE;

    s->top=s->top-1;
    *c=s->val[s->top];

    return TRUE;
}
int main(){
    Stack s;
    s=createStack();
    char str[50];
    char ch;
    printf("Enter the string to check validity:");
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0'){
        push(&s,str[i]);
        i++;
    }
    i=0;
    while(str[i]!='\0'){
        pop(&s,&ch);
        if(ch!=str[i])
        {
            printf("Invalid");
            return 0;
        }
        i++;
    }
    if(isEmptyS(s)){
        printf("Valid");
    }
    else
        printf("Invalid");
}

