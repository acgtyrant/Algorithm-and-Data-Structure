#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

class BinaryHeap {
 public:
  BinaryHeap(
      std::vector<int>::iterator first,
      std::vector<int>::iterator last) {
    for (auto iterator = first; iterator != last; ++iterator)
      Insert(*iterator);
  }

  void Insert(int data);
  int DeleteMax();
  void Sort();

 private:
  void Swim(std::vector<int>::iterator index);
  void Sink(std::vector<int>::iterator index);
  // It judge the priority between two nodes.
  bool Superior(
      std::vector<int>::iterator former,
      std::vector<int>::iterator later) {
    // For simplicity, we construct a max priority queue.
    return (*former < *later);
  }
  std::vector<int>::iterator Parent(std::vector<int>::iterator index) {
    if (index == priority_query_.begin()) return priority_query_.begin();
    return priority_query_.begin() +
           (index - priority_query_.begin() + 1) / 2 - 1;
  }
  std::vector<int>::iterator Child(std::vector<int>::iterator index) {
    return priority_query_.begin() +
           (index - priority_query_.begin() + 1) * 2 - 1;
  }

  std::vector<int> priority_query_;
};

void HeapSort(
    std::vector<int>::iterator first,
    std::vector<int>::iterator last);

#endif // HEAP_SORT_H
