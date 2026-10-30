
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

int findPos(Node *l, int val) {
    int pos = 1;
    while (l) {
        if (l->data == val)
            return pos;
        l = l->next;
        pos++;
    }
    return -1;
}

Node* inSort(Node *l, int data) {
    if (!l || l->data > data) {
        Node *temp = makeNode(data);
        temp->next = l;
        return temp;
    }

    l->next = inSort(l->next, data);
    return l;
}

Node* delSort(Node *l, int data) {
    if (!l)
        return l;

    if (l->data > data)
        return l;

    if (l->data == data) {
        Node *temp = l->next;
        free(l);
        return temp;
    }

    l->next = delSort(l->next, data);
    return l;
}

Node* reverse(Node *l) {
    Node *curr = l;
    Node *prev = NULL;

    while (curr) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main() {
    Node *l = NULL;

    printf("\nInserting in sorted list:\n");
    l = inSort(l, 25);
    display(l);

    l = inSort(l, 5);
    display(l);

    l = inSort(l, 60);
    display(l);

    l = inSort(l, 80);
    display(l);

    l = inSort(l, 30);
    display(l);

   // printf("\nDeleting from sorted list:\n");
    printf("\nDeleting 25 from sorted list:\t");
    l = delSort(l, 25);
    display(l);
    printf("\nDeleting 5 from sorted list:\t");
    l = delSort(l, 5);
    display(l);


    printf("\nAscending Order:\t");
    display(l);

    printf("Descending Order:\t");
    l=reverse(l);
    display(l);



    /* Free remaining nodes */
    while (l) {
        Node *temp = l;
        l = l->next;
        free(temp);
    }

    return 0;
}
