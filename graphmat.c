#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int n;


void createGraph()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
}


void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}


void addDirectedEdge(int u, int v)
{
    graph[u][v] = 1;
}


void deleteEdge(int u, int v)
{
    graph[u][v] = 0;
    graph[v][u] = 0;
}

int hasEdge(int u, int v)
{
    return graph[u][v];
}

void displayGraph()
{
    int i, j;

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}


int degree(int vertex)
{
    int i;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1)
            count++;
    }

    return count;
}


int countEdges()
{
    int i, j;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                count++;
        }
    }


    return count / 2;
}

void DFSUtil(int vertex, int visited[])
{
    int i;

    visited[vertex] = 1;

    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFSUtil(i, visited);
        }
    }
}


void DFS(int start)
{
    int visited[MAX] = {0};

    printf("DFS: ");

    DFSUtil(start, visited);

    printf("\n");
}


void BFS(int start)
{
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = 0;

    int i, vertex;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");

    while (front < rear)
    {
        vertex = queue[front++];

        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

int isConnected()
{
    int visited[MAX] = {0};
    int count = 0;

    DFSUtil(0, visited);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            count++;
    }

    return count == n;
}


int main()
{
    int u, v, start;

    createGraph();
                printf("Enter two vertices: ");
                scanf("%d %d", &u, &v);

                addEdge(u, v);

                printf("Enter two vertices: ");
                scanf("%d %d", &u, &v);

                deleteEdge(u, v);

                displayGraph();

                printf("Enter two vertices: ");
                scanf("%d %d", &u, &v);

                if (hasEdge(u, v))
                    printf("Edge exists\n");
                else
                    printf("Edge does not exist\n");


                printf("Enter vertex: ");
                scanf("%d", &u);

                printf("Degree = %d\n", degree(u));

                printf("Number of edges = %d\n", countEdges());

                printf("Enter starting vertex: ");
                scanf("%d", &start);

                DFS(start);

                printf("Enter starting vertex: ");
                scanf("%d", &start);

                BFS(start);

                if (isConnected())
                    printf("Graph is connected\n");
                else
                    printf("Graph is not connected\n");


    return 0;
}
