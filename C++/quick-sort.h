#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <algorithm>

#include "insertion-sort.h"

// bad namespace scope while it is included in headfile
namespace quick_sort_h_ {

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
  if (last - first < quick_sort_h_::cutoff) return InsertionSort(first, last);
  std::random_shuffle(first + 1, last);
  if (first + 2 < last) {
    auto median = quick_sort_h_::MedianOf3(
        first,
        first + (last - first) / 2,
        last - 1);
    std::iter_swap(first, median);
  }
  auto partition_value = *first;
  auto less = first;
  auto equal = first + 1;
  auto more = last - 1;
  while (equal <= more) {
    if (*equal < partition_value) {
      std::iter_swap(equal, less);
      ++equal;
      ++less;
    } else if (*equal > partition_value) {
      std::iter_swap(equal, more);
      --more;
    } else {
      ++equal;
    }
  }
  QuickSort(first, less);
  QuickSort(equal, last);
}

#endif // QUICK_SORT_H_
