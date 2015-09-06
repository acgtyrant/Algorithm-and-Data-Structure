#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <algorithm>
#include <vector>

#include "insert-sort.h"

namespace mergesort {

constexpr int cutoff = 3;

template <typename RandomIterator>
void Merge(
    RandomIterator first,
    RandomIterator last,
    RandomIterator tmp_iterator) {
  // We do not need to judge first == last, because Sort() do it.
  const auto middle = first + (last - first) / 2;
  auto first_half_iterator = first;
  auto second_half_iterator = middle;
  while (first_half_iterator != middle &&
         second_half_iterator != last) {
    if (*first_half_iterator < *second_half_iterator) {
      *tmp_iterator++ = *first_half_iterator++;
    } else {
      *tmp_iterator++ = *second_half_iterator++;
    }
  }
  if (first_half_iterator == middle)
    while (second_half_iterator != last)
      *tmp_iterator++ = *second_half_iterator++;
  if (second_half_iterator == last)
    while (first_half_iterator != middle)
      *tmp_iterator++ = *first_half_iterator++;
}

// Sorts the elements in the range [first, last) too.
template <typename RandomIterator>
void Sort(
    RandomIterator first,
    RandomIterator last,
    RandomIterator tmp_iterator) {
  if (first == last || first + 1 == last) return;
  if (last - first < mergesort::cutoff) {
    InsertSort(first, last);
    return;
  }
  Sort(first, first + (last - first) / 2,
       tmp_iterator);
  Sort(first + (last - first) / 2, last,
       tmp_iterator + (last - first) / 2);
  Merge(first, last, tmp_iterator);
  std::copy(tmp_iterator, tmp_iterator + (last - first), first);
}

}  // namespace

// Sorts the elements in the range [first, last) in ascending order.
// We will use std::copy to copy from tmp_vector.begin() to first, so we do not
// use const_iterator.
template <typename RandomIterator>
void MergeSort(
    RandomIterator first,
    RandomIterator last,
    RandomIterator temporary_first) {
    // use as an iterator of the temporary vector, so it requires the caller
    // construct an temporary vector and pass it.
  mergesort::Sort(first, last, temporary_first);
  std::copy(temporary_first, temporary_first + (last - first), first);
}

#endif  // MERGE_SORT_H_
