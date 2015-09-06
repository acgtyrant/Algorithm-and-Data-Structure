#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

#include <algorithm>

template <typename RandomrIterator>
void InsertSort(RandomrIterator first, RandomrIterator end) {
  RandomrIterator temporary_iterator;
  for (auto iterator = first; iterator != end; ++iterator) {
    temporary_iterator = iterator;
    while (temporary_iterator > first &&
        *temporary_iterator < *(temporary_iterator - 1)) {
      std::iter_swap(temporary_iterator, temporary_iterator - 1);
      --temporary_iterator;
    }
  }
}

#endif // INSERT_SORT_H_
