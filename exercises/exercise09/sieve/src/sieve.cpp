#include "sieve.h"
#include <algorithm>
#include <iostream>
#include <vector>

Sieve::Sieve(std::vector<std::size_t>& numbers) : numbers(numbers) {}

void Sieve::reduceToPrimes() {
  // TODO: Implement reduceToPrimes
}

void Sieve::resetToSize(std::size_t size) {
  // TODO: Implement resetToSize
}

void Sieve::groupNumbers(std::size_t lowerBound, std::size_t upperBound) {
  // TODO: Implement groupNumbers
}

void Sieve::printNumbers(std::ostream& os) {
  os << "{";
  for (std::size_t i = 0; i < this->numbers.size() - 1; ++i) {
    os << this->numbers[i] << ", ";
  }
  os << this->numbers[this->numbers.size() - 1] << "}\n\n" << std::flush;
}
