#include <cassert>
#include <cstring>

class String {
 public:
  String() : string_(new char[1]) { string_[0] = '\0'; }
  // Convert char * to String implicitly is allowed.
  String(const char *right_hand_side)
      : string_(new char[std::strlen(right_hand_side) + 1]) {
    std::strncpy(string_, right_hand_side, std::strlen(right_hand_side) + 1);
  }
  String(const String &right_hand_side) 
      : string_(new char[right_hand_side.size()]) {
    std::strncpy(string_, right_hand_side.string_, right_hand_side.size() + 1);
  }
  String(String &&right_hand_side) : string_(right_hand_side.string_) {
    right_hand_side.string_ = nullptr;
  }
  String &operator=(String right_hand_side) {
    swap(*this, right_hand_side);
    return *this;
  }
  ~String() { delete[] string_; }

  // O(n)
  int size() const {
    return std::strlen(string_);
  }

  char operator[](int index) const {
    assert(index >= 0 && index <= std::strlen(string_));
    return string_[index];
  }


 private:
  char *string_ = nullptr;

  friend void swap(String &left_hand_side, String &right_hand_side);
  friend bool operator==(String left_hand_side, String right_hand_side);
  friend bool operator<(String left_hand_side, String right_hand_side);
};

void swap(String &left_hand_side, String &right_hand_side);
bool operator==(String left_hand_side, String right_hand_side);
bool operator<(String left_hand_side, String right_hand_side);
