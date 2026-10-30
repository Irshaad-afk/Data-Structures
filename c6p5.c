
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int expo;
    struct Node *next;
} Node;

Node* makeNode(int coeff,int expo) {
    Node *temp = (Node*)malloc(sizeof(Node));

    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;
    return temp;
}

void display(Node *l) {
    while (l) {
        printf("%dx^%d", l->coeff,l->expo);
    if(l->next != NULL)
            printf(" + ");
    l = l->next;
    }
    printf("\n");
}

int insertTerm(Node *l,int coeff,int expo)
{
    if(!l)
        return makeNode(coeff,expo);
    Node *curr = l;
    Node *prev = NULL;


    while (curr != NULL && curr->expo > expo) {
        prev = curr;
        curr = curr->next;
    }



    if (curr != NULL && curr->expo == expo) {

        curr->coeff = curr->coeff + coeff;

        if (curr->coeff == 0) {

            if (prev == NULL)
                l= curr->next;

            else
                prev->next = curr->next;

        }

        return l;
    }



    Node *temp = makeNode(coeff, expo);


    if (prev == NULL) {
        temp->next = l;
        l = temp;
    }

    else {
        temp->next = curr;
        prev->next = temp;
    }


    return l;
}

int Mul(Node *l,int s)
{
    Node *t=l;
    while(t)
    {
        t->coeff=t->coeff*s;
        t=t->next;
    }
    return l;

}

int addpoly(Node *l1,Node *l2)
{
    Node *result = NULL;

    while (l1 != NULL && l2 != NULL) {

        if (l1->expo == l2->expo) {
            result = insertTerm(result, l1->coeff + l2->coeff, l1->expo);
            l1 = l1->next;
            l2 = l2->next;
        }

        else if (l1->expo > l2->expo) {
            result = insertTerm(result, l1->coeff, l1->expo);
            l1 = l1->next;
        }

        else {
            result = insertTerm(result, l2->coeff, l2->expo);
            l2 = l2->next;
        }
    }


    while (l1 != NULL) {
        result = insertTerm(result, l1->coeff, l1->expo);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        result = insertTerm(result, l2->coeff, l2->expo);
        l2 = l2->next;
    }


    return result;
}


int main() {

     Node *l1 = NULL;
     Node *l2 = NULL;
     Node *l3 = NULL;



    l1 = insertTerm(l1, 5, 4);
    l1 = insertTerm(l1, 3, 2);
    l1 = insertTerm(l1, 7, 1);
    l1 = insertTerm(l1, 2, 0);


    printf("Polynomial 1:\n");
    display(l1);


    l2 = insertTerm(l2, 4, 6);
    l2 = insertTerm(l2, 3, 5);
    l2 = insertTerm(l2, 6, 1);
    l2 = insertTerm(l2, 8, 0);


    printf("\nPolynomial 2:\n");
    display(l2);



    l1 = insertTerm(l1, 4, 3);


    printf("\nAfter inserting 4x^3 in list 1:\n");
    display(l1);

    l1 = Mul(l1, 5);


    printf("\nAfter scalar value being mutiplied in list 1:\n");
    display(l1);


    l3 = addpoly(l1,l2);


    printf("\nResulting List:\n");
    display(l3);





    return 0;
}
