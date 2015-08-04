#include "heap-sort.h"

#include <algorithm>
#include <cassert>
#include <vector>

void BinaryHeap::Insert(int data) {
  priority_query_.push_back(data);
  Swim(priority_query_.end() - 1);
}

int BinaryHeap::DeleteMax() {
  int return_val = priority_query_.front();
  std::iter_swap(priority_query_.begin(), priority_query_.end() - 1);
  priority_query_.pop_back();
  Sink(priority_query_.begin());
  return return_val;
}

void BinaryHeap::Sort() {
  auto index = Parent(priority_query_.end() - 1);
  while (index >= priority_query_.begin()) {
    Sink(index);
    --index;
  }
}

void BinaryHeap::Swim(std::vector<int>::iterator index) {
  auto parent = Parent(index);
  while (index > priority_query_.begin() && Superior(index, parent)) {
    std::iter_swap(parent, index);
    index = parent;
    parent = Parent(index);
  }
}

void BinaryHeap::Sink(std::vector<int>::iterator index) {
  auto child = Child(index);
  while (child < priority_query_.end() && Superior(child, index)) {
    // child + 1 is right_child of index while child is left_child of index.
    if (child + 1 < priority_query_.end() && Superior(child + 1, child))
      child = child + 1;
    std::iter_swap(index, child);
    index = child;
    child = Child(index);
  }
}

void HeapSort(
    std::vector<int>::iterator first,
    std::vector<int>::iterator last) {
  BinaryHeap binary_heap(first, last);
  for (auto iterator = first; iterator != last; ++iterator)
    *iterator = binary_heap.DeleteMax();
}

namespace in_place {

void BinaryHeap::Sort() {
  for (auto index = Parent(last_ - 1); index >= first_; --index)
    Sink(index);
  while (last_ - 1 > first_) {
    std::iter_swap(first_, last_ - 1);
    Sink(first_);
    --last_;
  }
}

void BinaryHeap::Swim(std::vector<int>::iterator index) {
  auto parent = Parent(index);
  while (index > first_ && Superior(index, parent)) {
    std::iter_swap(parent, index);
    index = parent;
    parent = Parent(index);
  }
}

void BinaryHeap::Sink(std::vector<int>::iterator index) {
  auto child = Child(index);
  while (child < last_ && Superior(child, index)) {
    // child + 1 is right_child of index while child is left_child of index.
    if (child + 1 < last_ && Superior(child + 1, child))
      child = child + 1;
    std::iter_swap(index, child);
    index = child;
    child = Child(index);
  }
}

void HeapSort(
    std::vector<int>::iterator first,
    std::vector<int>::iterator last) {
  BinaryHeap binary_heap(first, last);
  binary_heap.Sort();
}

}  // in_place
