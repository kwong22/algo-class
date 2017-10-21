/**
 * count_comparisons.cpp
 *
 * Kelvin Wong
 * kwong691@gmail.com
 *
 * Count the number of comparisons made during QuickSort
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

  // count number of comparisons made
  long result = quick_sort(numbers, 0, len);

  std::cout << "number of comparisons: " << result << std::endl;

  return 0;
}
