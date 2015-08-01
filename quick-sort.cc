#include "quick-sort.h"

#include <algorithm>
#include <vector>

namespace {

std::vector<int>::iterator MedianOf3(
    std::vector<int>::iterator one,
    std::vector<int>::iterator two,
    std::vector<int>::iterator three) {
  return std::min_element(one, std::min_element(two, three));
}

}  // namespace

void QuickSort(
    const std::vector<int>::iterator first,
    const std::vector<int>::iterator last) {
  if (first == last || first + 1 == last) return;
  std::random_shuffle(first + 1, last);
  auto low = first + 1;
  auto high = last - 1;
  auto partition = first;
  if (first + 2 < last) {
    auto median = MedianOf3(
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
