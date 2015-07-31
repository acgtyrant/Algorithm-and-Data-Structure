#include "binary-search.h"

#include <vector>

bool BinarySearch(
    const std::vector<int>::const_iterator first,
    const std::vector<int>::const_iterator last,
    const int value) {
  if (first == last) return false;
  auto middle = first + (last - first) / 2;
  if (*middle == value) return true;
  if (*middle > value) return BinarySearch(first, middle, value);
  if (*middle < value) return BinarySearch(middle + 1, last, value);
}

namespace iteration {

// first and last are not const.
bool BinarySearch(
    std::vector<int>::const_iterator first,
    std::vector<int>::const_iterator last,
    const int value) {
  std::vector<int>::const_iterator middle;
  while (first != last) {
    middle = first + (last - first) / 2;
    if (*middle == value) return true;
    if (*middle > value) last = middle;
    if (*middle < value) first = middle + 1;
  }
  return false;
}

}  // namespace iteration
