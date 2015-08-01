#include "quick-sort.h"

#include <vector>

void QuickSort(
    const std::vector<int>::iterator first,
    const std::vector<int>::iterator last) {
  if (first == last || first + 1 == last) return;
  auto low = first + 1;
  auto high = last - 1;
  auto partition = first;
  while (low <= high) {
    while (*low < *partition && low != last) ++low;
    while (*high > *partition && high != first) --high;
    if (low < high) std::iter_swap(low, high);
  }
  std::iter_swap(first, low - 1);
  QuickSort(first, low - 1);
  QuickSort(low, last);
}
