#include<stdio.h>
#include<malloc.h>
#define MAX 10

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct vert{
    int vertex;
    Node *nex;
    struct V *next;
} V;


typedef struct G{
    int vertices;
    V *head;
} G;

Node *createNode(int vertex)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    temp->vertex = vertex;
    temp->next = NULL;

    return temp;
}

G *createGraph(int vertices)
{
    G *graph = (G *)malloc(sizeof(G));

    graph->vertices = vertices;
    graph->head=NULL;

    V *t=(V *)malloc(sizeof(V));
    for(int i=0;i<vertices;i++)
    {

    }
    graph->nex=NULL;

    return graph;
}


void Convert(int graph[MAX][MAX],int n, G *g)
{
    for(int i=0;i<n;i++)
    {
        Node *t=NULL;

        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1)
            {
                Node *t2=createNode(j+1);
                if(g->nex == NULL)
                {
                    g->nex=t2;
                }
                else
                {
                    t->next=t2;
                }
                t=t2;
            }
        }
    }
}


void DFSUtil(int vertex, int n, int graph[MAX][MAX], int visited[])
{
    int i;

    visited[vertex] = 1;

    printf("%d ", vertex+1);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFSUtil(i, n, graph, visited);
        }
    }
}


void DFS(int n, int graph[MAX][MAX], int start)
{
    int visited[MAX] = {0};

    printf("DFS: ");

    DFSUtil(start, n, graph, visited);

    printf("\n");
}


void BFS(int graph[MAX][MAX],int n,int s)
{
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = 0;

    int i, v;

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS: ");

    while (front < rear)
    {
        v = queue[front++];

        printf("%d ", v+1);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}


void displayGraph(G *g, int graph[MAX][MAX],int n)
{
    printf("\nAdjacency Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
     printf("\n");

    printf("\nAdjacency List:\n");

    for (int i = 0; i < g->vertices; i++)
    {
        Node *temp = g->nex;

        printf("%d  ", i+1);

        while (temp != NULL) {
            printf("%d  ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int g1[MAX][MAX]={{0,1,1,1,0,0},
                  {1,0,0,0,0,1},
                  {1,0,0,0,1,0},
                  {1,0,0,0,1,0},
                  {0,0,1,1,0,1},
                  {0,1,0,0,1,0}};
    int g2[MAX][MAX]={{0,0,1,1,0,0,0},
                  {0,0,0,1,1,1,0},
                  {1,0,0,0,0,1,1},
                  {1,1,0,0,0,1,0},
                  {0,1,0,0,0,1,0},
                  {0,1,1,1,1,0,0},
                  {0,0,1,0,0,0,0}};

    G *g=NULL;
    g=createGraph(6);
    Convert(g1,6,g);

    displayGraph(g,g1,6);
    printf("\n\n");
    DFS(6,g1,0);
    BFS(g1,6,0);

     printf("\n\n");

/*
    G *gra=NULL;
    gra=createGraph(7);
    Tolist(gra,g2,7);

    displayGraph(gra,g2,7);
    printf("\n\n");
    DFS(7,g2,0);
    BFS(g2,7,0);
*/
    return 0;


}

