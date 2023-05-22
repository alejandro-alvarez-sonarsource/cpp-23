#include <expected>
#include <filesystem>
#include <iostream>

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
