/**
 * calculate_min_cut.cpp
 * Calculates the number of crossing edges in the min cut of the graph.
 *
 * Kelvin Wong
 * kwong691@gmail.com
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "Graph.h"

int main() {
  // seed randomizer with current time, call once at beginning of program
  std::srand(std::time(NULL));

  Graph g;
  std::string filename = "kargerMinCut.txt";

  int num_trials = 25000;
  int best_min_cut = 2517; // initialize as total number of edges in graph

  // calculate min cut many times, and keep track of best min cut
  for (int i = 0; i < num_trials; ++i) {
    // load the entire graph to reset it
    load_graph_from_file(g, filename);

    int num_edges = calculate_min_cut(g);
    
    if (num_edges < best_min_cut) {
      best_min_cut = num_edges;
    }

    // check progress
    std::cout << "[" << i + 1 << "/" << num_trials << "] ";
    std::cout << num_edges << " | Best: " << best_min_cut << std::endl;
  }

  std::cout << "The best min cut found contains " << best_min_cut <<
    " crossing edges." << std::endl;

  return 0;
}
