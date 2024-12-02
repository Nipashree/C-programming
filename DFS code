#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function for DFS
void DFS(int graph[MAX][MAX], int vertex, bool visited[], int n) {
    // Mark the current vertex as visited and process it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all neighbors of the current vertex
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) { // Check for an edge and unvisited vertex
            DFS(graph, i, visited, n);
        }
    }
}

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

    bool visited[MAX] = {false}; // Array to keep track of visited vertices

    printf("DFS Traversal: ");
    DFS(graph, start, visited, n);
    printf("\n");

    return 0;
}
