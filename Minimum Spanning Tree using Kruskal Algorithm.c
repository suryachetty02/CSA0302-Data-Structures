#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to compare two edges by their weights (used in sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the parent of a vertex (used in cycle detection)
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform Union operation (merge two sets)
void unionSets(int parent[], int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

// Function to implement Kruskal's algorithm to find the MST
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge resultMST[V]; // Array to store the MST
    int e = 0; // Index variable for the resultMST array
    int i = 0; // Index variable for the sorted edges array

    // Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for creating V subsets (for Union-Find)
    int* parent = (int*)malloc(V * sizeof(int));

    // Initialize all subsets as singletons (each vertex in its own set)
    for (int v = 0; v < V; v++) {
        parent[v] = -1;
    }

    // Number of edges to be taken is V-1
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edge[i++];

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        // If including this edge does not cause a cycle, add it to the resultMST
        if (x != y) {
            resultMST[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }

    // Print the edges of the MST
    printf("Edges of the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("(%d - %d) with weight %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);
    }

    free(parent);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges to the graph
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);

    return 0;
}
