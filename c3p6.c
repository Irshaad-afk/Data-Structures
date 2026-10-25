#include<stdio.h>
#define MAX_VAL 20
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
    int i=0;
    printf("enter string:");
    scanf("%s",str);

    while(str[i]!='.')
    {
        push(&s1,str[i]);
        i++;
    }
    i++;
    while(str[i]!='\0')
   {
       if(isEmpty(s1))
       {
           printf(" not valid");
           return 0;
       }
       pop(&s1,&ch);
       if(ch!=str[i])
       {
           printf("not valid");
           return 0;
       }
       i++;
     }
   if(isEmpty(s1))
   {
       printf("The given is valid");
   }
   else{
    printf(" It is not valid");

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







