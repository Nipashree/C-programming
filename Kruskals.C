#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int parent[MAX];
int rank[MAX];

int find(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]); 
}


void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}


int compare(const void* a, const void* b) {
    int* edgeA = (int*)a;
    int* edgeB = (int*)b;
    return edgeA[2] - edgeB[2];  // Compare weights (edge[2])
}

void kruskal(int V, int E, int edges[][3]) {
    int mstWeight = 0;
    int mstEdges = 0;
    
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
  
    qsort(edges, E, sizeof(edges[0]), compare);

    printf("Edge \tWeight\n");

    
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

       
        if (find(u) != find(v)) {
            printf("%d - %d \t%d\n", u + 1, v + 1, weight); 
            mstWeight += weight;
            unionSets(u, v); 
            mstEdges++;
        }
      
        if (mstEdges == V - 1) {
            break;
        }
    }

    printf("\nTotal Weight of MST: %d\n", mstWeight);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int edges[E][3]; 

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
        edges[i][0]--;  
        edges[i][1]--;
    }

    kruskal(V, E, edges);
    
    return 0;
}
