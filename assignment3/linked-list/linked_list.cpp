// source file for linked-list-related functions
#include "linked_list.h"

// delete node from linked list
void delete_node(node** head, node* ptr_del) {

  // check if node to be deleted is the first in the list
  if (ptr_del == *head) {
    *head = (*head)->next; // reassign head of linked list
    (*head)->prev = NULL;
    delete ptr_del;
    return;
  }

  // node to be deleted is not first in the list, so it has a previous node
  // move previous node's next pointer to next node
  ptr_del->prev->next = ptr_del->next;

  // move next node's prev pointer to previous node
  if (ptr_del->next != NULL) {
    ptr_del->next->prev = ptr_del->prev;
  }

  delete ptr_del;
}

// add node containing n after current node
// assumes cur is not null
void add_node_after(node* cur, int n) {

  node* new_node = new node;
  new_node->x = n;

  // first assign pointers from new node (uses cur->next)
  new_node->prev = cur;
  new_node->next = cur->next;

  // then assign pointer from next node (uses cur->next)
  if (cur->next != NULL) {
    cur->next->prev = new_node;
  }

  // finally assign pointer from previous node (changes cur->next)
  cur->next = new_node;
}

// add node containing n before current node
// assumes cur is not null
void add_node_before(node* cur, int n) {

  node* new_node = new node;
  new_node->x = n;

  // first assign pointers from new node (uses cur->prev)
  new_node->prev = cur->prev;
  new_node->next = cur;

  // then assign pointer from previous node (uses cur->prev)
  if (cur->prev != NULL) {
    cur->prev->next = new_node;
  }

  // finally assign pointer from next node (changes cur->prev)
  cur->prev = new_node;
}

// add node to front of linked list and reassign head to new node
// special case of add_node_before where cur is head of a linked list
// pass reference to pointer to modify it outside of function
void add_node_to_front(node** head, int n) {
  add_node_before(*head, n);
  *head = (*head)->prev;
}

// add node containing n to linked list in ascending order, no duplicates
// assumes that existing linked list is sorted
// return true if inserted
// return false if not inserted (n already exists in list)
bool insert_node_in_order(node** head, int n) {

  // create new list if list does not exist
  if (*head == NULL) {
    *head = new node;
    (*head)->x = n;
    (*head)->prev = NULL;
    (*head)->next = NULL;
    return true;
  }

  // iterate through linked list and find ordered position
  // stops when equal or larger element is encountered
  // also stops at last element of list, so check if n goes at end of list
  node* cur = *head;
  while (cur->next != NULL && cur->x < n) {
    cur = cur->next;
  }

  // check if n already exists in list
  if (n == cur->x) {
    return false;
  }

  // check if n goes at end of list
  if (n > cur->x) {
    add_node_after(cur, n);
    return true;
  }

  // n comes before the head of the list
  // need to reassign head of linked list
  if (cur == *head) {
    add_node_to_front(head, n);
    return true;
  }

  // n comes after the head of the list, before current node
  add_node_before(cur, n);
  return true;
}

// delete linked list (all of its nodes)
void delete_linked_list(node** head) {
  node* tmp_node;
  while (*head != NULL) {
    tmp_node = *head;
    *head = (*head)->next;
    delete tmp_node;
  }
}
