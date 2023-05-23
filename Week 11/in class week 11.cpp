#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
  int u, v;
  int weight;

  Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

void prims_mst(vector<vector<Edge>> &graph, int start_node) {
  // Initialize the minimum spanning tree.
  vector<Edge> mst;

  // Initialize the set of visited vertices.
  vector<bool> visited(graph.size(), false);

  // Add the starting vertex to the visited set.
  visited[start_node] = true;

  // While there are unvisited vertices:
  while (true) {

    // Find the edge with the minimum weight that connects a visited vertex
    // to an unvisited vertex.
    int min_weight = INT_MAX;
    int u = -1;
    int v = -1;
    for (int i = 0; i < graph.size(); i++) {
      if (visited[i]) {
        for (Edge &e : graph[i]) {
          if (!visited[e.v] && e.weight < min_weight) {
            min_weight = e.weight;
            u = i;
            v = e.v;
          }
        }
      }
    }

    // If there are no unvisited vertices, then we are done.
    if (u == -1) {
      break;
    }

    // Add the minimum edge to the minimum spanning tree.
    mst.push_back({u, v, min_weight});

    // Add the vertex connected by the minimum edge to the visited set.
    visited[v] = true;
  }

  // Print the minimum spanning tree.
  for (Edge &e : mst) {
    cout << e.u << " " << e.v << " " << e.weight << endl;
  }
}

int main() {
  // Create a graph.
  int adj_matrix[6][6] = {
    {0, 3, 0, 0, 0, 1},
    {3, 0, 2, 1, 10, 0},
    {0, 2, 0, 3, 0, 5},
    {0, 1, 3, 0, 5, 0},
    {0, 10, 0, 5, 0, 4},
    {1, 0, 5, 0, 4, 0}
  };

  vector<vector<Edge>> graph(6);
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (adj_matrix[i][j] != 0) {
        graph[i].push_back(Edge(i, j, adj_matrix[i][j]));
      }
    }
  }

  // Find the minimum spanning tree.
  prims_mst(graph, 0);

  return 0;
}
