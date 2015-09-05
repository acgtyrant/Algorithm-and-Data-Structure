#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include <algorithm>

template <typename ForwardIterator>
void SelectionSort(
    ForwardIterator first,
    ForwardIterator last) {
  for (auto iterator = first; iterator != last; ++iterator)
    std::iter_swap(iterator, std::min_element(iterator, last));
}

#endif // SELECTION_SORT_H_
