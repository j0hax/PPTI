#ifndef SIEVE_H_
#define SIEVE_H_

#include <iostream>
#include <vector>

class Sieve {
 public:
  Sieve(std::vector<std::size_t>& numbers);
  void reduceToPrimes();
  void resetToSize(std::size_t size);
  void groupNumbers(std::size_t lowerBound, std::size_t upperBound);
  void printNumbers(std::ostream& os);

 private:
  std::vector<std::size_t> numbers;
};

#endif
