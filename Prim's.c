#include <stdio.h>
#define INF 999999

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm and calculate the total weight of the MST
void primMST(int src[], int dest[], int weight[], int E, int V) {
    int parent[V];
    int key[V];
    int mstSet[V];
    int totalWeight = 0;  // Variable to store the total weight of the MST
    
    // Initialize the key values and mstSet
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    
    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;
    
    // Build the MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);  // Find the vertex with the minimum key value
        mstSet[u] = 1;  // Add the selected vertex to the MST
        
        // Update the key values and parent for the adjacent vertices
        for (int i = 0; i < E; i++) {
            if ((src[i] == u || dest[i] == u) && mstSet[src[i] == u ? dest[i] : src[i]] == 0) {
                int v = src[i] == u ? dest[i] : src[i];
                if (weight[i] < key[v]) {
                    parent[v] = u;
                    key[v] = weight[i];
                }
            }
        }
    }

    // Print the edges and total weight of the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i] + 1, i + 1, key[i]);
        totalWeight += key[i];  // Add the weight of the selected edge to the total weight
    }
    
    // Print the total weight of the MST
    printf("\nTotal Weight of MST: %d\n", totalWeight);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    int src[E], dest[E], weight[E];
    
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &src[i], &dest[i], &weight[i]);
        src[i]--;  // Adjust to 0-indexed for easier array manipulation
        dest[i]--; // Adjust to 0-indexed
    }
    
    // Call the function to compute the MST and display the result
    primMST(src, dest, weight, E, V);
    
    return 0;
}
