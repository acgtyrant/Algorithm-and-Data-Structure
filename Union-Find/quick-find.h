#include <vector>

class UnionFind final {
 public:
  UnionFind() = delete;
  explicit UnionFind(int numbers);
  UnionFind(const UnionFind &) = delete;
  UnionFind(UnionFind &&) = delete;
  UnionFind operator=(UnionFind) = delete;
  ~UnionFind() = default;

  void Union(int p, int q);
  bool Connected(int p, int q);
  // int Find(int p);
  // int Count();

 private:
  std::vector<int> array_;
  int size_;
};

UnionFind::UnionFind(int numbers) : size_(numbers) {
  for (int i = 0; i < numbers; ++i) array_.push_back(i);
};

void UnionFind::Union(int p, int q) {
  int p_component = array_[p];
  int q_component = array_[q];
  for (int i = 0; i < size_; ++i) {
    if (array_[i] == p_component) array_[i] = q_component;
  }
}

bool UnionFind::Connected(int p, int q) {
  return array_[p] == array_[q];
}
