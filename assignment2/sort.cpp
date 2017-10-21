// source file for sort-related functions
#include "sort.h"

// sort array using QuickSort
// return number of comparisons made in partition subroutine
// start index included, end index excluded
long quick_sort(int* array, int start, int end) {
  int length = end - start;

  if (length <= 1) {
    return 0;
  }

  int pivot_index = choose_pivot_index(array, start, end);

  // partition around pivot and get correct sorted position of pivot
  int pivot_pos = partition(array, start, end, pivot_index);

  // partition subroutine compares pivot to all other elements
  long num_comparisons = length - 1;

  // recursively sort left and right sides (without pivot)
  num_comparisons += quick_sort(array, start, pivot_pos);
  num_comparisons += quick_sort(array, pivot_pos + 1, end);

  return num_comparisons;
}

// choose pivot index between given indices for partition subroutine of QuickSort
// start index included, end index excluded
// return index of median of first, middle, and last elements
int choose_pivot_index(int* array, int start, int end) {
  int elements[3];
  int element_indices[3];

  elements[0] = array[start]; // first element
  element_indices[0] = start;

  elements[1] = array[(end - 1 + start) / 2]; // middle element
  element_indices[1] = (end - 1 + start) / 2;

  elements[2] = array[end - 1]; // last element
  element_indices[2] = end - 1;

  // simplified bubble sort for 3 elements
  if (elements[0] > elements[1]) {
    swap(elements, 0, 1);
    swap(element_indices, 0, 1);
  }
  if (elements[1] > elements[2]) {
    swap(elements, 1, 2);
    swap(element_indices, 1, 2);
  }
  if (elements[0] > elements[1]) {
    swap(elements, 0, 1);
    swap(element_indices, 0, 1);
  }

  // median is in the middle
  return element_indices[1];
}

// partition elements within specified subarray around pivot
// return sorted pivot position
// all elements less than pivot to left of it, and
// all elements greater than pivot to right of it
// start index included, end index excluded
int partition(int* array, int start, int end, int pivot_index) {
  // place pivot at beginning of array
  swap(array, start, pivot_index);

  // track division between left and right sides of partitioned elements
  // loop invariant: i is positioned at first element of right side
  int i = start + 1;

  // traverse rest of array after pivot
  // loop invariant: all elements before j have been partitioned
  for (int j = start + 1; j < end; ++j) {
    // if current element < pivot, should be placed in right side
    if (array[j] < array[start]) {
      swap(array, i, j); // redundant swap if i = j, but still need to advance i
      ++i; // advance i to restore invariant
    }
  }

  // place pivot between left and right sides (correct sorted position)
  swap(array, start, i - 1);

  return i - 1;
}

// swap elements at indices x and y in array
void swap(int* array, int x, int y) {
  int temp = array[x];
  array[x] = array[y];
  array[y] = temp;
}
