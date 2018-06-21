// source file for Graph-related functions
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Graph.h"

using std::istream;
using std::vector;

// Loads graph from file with corresponding filename
void load_graph_from_file(Graph& g, std::string filename) {
  // open file
  std::ifstream infile(filename.c_str()); // requires a C string

  std::string line;

  // read and store the graph, each line represents a vertex
  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    read_vertex(iss, g);
  }

  infile.close();
}

// Reads vertex from line
istream& read_vertex(istream& is, Graph& g) {
  // read vertex from first position
  int v1;
  is >> v1;

  // add vertex if graph does not already contain it
  if (!contains_vertex(g, v1)) {
    // add vertex to list of vertices
    add_vertex(g, v1);
    
    // read and store edges from rest of the line
    read_edges_of_vertex(is, g, v1);
  }
  return is;
}

// Reads edges from a single line, given an endpoint vertex
istream& read_edges_of_vertex(istream& is, Graph& g, int v1) {
  if (is) {
    // read vertices connected to v1, they form an edge
    int v2;
    while (is >> v2) {
      // re-order vertices so that first vertex <= second vertex
      int vertex1, vertex2;
      if (v1 <= v2) {
        vertex1 = v1;
        vertex2 = v2;
      } else {
        vertex1 = v2;
        vertex2 = v1;
      }

      // add edge if graph does not already contain it
      if (!contains_edge(g, vertex1, vertex2)) {
        add_edge(g, vertex1, vertex2);
      }
    }

    // clear stream so that input will work for next vertex
    is.clear();
  }
  return is;
}

// Adds vertex to graph
void add_vertex(Graph& g, int vertex) {
  g.vertices.push_back(vertex);
}

// Adds edge (v1, v2) to graph, v1 <= v2
void add_edge(Graph& g, int v1, int v2) {
  Edge e;
  e.v1 = v1;
  e.v2 = v2;
  g.edges.push_back(e);
}

// Returns true if graph already contains vertex
// Otherwise returns false
bool contains_vertex(Graph& g, int vertex) {
  for (int i = 0; i < g.vertices.size(); ++i) {
    if (g.vertices[i] == vertex) {
      return true;
    }
  }
  return false;
}

// Returns true if graph already contains edge (v1, v2), v1 <= v2
// Otherwise returns false
bool contains_edge(Graph& g, int v1, int v2) {
  for (int i = 0; i < g.edges.size(); ++i) {
    if (g.edges[i].v1 == v1 && g.edges[i].v2 == v2) {
      return true;
    }
  }
  return false;
}

// Merges vertices v1 and v2, where v1 < v2 (v1 != v2)
void merge_vertices(Graph& g, int v1, int v2) {
  // remove v2 from the graph
  for (int i = 0; i < g.vertices.size(); ++i) {
    if (g.vertices[i] == v2) {
      g.vertices.erase(g.vertices.begin() + i);
      break;
    }
  }

  // migrate edges from v2 to v1
  // start from the end and move up until v2 is no longer the first vertex
  int j = g.edges.size() - 1;
  for (; j >= 0 && g.edges[j].v1 >= v2; --j) {
    // track any edge endpoint that becomes orphaned
    int orphan;

    // remove edge if it contains v2
    if (g.edges[j].v1 == v2) {
      orphan = g.edges[j].v2;
      g.edges.erase(g.edges.begin() + j);
      
      // add edge back even if graph already contains it
      add_edge(g, v1, orphan);
    }
  }

  // continue from last index, now v2 will be second vertex
  for (; j >= 0; --j) {
    // track any edge endpoint that becomes orphaned
    int orphan;

    // remove edge if it contains v2
    if (g.edges[j].v2 == v2) {
      orphan = g.edges[j].v1;
      g.edges.erase(g.edges.begin() + j);

      // re-order vertices so that first vertex <= second vertex
      int vertex1, vertex2;
      if (v1 <= orphan) {
        vertex1 = v1;
        vertex2 = orphan;
      } else {
        vertex1 = orphan;
        vertex2 = v1;
      }

      // add edge back even if graph already contains it
      add_edge(g, vertex1, vertex2);
    }
  }
}

// Removes any edges that begin and end at the same vertex (self loops)
void remove_self_loops(Graph& g) {
  // iterate backward so that erasing an item does not disrupt the loop
  for (int i = g.edges.size() - 1; i >= 0; --i) {
    if (g.edges[i].v1 == g.edges[i].v2) {
      g.edges.erase(g.edges.begin() + i);
    }
  }
}

// Calculates a min cut of the graph via the Random Contraction algorithm
// Returns number of crossing edges in the calculated min cut
int calculate_min_cut(Graph& g) {
  while (g.vertices.size() > 2) {
    // generate random index within list of edges
    int i = std::rand() % g.edges.size();

    // merge v1 and v2 into a single vertex
    int v1 = g.edges[i].v1;
    int v2 = g.edges[i].v2;
    merge_vertices(g, v1, v2);

    // remove any self loops that result
    remove_self_loops(g);
  }

  return g.edges.size();
}

