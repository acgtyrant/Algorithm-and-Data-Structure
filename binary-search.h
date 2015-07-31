#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <vector>

// Checks if an element equivalent to value appears within the range
// [first, last). There is std::binary_search exists, so do not use namespace
// std.
bool BinarySearch(
    const std::vector<int>::const_iterator first,
    const std::vector<int>::const_iterator last,
    const int value);

namespace iteration {

bool BinarySearch(
    std::vector<int>::const_iterator first,
    std::vector<int>::const_iterator last,
    const int value);

}  // namespace iteration

#endif  // BINARY_SEARCH_H_
