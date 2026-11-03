#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    int vertices;
    Node *adj[MAX];
} Graph;

/* Create graph */
Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adj[i] = NULL;

    return graph;
}
void matrixToList(G *g, int graph[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *last = NULL;

        for (int j = 0; i < n; j++)
        {
            if (graph[i][j] == 1)
            {
                Node *temp = createNode(j + 1);

                if (g->adj[i] == NULL)
                {
                    g->adj[i] = temp;
                }
                else
                {
                    last->next = temp;
                }

                last = temp;
            }
        }
    }
}


/* Create a new adjacency-list node */
Node *createNode(int vertex) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

/* Add directed edge */
void addEdgeDirected(Graph *graph, int src, int dest) {
    Node *newNode = createNode(dest);

    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

/* Add undirected edge */
void addEdgeUndirected(Graph *graph, int src, int dest) {
    addEdgeDirected(graph, src, dest);
    addEdgeDirected(graph, dest, src);
}

/* Display graph */
void displayGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->adj[i];

        printf("%d: ", i);

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

/* DFS recursive */
void DFSUtil(Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1;

    printf("%d ", vertex);

    Node *temp = graph->adj[vertex];

    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFSUtil(graph, temp->vertex, visited);

        temp = temp->next;
    }
}

/* DFS */
void DFS(Graph *graph, int start) {
    int visited[MAX] = {0};

    printf("DFS: ");
    DFSUtil(graph, start, visited);
    printf("\n");
}

/* BFS */
void BFS(Graph *graph, int start) {
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");

    while (front < rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        Node *temp = graph->adj[vertex];

        while (temp != NULL) {
            int nextVertex = temp->vertex;

            if (!visited[nextVertex]) {
                visited[nextVertex] = 1;
                queue[rear++] = nextVertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

/* Count edges in directed graph */
int countEdgesDirected(Graph *graph) {
    int count = 0;

    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->adj[i];

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
    }

    return count;
}

/* Count edges in undirected graph */
int countEdgesUndirected(Graph *graph) {
    return countEdgesDirected(graph) / 2;
}

/* Calculate degree of a vertex */
int degree(Graph *graph, int vertex) {
    int count = 0;

    Node *temp = graph->adj[vertex];

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

/* Search whether an edge exists */
int hasEdge(Graph *graph, int src, int dest) {
    Node *temp = graph->adj[src];

    while (temp != NULL) {
        if (temp->vertex == dest)
            return 1;

        temp = temp->next;
    }

    return 0;
}

/* Free graph memory */
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->adj[i];

        while (temp != NULL) {
            Node *deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }
    }

    free(graph);
}

/* Main */
int main() {
    int vertices = 6;

    Graph *graph = createGraph(vertices);

    addEdgeUndirected(graph, 0, 1);
    addEdgeUndirected(graph, 0, 2);
    addEdgeUndirected(graph, 1, 3);
    addEdgeUndirected(graph, 1, 4);
    addEdgeUndirected(graph, 2, 5);

    printf("Graph:\n");
    displayGraph(graph);

    printf("\n");

    DFS(graph, 0);
    BFS(graph, 0);

    printf("\n");

    printf("Number of edges: %d\n",
           countEdgesUndirected(graph));

    printf("Degree of vertex 1: %d\n",
           degree(graph, 1));

    printf("Edge 0 -> 2: %s\n",
           hasEdge(graph, 0, 2) ? "Yes" : "No");

    freeGraph(graph);

    return 0;
}
