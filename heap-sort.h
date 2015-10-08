#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include <algorithm>

namespace heap_sort_h_ {

template <typename RandomIterator>
void Sink(RandomIterator iterator, RandomIterator first, RandomIterator last) {
  auto left_child = first + (iterator - first) * 2 + 1;
  auto right_child = left_child + 1;
  auto child = left_child;
  while (left_child < last) {
    if (right_child < last && *right_child > *left_child) {
      child = right_child;
    }
    if (*child > *iterator) {
      std::iter_swap(iterator, child);
      iterator = child;
      left_child = first + (iterator - first) * 2 + 1;
      right_child = left_child + 1;
      child = left_child;
    } else {
      break;
    }
  }
}

template <typename RandomIterator>
void BuildHeap(RandomIterator first, RandomIterator last) {
  for (auto iterator = first + (last - first) / 2 - 1;
      iterator >= first;
      --iterator) {
    heap_sort_h_::Sink(iterator, first, last);
  }
}

}

template <typename RandomIterator>
void HeapSort(RandomIterator first, RandomIterator last) {
  BuildHeap(first, last);
  auto iterator = last - 1;
  while (iterator > first) {
    std::iter_swap(first, iterator);
    heap_sort_h_::Sink(first, first, iterator);
    --iterator;
  }
}

#endif // HEAP_SORT_H_
