#include<stdio.h>
#include<malloc.h>
#define MAX 10

//print all the vertices that can be reached from the given source with atmost distance k
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
    int k=0;

    while (front < rear )
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
        k++;

    }

    printf("\n");
}


void displayGraph(int graph[MAX][MAX],int n)
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

    displayGraph(g2,6);
    printf("\n\n");

    BFS(g2,7,3);

    printf("\n\n");

    return 0;
}
