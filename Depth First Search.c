#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Depth-First Search traversal
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("Visited vertex: %d\n", vertex);

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, vertices, i, visited);
        }
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    int visited[MAX_VERTICES] = {0};

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    DFS(graph, vertices, startVertex, visited);

    return 0;
}
