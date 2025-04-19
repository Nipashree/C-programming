#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

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


void BFS(int graph[MAX][MAX], int start, int n) {
    bool visited[MAX] = {false}; 
    Queue q;
    initializeQueue(&q);

   
    visited[start] = true;
    enqueue(&q, start);

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) { 
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int n = 5;
    int start = 0; 

    BFS(graph, start, n);

    return 0;
}
