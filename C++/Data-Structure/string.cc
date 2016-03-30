#include "string.h"

#include <cstring>

void swap(String &left_hand_side, String &right_hand_side) {
  char *temporary_string = left_hand_side.string_;
  left_hand_side.string_ = right_hand_side.string_;
  right_hand_side.string_ = temporary_string;
}

bool operator==(String left_hand_side, String right_hand_side) {
  return std::strcmp(left_hand_side.string_, right_hand_side.string_);
}

bool operator<(String left_hand_side, String right_hand_side) {
  return std::strcmp(left_hand_side.string_, right_hand_side.string_) < 0;
}
