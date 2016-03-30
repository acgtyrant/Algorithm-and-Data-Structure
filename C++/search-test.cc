// A simple test case, I will replace it with unittest framework in future.
#include "binary-search.h"

#include <cassert>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

namespace {

constexpr int target = 100;  // value to search

}  // namespace

int main(void) {
  // You need to edit the file manually to test...
  std::ifstream input("sorted-int.txt");
  int num;
  std::vector<int> nums;
  while (input >> num)
    nums.push_back(num);
  input.close();
  assert(nums.size() > 0);
  assert(std::is_sorted(nums.cbegin(), nums.cend()));
  // You can choose two implemetations.
  if (BinarySearch(nums.cbegin(), nums.cend(), target)) {
    // if (tail_recursion::BinarySearch(nums.cbegin(), nums.cend(), target)) {
    std::cout << "Find it." << std::endl;
  } else {
    std::cout << "No such one." << std:: endl;
  }
  return 0;
}
