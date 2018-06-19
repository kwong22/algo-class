/**
 * calculate_min_cut.cpp
 * Calculates the number of crossing edges in the min cut of the graph.
 *
 * Kelvin Wong
 * kwong691@gmail.com
 */

#include <iostream>
#include "linked_list.h"

std::istream& read_vertex(std::istream& is, linked_list* vertex, int* count) {
  if (is) {
    int n;
    while (is >> n) {
      std::cout << "inserting " << n << " into " << vertex << std::endl;
      if (insert_node_in_order(&(vertex->head), n)) {
        std::cout << "inserted" << std::endl;
        ++(vertex->len);
        ++(*count);
      }
    }
    is.clear();
  }
  return is;
}

std::istream& read(std::istream& is, linked_list** vertices, int* count) {
  int index;
  is >> index;

  std::cout << "Reading vertex " << index << std::endl;
  read_vertex(is, vertices[index], count);
  return is;
}

int main() {

  int n = 200; // number of vertices
  int m = 0; // number of edges

  // store linked lists containing vertices that share an edge
  linked_list vertices[n + 1]; // add 1 to match index with vertex number
  
  while (read(std::cin, &vertices, &m))
    ;

  /*
  node* root = NULL;
  insert_node_in_order(&root, 30);
  insert_node_in_order(&root, 12);
  insert_node_in_order(&root, 15);
  insert_node_in_order(&root, 15);
  insert_node_in_order(&root, 100);
  insert_node_in_order(&root, 30);
  insert_node_in_order(&root, 4);
  insert_node_in_order(&root, 60);
  insert_node_in_order(&root, 300);
  
  delete_node(&root, root);
  delete_node(&root, root->next->next);
  delete_node(&root, root->next->next->next->next);
  insert_node_in_order(&root, 30);

  // Print contents of linked list
  node* cur = root;
  std::cout << root->x << std::endl;
  while (cur->next != NULL) {
    cur = cur->next;
    std::cout << cur->x << std::endl;
  }

  // then print contents in reverse
  while (cur->prev != NULL) {
    cur = cur->prev;
    std::cout << cur->x << std::endl;
  }

  delete_linked_list(&root);
  */

  return 0;
}
