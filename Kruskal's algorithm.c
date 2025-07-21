#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to compare edges based on weight (for sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find function (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function (by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Kruskal's algorithm to find MST
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // Store MST
    int e = 0, i = 0;

    // Sort edges by weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize subsets
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edges in MST:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

// Main function
int main() {
    int V = 4, E = 5; // Example: 4 vertices, 5 edges
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    // Example edges
    graph->edges[0] = (struct Edge){0, 1, 10};
    graph->edges[1] = (struct Edge){0, 2, 6};
    graph->edges[2] = (struct Edge){0, 3, 5};
    graph->edges[3] = (struct Edge){1, 3, 15};
    graph->edges[4] = (struct Edge){2, 3, 4};

    kruskalMST(graph);

    free(graph->edges);
    free(graph);
    return 0;
}
