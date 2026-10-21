#include <stdio.h>
#include <stdlib.h>

#define T 3

typedef struct BTreeNode
{
    int keys[2 * T - 1];
    struct BTreeNode *child[2 * T];

    int n;       // Number of keys
    int leaf;    // 1 = leaf, 0 = internal node
} BTreeNode;


/* =========================================================
   CREATE NODE
   ========================================================= */

BTreeNode *createNode(int leaf)
{
    BTreeNode *node;

    node = (BTreeNode *)malloc(sizeof(BTreeNode));

    node->leaf = leaf;
    node->n = 0;

    for (int i = 0; i < 2 * T; i++)
        node->child[i] = NULL;

    return node;
}


/* =========================================================
   SEARCH
   ========================================================= */

BTreeNode *search(BTreeNode *root, int key)
{
    int i = 0;

    if (root == NULL)
        return NULL;

    while (i < root->n && key > root->keys[i])
        i++;

    if (i < root->n && key == root->keys[i])
        return root;

    if (root->leaf)
        return NULL;

    return search(root->child[i], key);
}


/* =========================================================
   TRAVERSAL
   ========================================================= */

void traverse(BTreeNode *root)
{
    if (root == NULL)
        return;

    int i;

    for (i = 0; i < root->n; i++)
    {
        if (!root->leaf)
            traverse(root->child[i]);

        printf("%d ", root->keys[i]);
    }

    if (!root->leaf)
        traverse(root->child[i]);
}


/* =========================================================
   SPLIT CHILD
   ========================================================= */

void splitChild(BTreeNode *parent, int index)
{
    BTreeNode *fullChild = parent->child[index];
    BTreeNode *newChild = createNode(fullChild->leaf);

    int middleKey = fullChild->keys[T - 1];

    newChild->n = T - 1;

    /* Copy last T-1 keys */
    for (int j = 0; j < T - 1; j++)
    {
        newChild->keys[j] =
            fullChild->keys[j + T];
    }

    /* Copy children */
    if (!fullChild->leaf)
    {
        for (int j = 0; j < T; j++)
        {
            newChild->child[j] =
                fullChild->child[j + T];
        }
    }

    fullChild->n = T - 1;

    /* Move parent's children */
    for (int j = parent->n; j >= index + 1; j--)
    {
        parent->child[j + 1] =
            parent->child[j];
    }

    parent->child[index + 1] = newChild;

    /* Move parent's keys */
    for (int j = parent->n - 1; j >= index; j--)
    {
        parent->keys[j + 1] =
            parent->keys[j];
    }

    parent->keys[index] = middleKey;

    parent->n++;
}


/* =========================================================
   INSERT INTO NON-FULL NODE
   ========================================================= */

void insertNonFull(BTreeNode *node, int key)
{
    int i = node->n - 1;

    /* Leaf node */
    if (node->leaf)
    {
        while (i >= 0 && key < node->keys[i])
        {
            node->keys[i + 1] =
                node->keys[i];

            i--;
        }

        node->keys[i + 1] = key;
        node->n++;
    }

    /* Internal node */
    else
    {
        while (i >= 0 && key < node->keys[i])
            i--;

        i++;

        /* Child is full */
        if (node->child[i]->n == 2 * T - 1)
        {
            splitChild(node, i);

            if (key > node->keys[i])
                i++;
        }

        insertNonFull(node->child[i], key);
    }
}


/* =========================================================
   INSERT
   ========================================================= */

void insert(BTreeNode **root, int key)
{
    /* Empty tree */
    if (*root == NULL)
    {
        *root = createNode(1);
        (*root)->keys[0] = key;
        (*root)->n = 1;

        return;
    }

    /* Root is full */
    if ((*root)->n == 2 * T - 1)
    {
        BTreeNode *newRoot =
            createNode(0);

        newRoot->child[0] = *root;

        splitChild(newRoot, 0);

        int i = 0;

        if (key > newRoot->keys[0])
            i++;

        insertNonFull(newRoot->child[i], key);

        *root = newRoot;
    }

    else
    {
        insertNonFull(*root, key);
    }
}


/* =========================================================
   FIND KEY INDEX
   ========================================================= */

