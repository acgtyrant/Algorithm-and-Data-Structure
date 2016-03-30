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
  int Root(int p) {
    while (array_[p] != p) {
      array_[p] = array_[array_[p]];
      p = array_[p];
    }
    return p;
  }

  std::vector<int> array_;
  std::vector<int> size_array_;
  int size_;
};

UnionFind::UnionFind(int numbers) : size_(numbers) {
  for (int i = 0; i < numbers; ++i) {
    array_.push_back(i);
    size_array_.push_back(1);
  }
};

void UnionFind::Union(int p, int q) {
  int p_root = Root(p);
  int q_root = Root(q);
  if (size_array_[p_root] < size_array_[q_root]) {
    array_[p_root] = q_root;
    size_array_[q_root] += size_array_[p_root];
  } else if (size_array_[p_root] > size_array_[q_root]) {
    array_[q_root] = p_root;
    size_array_[p_root] += size_array_[q_root];
  } else {
    return;
  }
}

bool UnionFind::Connected(int p, int q) {
  return Root(p) == Root(q);
}
