/**
 * count_inversions.cpp
 *
 * Kelvin Wong
 * kwong691@gmail.com
 *
 * Count the number of inversions in list of numbers
 */

#include <iostream>
#include <vector>
#include "Vector_inversions.h"

int main() {
  // store list of numbers
  std::vector<int> numbers;

  // read numbers from input stream
  int n;
  while (std::cin >> n) {
    numbers.push_back(n);
  }

  std::cout << "n: " << numbers.size() << std::endl;

  // count number of inversions
  Vector_inversions result = sort_and_count(numbers, numbers.size());

  std::cout << "number of inversions: " << result.num_inversions << std::endl;

  return 0;
}
