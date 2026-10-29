#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* makeNode(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void display(Node *l) {
    if (!l) {
        printf("Empty List\n");
        return;
    }

    Node *temp = l;
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != l);

    printf("\n");
}

Node* insertTail(Node *l, int data) {
    Node *temp = makeNode(data);

    if (!l)
        return temp;

    Node *last = l;
    while (last->next != l)
        last = last->next;

    temp->next = l;
    last->next = temp;

    return l;
}

int searchps(Node *l, int data) {
    if (!l)
        return -1;

    Node *temp = l;
    Node *prev = NULL;
    int pos =1;

    while(temp->next!=l)
    {
        temp = temp->next;
    }
    prev=temp;

    temp =l;
    do {
        if (temp->data == data)
          {
              printf("\nPredecessor :%d \n",prev->data);
              printf("successor: %d \n",temp->next->data);
              return pos;

          }
        prev=temp;
        temp = temp->next;
        pos++;
    }
    while (temp != l);
       return -1;
}

Node* reverse(Node *l) {
    if (l == NULL || l->next == l)
        return l;

    Node *prev = NULL;
    Node *curr = l;
    Node *next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != l);

    l->next = prev;
    l = prev;

    return l;
}
int countnodes(Node *l)
{
    if (!l)
        return 0;

    int count = 1;
    Node *temp = l->next;

    while (temp != l) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node *l = NULL;
    printf("Inserted list:\n");

    l = insertTail(l, 40);
    l = insertTail(l, 50);
    l = insertTail(l, 60);
    l = insertTail(l, 70);
    l = insertTail(l, 80);
    display(l);
    printf("position of 60: %d \n",searchps(l, 80));

    printf("\nReverse of the list:\n");
    l = reverse(l);
    display(l);

    printf("\nThe count: %d \n",countnodes(l));

    return 0;
}
