/*
Write a program to implement Breadth First Search and Depth First Search in graph.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Structure for adjacency list
struct Graph
{
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'numVertices' vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjLists = (struct Node **)malloc(numVertices * sizeof(struct Node *));
    graph->visited = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function for Breadth First Search (BFS)
void BFS(struct Graph *graph, int startVertex)
{
    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Mark the startVertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear)
    {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node *temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Function for Depth First Search (DFS)
void DFS(struct Graph *graph, int vertex)
{
    // Mark the current vertex as visited
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct Node *temp = graph->adjLists[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex])
        {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int numVertices = 6; // Example graph has 6 vertices
    struct Graph *graph = createGraph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Breadth First Search (BFS) starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    // Resetting visited array
    for (int i = 0; i < numVertices; i++)
    {
        graph->visited[i] = 0;
    }

    printf("Depth First Search (DFS) starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
