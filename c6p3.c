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
    int val = temp->data;
    s->top = s->top->next;
    free(temp);

    return val;
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
int check(char op)
{
    return (op=='+' || op=='-' || op=='*' || op=='/' || op=='%');
}

int evaluatePostfix(char exp[])
{
    Stack s = createStack();

    int i = 0;

    while(exp[i] != '\0')
    {
        if(exp[i] == ' ')
        {
            i++;
            continue;
        }

        if(exp[i] >='0' && exp[i] <='9')
        {
            push(&s, exp[i] - '0');
        }
        else if(check(exp[i]))
        {
            int b = pop(&s);
            int a = pop(&s);

            switch(exp[i])
            {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                case ''%': push(&s, a % b); break;
            }
        }

        i++;
    }

    return pop(&s);
}

int main() {
    Stack s = createStack();

    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));

    while (!isEmpty(s)) {
        pop(&s);
    }

    return 0;
}
