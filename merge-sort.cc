#include "merge-sort.h"

#include <algorithm>
#include <vector>

namespace {

void Merge(
    const std::vector<int>::const_iterator first,
    const std::vector<int>::const_iterator last,
    std::vector<int>::iterator tmp_iterator) {
  // We do not need to judge first == last, because Sort() do it.
  const auto middle = first + (last - first) / 2;
  auto first_half_iterator = first;
  auto second_half_iterator = middle;
  while (first_half_iterator != middle &&
         second_half_iterator != last) {
    if (*first_half_iterator < *second_half_iterator)
      *tmp_iterator++ = *first_half_iterator++;
    if (*first_half_iterator > *second_half_iterator)
      *tmp_iterator++ = *second_half_iterator++;
  }
  if (first_half_iterator == middle)
    while (second_half_iterator != last)
      *tmp_iterator++ = *second_half_iterator++;
  if (second_half_iterator == last)
    while (first_half_iterator != middle)
      *tmp_iterator++ = *first_half_iterator++;
}

// Sorts the elements in the range [first, last) too.
void Sort(
    const std::vector<int>::const_iterator first,
    const std::vector<int>::const_iterator last,
    std::vector<int>::iterator tmp_iterator) {
  if (first == last || first + 1 == last) return;
  Sort(first, first + (last - first) / 2,
       tmp_iterator);
  Sort(first + (last - first) / 2, last,
       tmp_iterator + (last - first) / 2);
  Merge(first, last, tmp_iterator);
}

}  // namespace

// Sorts the elements in the range [first, last) in ascending order.
// We will use std::copy to copy from tmp_vector.begin() to first, so we do not
// use const_iterator.
void MergeSort(
    const std::vector<int>::iterator first,
    const std::vector<int>::iterator last) {
  // Get the same size as nums, so we can use some stable iteartors later.
  std::vector<int> tmp_vector(last - first);
  Sort(first, last, tmp_vector.begin());
  std::copy(tmp_vector.begin(), tmp_vector.end(), first);
}
