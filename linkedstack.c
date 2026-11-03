#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack createStack() {
    Stack s;
    s.top = NULL;
    return s;
}

int isEmpty(Stack s) {
    return s.top == NULL;
}

int push(Stack *s, int val) {
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp == NULL)
        return 0;

    temp->data = val;
    temp->next = s->top;
    s->top = temp;

    return 1;
}

int pop(Stack *s) {
    if (isEmpty(*s))
        return 0;

    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);

    return 1;
}

int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Empty Stack\n");
        return -1;
    }

    return s.top->data;
}

void printStack(Stack s) {
    Node *temp = s.top;

    if (temp == NULL) {
        printf("Empty stack\n");
        return;
    }

    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Stack s = createStack();

    printf("Push 10, 20, 30\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(s);
    // Expect: 30 20 10

    printf("Peek: %d\n", peek(s));
    // Expect: 30

    printf("Pop once\n");
    pop(&s);
    printStack(s);
    // Expect: 20 10

    printf("Pop until empty\n");
    pop(&s);
    pop(&s);
    printStack(s);
    // Expect: Empty stack

    printf("Pop from empty stack: %d\n", pop(&s));
    // Expect: 0 (false)

    /* Free any remaining nodes */
    while (!isEmpty(s)) {
        pop(&s);
    }

    return 0;
}

