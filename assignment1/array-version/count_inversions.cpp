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
#include "sort.h"

int main() {
  // store input of numbers
  std::vector<int> input;

  // read numbers from input stream
  int n;
  int len = 0;
  while (std::cin >> n) {
    input.push_back(n);
    ++len;
  }

  // transfer input to array
  int numbers[len];
  for (int i = 0; i < len; ++i) {
    numbers[i] = input[i];
  }

  std::cout << "n: " << len << std::endl;

  // count number of inversions
  long result = sort_and_count(numbers, 0, len);

  std::cout << "number of inversions: " << result << std::endl;

  return 0;
}
