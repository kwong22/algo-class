#ifndef GUARD_Graph
#define GUARD_Graph

// Graph.h header file
// Graph implemented as an adjacency list
// list of n vertices and list of m edges
#include <iostream>
#include <string>
#include <vector>

struct Edge {
  // indices of the 2 vertices that make up the edge, v1 <= v2
  int v1, v2;
};

struct Graph {
  std::vector<int> vertices;
  std::vector<Edge> edges;
};

void load_graph_from_file(Graph&, std::string);
std::istream& read_vertex(std::istream&, Graph&);
std::istream& read_edges_of_vertex(std::istream&, Graph&, int);
void add_vertex(Graph&, int);
void add_edge(Graph&, int, int);
bool contains_vertex(Graph&, int);
bool contains_edge(Graph&, int, int);
void merge_vertices(Graph&, int, int);
void remove_self_loops(Graph&);
int calculate_min_cut(Graph&);
#endif