int findKey(BTreeNode *node, int key)
{
    int index = 0;

    while (index < node->n &&
           node->keys[index] < key)
    {
        index++;
    }

    return index;
}


/* =========================================================
   GET PREDECESSOR
   ========================================================= */

int getPredecessor(BTreeNode *node)
{
    while (!node->leaf)
        node = node->child[node->n];

    return node->keys[node->n - 1];
}


/* =========================================================
   GET SUCCESSOR
   ========================================================= */

int getSuccessor(BTreeNode *node)
{
    while (!node->leaf)
        node = node->child[0];

    return node->keys[0];
}


/* =========================================================
   BORROW FROM PREVIOUS CHILD
   ========================================================= */

void borrowFromPrev(BTreeNode *node, int index)
{
    BTreeNode *child = node->child[index];
    BTreeNode *sibling = node->child[index - 1];

    /* Move child's keys */
    for (int i = child->n - 1; i >= 0; i--)
    {
        child->keys[i + 1] =
            child->keys[i];
    }

    /* Move child's children */
    if (!child->leaf)
    {
        for (int i = child->n; i >= 0; i--)
        {
            child->child[i + 1] =
                child->child[i];
        }

        child->child[0] =
            sibling->child[sibling->n];
    }

    /* Parent key comes to child */
    child->keys[0] =
        node->keys[index - 1];

    /* Sibling's last key goes to parent */
    node->keys[index - 1] =
        sibling->keys[sibling->n - 1];

    child->n++;
    sibling->n--;
}


/* =========================================================
   BORROW FROM NEXT CHILD
   ========================================================= */

void borrowFromNext(BTreeNode *node, int index)
{
    BTreeNode *child = node->child[index];
    BTreeNode *sibling = node->child[index + 1];

    /* Parent key goes to child */
    child->keys[child->n] =
        node->keys[index];

    /* Move sibling's first child */
    if (!child->leaf)
    {
        child->child[child->n + 1] =
            sibling->child[0];
    }

    /* Sibling's first key goes to parent */
    node->keys[index] =
        sibling->keys[0];

    /* Shift sibling keys */
    for (int i = 1; i < sibling->n; i++)
    {
        sibling->keys[i - 1] =
            sibling->keys[i];
    }

    /* Shift sibling children */
    if (!sibling->leaf)
    {
        for (int i = 1; i <= sibling->n; i++)
        {
            sibling->child[i - 1] =
                sibling->child[i];
        }
    }

    child->n++;
    sibling->n--;
}


/* =========================================================
   MERGE CHILDREN
   ========================================================= */

void merge(BTreeNode *node, int index)
{
    BTreeNode *child = node->child[index];
    BTreeNode *sibling = node->child[index + 1];

    /* Parent key goes into child */
    child->keys[T - 1] =
        node->keys[index];

    /* Copy sibling keys */
    for (int i = 0; i < sibling->n; i++)
    {
        child->keys[i + T] =
            sibling->keys[i];
    }

    /* Copy children */
    if (!child->leaf)
    {
        for (int i = 0; i <= sibling->n; i++)
        {
            child->child[i + T] =
                sibling->child[i];
        }
    }

    child->n += sibling->n + 1;

    /* Shift parent keys */
    for (int i = index + 1; i < node->n; i++)
    {
        node->keys[i - 1] =
            node->keys[i];
    }

    /* Shift parent children */
    for (int i = index + 2; i <= node->n; i++)
    {
        node->child[i - 1] =
            node->child[i];
    }

    node->n--;

    free(sibling);
}


/* =========================================================
   FILL CHILD
   ========================================================= */

void fill(BTreeNode *node, int index)
{
    /* Borrow from previous sibling */
    if (index != 0 &&
        node->child[index - 1]->n >= T)
    {
        borrowFromPrev(node, index);
    }

    /* Borrow from next sibling */
    else if (index != node->n &&
             node->child[index + 1]->n >= T)
    {
        borrowFromNext(node, index);
    }

    /* Merge with sibling */
    else
    {
        if (index != node->n)
            merge(node, index);
        else
            merge(node, index - 1);
    }
}


