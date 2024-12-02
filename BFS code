#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Queue functions
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->items[q->front++];
}

// BFS function
void BFS(int graph[MAX][MAX], int start, int n) {
    bool visited[MAX] = {false}; // Array to keep track of visited nodes
    Queue q;
    initializeQueue(&q);

    // Start BFS from the given node
    visited[start] = true;
    enqueue(&q, start);

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        // Visit all neighbors of the current node
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // Check for an edge and unvisited node
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// Main function to test BFS
int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int n = 5; // Number of vertices
    int start = 0; // Starting vertex

    BFS(graph, start, n);

    return 0;
}
