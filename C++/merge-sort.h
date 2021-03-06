#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <algorithm>
#include <vector>

#include "insertion-sort.h"

namespace merge_sort_h_ {

constexpr int cutoff = 3;

template <typename RandomIterator>
void Merge(
    RandomIterator first,
    RandomIterator last,
    RandomIterator temporary_iterator) {
  // We do not need to judge first == last, because Sort() do it.
  const auto middle = first + (last - first) / 2;
  auto first_half_iterator = first;
  auto second_half_iterator = middle;
  while (first_half_iterator != middle &&
         second_half_iterator != last) {
    if (*first_half_iterator < *second_half_iterator) {
      *temporary_iterator++ = *first_half_iterator++;
    } else {
      *temporary_iterator++ = *second_half_iterator++;
    }
  }
  if (first_half_iterator == middle)
    while (second_half_iterator != last)
      *temporary_iterator++ = *second_half_iterator++;
  if (second_half_iterator == last)
    while (first_half_iterator != middle)
      *temporary_iterator++ = *first_half_iterator++;
}

// Sorts the elements in the range [first, last) too.
template <typename RandomIterator>
void Sort(
    RandomIterator first,
    RandomIterator last,
    RandomIterator temporary_iterator) {
  if (last - first < merge_sort_h_::cutoff) {
    InsertionSort(first, last);
    std::copy(first, last, temporary_iterator);
    return;
  }
  Sort(
      temporary_iterator,
      temporary_iterator + (last - first) / 2,
      first);
  Sort(
      temporary_iterator + (last - first) / 2,
      temporary_iterator + (last - first),
      first + (last - first) / 2);
  Merge(first, last, temporary_iterator);
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
  merge_sort_h_::Sort(first, last, temporary_first);
  std::copy(temporary_first, temporary_first + (last - first), first);
}

#endif  // MERGE_SORT_H_
