// source file for sort-related functions
#include "sort.h"

// sort array from indices start to end (end index exclusive)
// and count number of inversions
long sort_and_count(int* array, int start, int end) {

  // length of array to be sorted
  int len = end - start;

  // check that array needs sorting
  if (len == 1) {
    // no sorting can be done, and no inversions
    return 0;
  }

  // sort and count inversions in each half of array
  long num_left_inversions = sort_and_count(array, start, start + len / 2);
  long num_right_inversions = sort_and_count(array, start + len / 2, end);

  // merge sorted halves and count number of split inversions
  long num_split_inversions = merge_and_count_split_inv(array,
      start, start + len / 2, end);

  return num_left_inversions + num_right_inversions + num_split_inversions;
}

// merge sorted subarrays defined by start, mid, and end indices
// and count number of split inversions
// assuming subarrays are contiguous, with first one preceding the second
long merge_and_count_split_inv(int* array, int start, int mid, int end) {

  long num_split_inversions = 0;

  int len = end - start;

  int merged[len]; // to store merged array

  // merge two sorted subarrays
  int j = start;
  int k = mid;
  for (int i = 0; i < len; ++i) {
    // check that indices point to elements in the subarrays
    if (j < mid && k < end) {
      if (array[j] <= array[k]) { // include equivalent values so not counted as split inversions
        merged[i] = array[j];
        ++j;
      } else {
        // element from right comes before elements in left,
        // so split inversions
        // increment by number of elements remaining in left subarray
        num_split_inversions += mid - j;

        merged[i] = array[k];
        ++k;
      }
    } else if (!(j < mid)) {
      // copy rest of right subarray to merged, no more inversions
      for (; k < end; ++k) {
        merged[i] = array[k];
        ++i;
      }
    } else if (!(k < end)) {
      // copy rest of left subarray to merged
      for (; j < mid; ++j) {
        merged[i] = array[j];
        ++i;
      }
    }
  }

  // replace elements in original array with merged elements
  for (int i = 0; i < len; ++i) {
    array[start + i] = merged[i];
  }

  return num_split_inversions;
}
