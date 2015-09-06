#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <algorithm>

#include "insertion-sort.h"

// bad namespace scope while it is included in headfile
namespace quicksort {

template <typename ForwardIterator>
ForwardIterator MedianOf3(
    ForwardIterator one,
    ForwardIterator two,
    ForwardIterator three) {
  return std::min_element(one, std::min_element(two, three));
}

constexpr int cutoff = 3;

}  // namespace

template <typename RandomIterator>
void QuickSort(
    RandomIterator first,
    RandomIterator last) {
  if (last - first < quicksort::cutoff) return InsertionSort(first, last);
  std::random_shuffle(first + 1, last);
  auto low = first + 1;
  auto high = last - 1;
  auto partition = first;
  if (first + 2 < last) {
    auto median = quicksort::MedianOf3(
        first,
        first + (last - first) / 2,
        last - 1);
    std::iter_swap(partition, median);
  }
  while (low <= high) {
    while (*low < *partition && low != last) ++low;
    while (*high > *partition && high != first) --high;
    if (low < high) std::iter_swap(low, high);
  }
  std::iter_swap(first, low - 1);
  QuickSort(first, low - 1);
  QuickSort(low, last);
}

namespace anti_duplicate {

template <typename RandomIterator>
void QuickSort(
    RandomIterator first,
    RandomIterator last);

}  // anti_duplicate

#endif // QUICK_SORT_H_
