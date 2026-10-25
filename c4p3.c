#include <stdio.h>
#define MAX 5
typedef enum
{
    FALSE,TRUE
}Bool;
typedef struct{
    char val[MAX];
    int front;
    int rear;
}Queue;

Queue create(){
    Queue q;
    q.front=0;
    q.rear=0;
    return q;
}

Bool isEmpty(Queue q)
{
    return (q.front==q.rear);
}

Bool isFull(Queue q)
{
    return ((q.rear+1)%MAX==q.front);
}

Bool insert(Queue *q, char x)
{
    if(isFull(*q))
        return FALSE;
    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=x;
    return TRUE;
}

Bool del(Queue *q,char *val)
{
    if(isEmpty(*q))
        return FALSE;
    q->front=(q->front+1)%MAX;
    *val=q->val[q->front];
    return TRUE;
}
void print(Queue q)
{
    if(isEmpty(q))
        return;
    int i = (q.front + 1) % MAX;
    while(i != (q.rear + 1) % MAX) {
        printf("%c\t", q.val[i]);
            i = (i + 1) % MAX;
    }
}

int main(){
    Queue q;
    q=create();
    char str[50];
    printf("Enter the string to check validity:");
    scanf("%s",str);
    char ch;int i=0;
    while(str[i] != '.' && str[i] != '\0'){
        insert(&q,str[i]);
        i++;
    }
    i++;
    while(str[i]!='\0'){
    if(isEmpty(q)) {printf("Invalid"); return 0;}
        del(&q,&ch);
        if(ch!=str[i]){
            printf("Invalid");
            return 0;
        }
    i++;
    }
    if(isEmpty(q))
        printf("Valid");
    else
        printf("Invalid");
}