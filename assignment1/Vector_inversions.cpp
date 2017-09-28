// source file for Vector_inversions-related functions
#include "Vector_inversions.h"

// sort list of size n and count number of inversions
Vector_inversions sort_and_count(const std::vector<int>& list, int n) {

  Vector_inversions result;

  // check that list needs sorting
  if (n == 1) {
    result.list = list;
    result.num_inversions = 0;
    return result;
  }

  // create iterators to split list in half
  //std::vector<int>::const_iterator first = list.begin();
  //std::vector<int>::const_iterator mid = list.begin() + n / 2;
  //std::vector<int>::const_iterator last = list.begin() + n;

  //Vector_inversions left_results = sort_and_count(std::vector<int> left(first, mid), n / 2);
  //Vector_inversions right_results = sort_and_count(std::vector<int> right(mid, last), n - n / 2);

  // create left half list and results
  std::vector<int> left;
  for (int i = 0; i < n / 2; i++) {
    left.push_back(list[i]);
  }
  Vector_inversions left_results = sort_and_count(left, n / 2);

  // create right half list and results
  std::vector<int> right;
  for (int i = n / 2; i < n; i++) {
    right.push_back(list[i]);
  }
  Vector_inversions right_results = sort_and_count(right, n - n / 2);

  Vector_inversions merged_results = merge_and_count_split_inv(left_results.list, right_results.list, n);

  // return sorted list and total number of inversions
  result.list = merged_results.list;
  result.num_inversions = left_results.num_inversions + right_results.num_inversions + merged_results.num_inversions;
  return result;
}

// merge two lists (total size n) and count number of split inversions
Vector_inversions merge_and_count_split_inv(const std::vector<int>& list1,
    const std::vector<int>& list2, int n) {

  std::vector<int> merged;
  long num_split_inversions = 0;

  int list1_size = list1.size();
  int list2_size = list2.size();

  // merge two sorted lists
  int j = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    // indices point to elements in the lists
    if (j < list1_size && k < list2_size) {
      if (list1[j] <= list2[k]) { // include equivalent values so not counted as split inversions
        merged.push_back(list1[j]);
        j++;
      } else {
        // element from right comes before elements in left,
        // so split inversions
        // increment by number of elements remaining in list1
        num_split_inversions += list1_size - j;

        merged.push_back(list2[k]);
        k++;
      }
    } else if (!(j < list1_size)) {
      // copy rest of list2 to merged
      for (; k < list2_size; k++) {
        merged.push_back(list2[k]);
      }
      break;
    } else if (!(k < list2_size)) {
      // copy rest of list1 to merged
      for (; j < list1_size; j++) {
        merged.push_back(list1[j]);
      }
      break;
    }
  }

  Vector_inversions result;
  result.list = merged;
  result.num_inversions = num_split_inversions;
  return result;
}