/* =========================================================
   REMOVE FROM LEAF
   ========================================================= */

void removeFromLeaf(BTreeNode *node, int index)
{
    for (int i = index + 1; i < node->n; i++)
    {
        node->keys[i - 1] =
            node->keys[i];
    }

    node->n--;
}


/* =========================================================
   REMOVE FROM INTERNAL NODE
   ========================================================= */

void removeFromNonLeaf(BTreeNode *node, int index)
{
    int key = node->keys[index];

    /* Left child has enough keys */
    if (node->child[index]->n >= T)
    {
        int predecessor =
            getPredecessor(node->child[index]);

        node->keys[index] = predecessor;

        /* Delete predecessor */
        deleteKey(node->child[index],
                  predecessor);
    }

    /* Right child has enough keys */
    else if (node->child[index + 1]->n >= T)
    {
        int successor =
            getSuccessor(node->child[index + 1]);

        node->keys[index] = successor;

        /* Delete successor */
        deleteKey(node->child[index + 1],
                  successor);
    }

    /* Both children have T-1 keys */
    else
    {
        merge(node, index);

        deleteKey(node->child[index], key);
    }
}


/* =========================================================
   DELETE KEY
   ========================================================= */

void deleteKey(BTreeNode *node, int key)
{
    int index = findKey(node, key);

    /* Key found */
    if (index < node->n &&
        node->keys[index] == key)
    {
        if (node->leaf)
        {
            removeFromLeaf(node, index);
        }
        else
        {
            removeFromNonLeaf(node, index);
        }

        return;
    }

    /* Key not found in this node */
    if (node->leaf)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    int flag =
        (index == node->n);

    /* Child has minimum number of keys */
    if (node->child[index]->n < T)
    {
        fill(node, index);
    }

    /* After merge, child index may change */
    if (flag && index > node->n)
    {
        deleteKey(node->child[index - 1], key);
    }
    else
    {
        deleteKey(node->child[index], key);
    }
}


/* =========================================================
   DELETE
   ========================================================= */

void delete(BTreeNode **root, int key)
{
    if (*root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    deleteKey(*root, key);

    /* Root became empty */
    if ((*root)->n == 0)
    {
        BTreeNode *oldRoot = *root;

        if ((*root)->leaf)
        {
            *root = NULL;
        }
        else
        {
            *root = (*root)->child[0];
        }

        free(oldRoot);
    }
}


/* =========================================================
   DISPLAY TREE
   ========================================================= */

void display(BTreeNode *root, int level)
{
    if (root == NULL)
        return;

    printf("Level %d: ", level);

    for (int i = 0; i < root->n; i++)
        printf("%d ", root->keys[i]);

    printf("\n");

    if (!root->leaf)
    {
        for (int i = 0; i <= root->n; i++)
        {
            display(root->child[i], level + 1);
        }
    }
}


/* =========================================================
   FREE TREE
   ========================================================= */

void freeTree(BTreeNode *root)
{
    if (root == NULL)
        return;

    if (!root->leaf)
    {
        for (int i = 0; i <= root->n; i++)
        {
            freeTree(root->child[i]);
        }
    }

    free(root);
}


/* =========================================================
   MAIN
   ========================================================= */

int main()
{
    BTreeNode *root = NULL;

    int choice;
    int key;

    while (1)
    {
        printf("\n===== B-TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Display Tree\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter key: ");
                scanf("%d", &key);

                if (search(root, key) != NULL)
                {
                    printf("Duplicate key.\n");
                }
                else
                {
                    insert(&root, key);
                }

                break;


            case 2:

                printf("Enter key: ");
                scanf("%d", &key);

                delete(&root, key);

                break;


            case 3:

                printf("Enter key: ");
                scanf("%d", &key);

                if (search(root, key) != NULL)
                    printf("Key found.\n");
                else
                    printf("Key not found.\n");

                break;


            case 4:

                printf("Traversal: ");
                traverse(root);
                printf("\n");

                break;


            case 5:

                printf("\nB-Tree:\n");
                display(root, 0);

                break;


            case 6:

                freeTree(root);
                return 0;


            default:

                printf("Invalid choice.\n");
        }
    }
}