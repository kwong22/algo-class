/**
 * calculate_min_cut.cpp
 * Calculates the number of crossing edges in the min cut of the graph.
 *
 * Kelvin Wong
 * kwong691@gmail.com
 */

#include <iostream>
#include "linked_list.h"

int main() {

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

  return 0;
}
