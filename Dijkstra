#include<stdio.h>
int main(){
void dijkstra(int graph[V][V], int start, int dist[]) {
    int visited[V] = {0};
    dist[start] = 0;
    
    for (int i = 0; i < V; i++) {
        int u = findMinDistNode(dist, visited);  // Find the unvisited node with the smallest distance
        visited[u] = 1;
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}
}
