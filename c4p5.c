#include <stdio.h>
#define SIZE 50
typedef enum{FALSE,TRUE}Bool;
typedef struct{
    char val[SIZE];
    int front;
    int rear;
}Q;
Q create(){
    Q q;
    q.front=0;
    q.rear=0;
    return q;
}
Bool isEmpty(Q q){
    return (q.front==q.rear);
}
Bool isFull(Q q){
    return ((q.rear+1)%SIZE==q.front);
}
Bool insert(Q *q, char x)
{
    if(isFull(*q)) return FALSE;
    q->rear=(q->rear+1)%SIZE;
    q->val[q->rear]=x;
    return TRUE;
}
Bool del(Q *q,char *val){
    if(isEmpty(*q)) return FALSE;
    q->front=(q->front+1)%SIZE;
    *val=q->val[q->front];
    return TRUE;
}
void print(Q q){
    if(isEmpty(q)) return;
    int i = (q.front + 1) % SIZE;
    while(i != (q.rear + 1) % SIZE) {
        printf("%c\t", q.val[i]);
            i = (i + 1) % SIZE;
    }
}

int main(){
    Q q;
    q=create();
    char str[50];
    printf("Enter the string to check validity:");
    scanf("%s",str);
    char ch;int i=0;
    while(str[i] != '.'){
        insert(&q,str[i]);
        i++;
    }
    i++;
    while(str[i] != '.' && str[i] != '\0'){
        if(isEmpty(q)) {printf("Invalid"); return 0;}
        del(&q,&ch);
        if(ch!=str[i]){
            printf("Invalid");
            return 0;
        }
        insert(&q,ch);
        i++;
    }
    if(str[i]=='.')
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
