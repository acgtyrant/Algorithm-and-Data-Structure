#include "selection-sort.h"

#include <algorithm>
#include <vector>

void SelectionSort(
    std::vector<int>::iterator first,
    std::vector<int>::iterator last) {
  for (auto iterator = first; iterator != last; ++iterator)
    std::iter_swap(iterator, std::min_element(iterator, last));
}
