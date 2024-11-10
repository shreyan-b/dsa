#include <stdio.h>

#define MAX 100

int time = 0;
int dfn[MAX], low[MAX], parent[MAX];
int visited[MAX], articulation[MAX];

void dfnlow(int u, int adj[MAX][MAX], int V) {
  int v;
  int children = 0;
  visited[u] = 1;
  dfn[u] = low[u] = ++time;
  for (v = 0; v < V; v++) {
    if (adj[u][v]) {
      if (!visited[v]) {
        children++;
        parent[v] = u;
        dfnlow(v, adj, V);
        low[u] = (low[u] < low[v]) ? low[u] : low[v];
        if (parent[u] == -1 && children > 1) {
          articulation[u] = 1;
        }
        if (parent[u] != -1 && low[v] >= dfn[u]) {
          articulation[u] = 1;
        }
      } else if (v != parent[u]) {
        low[u] = (low[u] < dfn[v]) ? low[u] : dfn[v];
      }
    }
  }
}

void findArticulationPoints(int adj[MAX][MAX], int V) {
  int i;
  for (i = 0; i < V; i++) {
    parent[i] = -1;
    visited[i] = 0;
    articulation[i] = 0;
  }
  for (i = 0; i < V; i++) {
    if (!visited[i]) {
      dfnlow(i, adj, V);
    }
  }
  printf("Articulation points are: \n");
  for (i = 0; i < V; i++) {
    if (articulation[i]) {
      printf("Router %d\n", i);
    }
  }
}

int main() {
  int V, E, i, u, v;
  int adj[MAX][MAX] = {0};
  printf("Enter the number of routers (vertices): ");
  scanf("%d", &V);
  printf("Enter the number of connections (edges): ");
  scanf("%d", &E);
  printf("Enter the connections (u v):\n");
  for (i = 0; i < E; i++) {
    scanf("%d %d", &u, &v);
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  findArticulationPoints(adj, V);
  return 0;
}