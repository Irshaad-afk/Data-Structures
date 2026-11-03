
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

Node* insertHead(Node *l, int data) {
    Node *temp = makeNode(data);
    temp->next = l;
    return temp;
}

int countNodes(Node *l) {
    int count = 0;
    while (l) {
        count++;
        l = l->next;
    }
    return count;
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

Node* insertTail(Node *l, int data) {
    if (!l)
        return makeNode(data);

    Node *temp = l;
    while (temp->next)
        temp = temp->next;

    temp->next = makeNode(data);
    return l;
}

Node* delPos(Node *l, int pos, int cP) {
    if (!l)
        return l;

    if (pos == cP) {
        Node *temp = l->next;
        free(l);
        return temp;
    }

    l->next = delPos(l->next, pos, cP + 1);
    return l;
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

int main() {
    Node *head = NULL;

    printf("INSERT AT HEAD\n");
    head = insertHead(head, 30);
    head = insertHead(head, 20);
    head = insertHead(head, 10);
    display(head);

    printf("\nINSERT AT TAIL\n");
    head = insertTail(head, 40);
    head = insertTail(head, 50);
    display(head);

    printf("\nCOUNT NODES\n");
    printf("Number of nodes = %d\n", countNodes(head));

    printf("\nFIND POSITION\n");
    printf("Position of 30 = %d\n", findPos(head, 30));
    printf("Position of 50 = %d\n", findPos(head, 50));
    printf("Position of 100 = %d\n", findPos(head, 100));

    printf("\nINSERT IN SORTED LIST\n");
    head = inSort(head, 25);
    display(head);

    head = inSort(head, 5);
    display(head);

    head = inSort(head, 60);
    display(head);

    printf("\nDELETE FROM SORTED LIST\n");
    head = delSort(head, 25);
    display(head);

    head = delSort(head, 5);
    display(head);

    head = delSort(head, 60);
    display(head);

    printf("\nDELETE POSITION\n");
    head = delPos(head, 3, 1);
    display(head);

    printf("\nREVERSE\n");
    head = reverse(head);
    display(head);

    /* Free remaining nodes */
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
