#include <stdio.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }

    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Function to print the shortest distance and path for all vertices
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("%d -> %d\t%d\t\t%d ", src, i, dist[i], src);
            printPath(parent, i);
            printf("\n");
        }
    }
}

// Function to implement Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Array to store the shortest distances
    int sptSet[V];    // Array to keep track of vertices included in the shortest path tree
    int parent[V];    // Array to store the parent vertices to construct the shortest path

    // Initialize the distance array and sptSet
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 0, 1, 0},
        {2, 0, 4, 0, 3, 0},
        {0, 4, 0, 5, 0, 0},
        {0, 0, 5, 0, 7, 3},
        {1, 3, 0, 7, 0, 0},
        {0, 0, 0, 3, 0, 0}
    };

    int src = 0; // Source vertex

    dijkstra(graph, src);

    return 0;
}
