#ifndef GUARD_Vector_inversions
#define GUARD_Vector_inversions

// Vector_inversions.h header file
#include <vector>

struct Vector_inversions {
  std::vector<int> list;
  long num_inversions; // long to handle larger datasets
};

Vector_inversions sort_and_count(const std::vector<int>&, int);
Vector_inversions merge_and_count_split_inv(const std::vector<int>&,
    const std::vector<int>&,
    int);

#endif
