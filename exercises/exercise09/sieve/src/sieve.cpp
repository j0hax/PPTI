#include "sieve.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

Sieve::Sieve(std::vector<std::size_t>& numbers) : numbers(numbers) {}

void Sieve::reduceToPrimes() {
  sort(this->numbers.begin(), this->numbers.end());

  const std::size_t m =
      *std::max_element(this->numbers.begin(), this->numbers.end());
  const std::size_t coeff_limit = static_cast<std::size_t>(std::sqrt(m));

  for (std::size_t c = 2; c <= coeff_limit; ++c) {
    // remove multiples of the coeffecient c
    std::size_t i = static_cast<std::size_t>(std::pow(c, 2));
    for (; i <= m; i += c) {
      this->numbers.erase(
          std::remove(this->numbers.begin(), this->numbers.end(), i),
          this->numbers.end());
    }
  }
}

void Sieve::resetToSize(std::size_t size) {
  const auto biggerThan = [&size](const auto& i) { return i > size; };

  this->numbers.erase(
      std::remove_if(this->numbers.begin(), this->numbers.end(), biggerThan),
      this->numbers.end());
  // Add the missing elements
  for (std::size_t i = 2; i <= size; ++i) {
    if (std::find(this->numbers.begin(), this->numbers.end(), i) ==
        this->numbers.end()) {
      this->numbers.push_back(i);
    }
  }

  // Sort again, in descending order
  std::sort(this->numbers.begin(), this->numbers.end(), std::greater<>());
}

void Sieve::groupNumbers(std::size_t lowerBound, std::size_t upperBound) {
  std::stable_partition(
      this->numbers.begin(), this->numbers.end(),
      [&](const auto& n) { return lowerBound < n && n < upperBound; });
}

void Sieve::printNumbers(std::ostream& os) {
  os << "{";
  for (std::size_t i = 0; i < this->numbers.size() - 1; ++i) {
    os << this->numbers[i] << ", ";
  }
  os << this->numbers[this->numbers.size() - 1] << "}\n\n" << std::flush;
}
