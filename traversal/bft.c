#include<stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue [MAX];
int front = -1, rear = -1;
int n;

void enqueue(int v)
{
    if(rear == MAX - 1)
    {
       printf("Queue Overflow!");
       return;
    }
    if(front == -1)
    front = 0;
    queue[++rear]=v;
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        return -1;
    }
    return queue [front ++];
}
int isQueueEmpty()
{
    return(front == -1 || front > rear);
}

void bfs(int start)
{
    enqueue(start);
    visited [start]= -1;

    while (!isQueueEmpty())
    {
        int v = dequeue();
        printf("%d",v);

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && !visited [i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    
}

int main()
{
    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Adjacency matrix");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i = 0; i < n;i++)
    {
        visited[i] = 0;
    }
    int start;
    printf("Enter starting vertex (0 to %d)",n-1);
    scanf("%d", &start);
    printf("BFT:");

    bfs(start);

    printf("\n");

    return 0;
}