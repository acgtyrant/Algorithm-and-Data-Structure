#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

// Checks if an element equivalent to value appears within the range
// [first, last). There is std::binary_search exists, so do not use namespace
// std.

template <typename RandomrIterator, typename T>
bool BinarySearch(
    RandomrIterator first,
    RandomrIterator last,
    const T value) {
  if (first == last) return false;
  auto middle = first + (last - first) / 2;
  if (*middle == value) return true;
  if (*middle > value) return BinarySearch(first, middle, value);
  if (*middle < value) return BinarySearch(middle + 1, last, value);
}

namespace iteration {

template <typename RandomrIterator, typename T>
// first and last are not const.
bool BinarySearch(
    RandomrIterator first,
    RandomrIterator last,
    const T value) {
  RandomrIterator middle;
  while (first != last) {
    middle = first + (last - first) / 2;
    if (*middle == value) return true;
    if (*middle > value) last = middle;
    if (*middle < value) first = middle + 1;
  }
  return false;
}

}  // namespace iteration

#endif  // BINARY_SEARCH_H_
