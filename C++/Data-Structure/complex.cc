#include "complex.h"

#include <cassert>
#include <cmath>

const Complex AdditiveInverse(const Complex element) {
  return Complex(-element.real_part_, -element.imaginary_part_);
}
const Complex MultiplicativeInverse(const Complex element) {
  assert(element.real_part_ != 0 && element.imaginary_part_ != 0);
  auto sum_of_squares = 
      element.real_part_ * element.real_part_ +
      element.imaginary_part_ * element.imaginary_part_;
  return Complex(
      element.real_part_ / sum_of_squares,
      element.imaginary_part_ / sum_of_squares);
}
const Complex AbsoluteValue(const Complex element) {
  return Complex(
      std::abs(element.real_part_),
      std::abs(element.imaginary_part_));
}

const Complex operator+(
    const Complex left_hand_side, const Complex right_hand_side) {
  return Complex(
      left_hand_side.real_part_ + right_hand_side.real_part_,
      left_hand_side.imaginary_part_ + right_hand_side.imaginary_part_);
}

const Complex operator-(
    const Complex left_hand_side, const Complex right_hand_side) {
  return left_hand_side + AdditiveInverse(right_hand_side);
}
const Complex operator*(
    const Complex left_hand_side, const Complex right_hand_side) {
  return Complex(
      left_hand_side.real_part_ * right_hand_side.real_part_ -
      left_hand_side.imaginary_part_ * right_hand_side.real_part_,
      left_hand_side.real_part_ * right_hand_side.imaginary_part_ +
      left_hand_side.imaginary_part_ + right_hand_side.real_part_);
}
const Complex operator/(
    const Complex left_hand_side, const Complex right_hand_side) {
  return left_hand_side * MultiplicativeInverse(right_hand_side);
}
bool operator==(
    const Complex left_hand_side, const Complex right_hand_side) {
  return (left_hand_side.real_part_ == right_hand_side.real_part_ &&
         left_hand_side.imaginary_part_ == right_hand_side.imaginary_part_);
}
bool operator!=(
    const Complex left_hand_side, const Complex right_hand_side) {
  return !(left_hand_side == right_hand_side);
}
