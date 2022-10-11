#include <stdexcept>

float division(int a, int b) {
  if (b == 0) throw std::invalid_argument("Input Error: can't divide by zero!");
  return (float)a / b;
}
