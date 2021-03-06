#ifndef GUARD_linked_list
#define GUARD_linked_list

// linked_list.h header file
#include <cstddef>

// node for doubly-linked list
struct node {
  int x;
  node* prev;
  node* next;
};

// linked list that contains head of list and number of elements
struct linked_list {
  int len;
  node* head;

  // constructor
  linked_list() {
    len = 0;
    head = NULL;
  }
};

void delete_node(node**, node*);
void add_node_after(node*, int);
void add_node_before(node*, int);
void add_node_to_front(node**, int);
bool insert_node_in_order(node**, int);
void delete_linked_list(node**);

#endif
