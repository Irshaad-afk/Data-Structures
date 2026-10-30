
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* makeNode(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void display(Node *l) {
    while (l) {
        printf("%d\t", l->data);
        l = l->next;
    }
    printf("\n");
}

Node* insertTail(Node *l, int data) {
    if (!l)
        return makeNode(data);

    Node *temp = l;
    while (temp->next)
        temp = temp->next;

    temp->next = makeNode(data);
    return l;
}

int finalno(Node *l)
{
    int total=0;
    while(l)
    {
        total=total*100+l->data;
        l=l->next;
    }
    return total;
}

int main() {
    Node *l = NULL;
    printf("\nlist:\t");


    l = insertTail(l, 1);
    l = insertTail(l, 0);
    l = insertTail(l, 0);

    display(l);

    printf("The final Number: %d\t\n",finalno(l));


    return 0;
}

