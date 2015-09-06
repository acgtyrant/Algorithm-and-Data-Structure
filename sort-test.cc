#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "heap-sort.h"
#include "insertion-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "selection-sort.h"

namespace {

constexpr int kMin = 0;
constexpr int kMax = 100;

}

int main(void) {
  std::vector<int> nums;
  std::default_random_engine engine;
  std::uniform_int_distribution<int> unsigned_random(kMin, kMax);
  std::ofstream unsorted_int_fstream("unsorted-int.txt");
  // Push a new element to the vector and shuffle it.
  for (int index = kMin; index < kMax; ++index) {
    nums.push_back(index);
    std::iter_swap(
        nums.begin() + (unsigned_random(engine) - 1) % nums.size(),
        nums.end() - 1);
  }
  for (auto num : nums) unsorted_int_fstream << num << std::endl;
  unsorted_int_fstream.close();
  // You can choose a sort method by uncommenting out the relative line below.
  // std::sort(nums.begin(), nums.end());
  // HeapSort(nums.begin(), nums.end());
  // in_place::HeapSort(nums.begin(), nums.end());
  // InsertionSort(nums.begin(), nums.end());
  std::vector<int> temporary_vector(nums.begin(), nums.end());
  auto temporary_first = temporary_vector.begin();
  MergeSort(nums.begin(), nums.end(), temporary_first);
  // QuickSort(nums.begin(), nums.end());
  // SelectionSort(nums.begin(), nums.end());
  std::ofstream sorted_int_fstream("sorted-int.txt");
  for (int num : nums) sorted_int_fstream << num << std::endl;
  sorted_int_fstream.close();
  return 0;
}
