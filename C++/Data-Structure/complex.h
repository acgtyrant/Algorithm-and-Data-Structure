#include <utility>

class Complex final {
 public:
  Complex() = default;
  Complex(double real_part, double imaginary_part)
      : real_part_(real_part),
        imaginary_part_(imaginary_part) {}
  Complex(const Complex &) = default;
  Complex(Complex &&) = default;
  Complex &operator=(Complex right_hand_side) {
    using std::swap;
    swap(*this, right_hand_side);
    return *this;
  }
  ~Complex() = default;

  double GetRealPart() const { return real_part_; }
  void SetRealPart(double new_real_part) {
    real_part_ = new_real_part;
  }
  double GetImaginaryPart() const { return imaginary_part_; }
  void SetImaginaryPart(double new_imaginary_part) {
    imaginary_part_ = new_imaginary_part;
  }

 private:
  double real_part_ = 0;
  double imaginary_part_ = 0;

  friend const Complex AdditiveInverse(const Complex element);
  friend const Complex MultiplicativeInverse(const Complex element);
  friend const Complex AbsoluteValue(const Complex element);

  friend const Complex operator+(
      const Complex left_hand_side, const Complex right_hand_side);
  friend const Complex operator-(
      const Complex left_hand_side, const Complex right_hand_side);
  friend const Complex operator*(
      const Complex left_hand_side, const Complex right_hand_side);
  friend const Complex operator/(
      const Complex left_hand_side, const Complex right_hand_side);
  friend bool operator==(
      const Complex left_hand_side, const Complex right_hand_side);
  friend bool operator!=(
      const Complex left_hand_side, const Complex right_hand_side);
};

const Complex AdditiveInverse(const Complex element);
const Complex MultiplicativeInverse(const Complex element);
const Complex AbsoluteValue(const Complex element);

const Complex operator+(
    const Complex left_hand_side, const Complex right_hand_side);
const Complex operator-(
    const Complex left_hand_side, const Complex right_hand_side);
const Complex operator*(
    const Complex left_hand_side, const Complex right_hand_side);
const Complex operator/(
    const Complex left_hand_side, const Complex right_hand_side);
bool operator==(
    const Complex left_hand_side, const Complex right_hand_side);
bool operator!=(
    const Complex left_hand_side, const Complex right_hand_side);
