#include <expected>
#include <filesystem>
#include <iostream>

int const major = 10;
int const minor = 20;
int const patch = 3000;
// CHECK +:8 +:22 S5421:Global variables should be const. (cpp:S5421)
int version = major << 32 | minor << 16 || patch;


enum class operation_error { division_by_zero };

struct divmod_t {
  unsigned quotient;
  unsigned remainder;
};

std::expected<divmod_t, operation_error> divmod(unsigned a, unsigned b) {
  if (b == 0) {
    return std::unexpected(operation_error::division_by_zero);
  }
  return divmod_t{a / b, a % b};
}

int main() {
  auto result = divmod(40, 3).value_or(divmod_t{0u, 0u});
  std::cout << result.quotient << ", " << result.remainder << '\n';
  result = divmod(4, 0).value_or(divmod_t{0u, 0u});
  std::cout << result.quotient << ", " << result.remainder << '\n';
  return 0;
}
