#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define a queue for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isQueueFull(struct Queue* queue, int maxVertices) {
    return (queue->rear == maxVertices - 1) || (queue->front == queue->rear + 1);
}

// Function to enqueue an item
void enqueue(struct Queue* queue, int value) {
    if (isQueueFull(queue, MAX_VERTICES)) {
        printf("Queue is full. Cannot enqueue.\n");
        exit(1);
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_VERTICES;
    queue->items[queue->rear] = value;
}

// Function to dequeue an item
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    int item = queue->items[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_VERTICES;
    }

    return item;
}

// Function to perform Breadth-First Search traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    struct Queue queue;
    initializeQueue(&queue);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    visited[startVertex] = 1;
    printf("Visited vertex: %d\n", startVertex);
    enqueue(&queue, startVertex);

    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("Visited vertex: %d\n", i);
                enqueue(&queue, i);
            }
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(graph, vertices, startVertex);

    return 0;
}
