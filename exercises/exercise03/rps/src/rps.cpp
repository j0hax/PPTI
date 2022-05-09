/**
 * @file rps.cpp
 */
#include "rps.h"
#include <sstream>

Move parseInput(const std::string& input) {
  if (input == "rock") {
    return Move::Rock;
  }

  if (input == "paper") {
    return Move::Paper;
  }

  if (input == "scissors") {
    return Move::Scissors;
  }

  return Move::Error;
}

Result rockPaperScissors(const std::string& p1, const std::string& p2) {
  Move r1 = parseInput(p1);
  Move r2 = parseInput(p2);

  if (r1 == r2 && r1 != Move::Error) {
    return Result::Tie;
  }

  // GCC will complain because of `-Wswitch`, but all cases are actually handled
  // and nothing falls through
  switch (r1) {
    case Move::Rock:
      switch (r2) {
        case Move::Paper:
          return Result::Player2Wins;
        case Move::Scissors:
          return Result::Player1Wins;
      }
    case Move::Paper:
      switch (r2) {
        case Move::Rock:
          return Result::Player1Wins;
        case Move::Scissors:
          return Result::Player2Wins;
      }
    case Move::Scissors:
      switch (r2) {
        case Move::Rock:
          return Result::Player2Wins;
        case Move::Paper:
          return Result::Player1Wins;
      }

    default:
      return Result::Invalid;
  }
}

int main(int argc, char** argv) {
  std::vector<std::string> args(argv, argv + argc);

  Result r = rockPaperScissors(args[1], args[2]);

  switch (r) {
    case Result::Player1Wins:
      std::cout << "Player 1 wins";
      break;
    case Result::Player2Wins:
      std::cout << "Player 2 wins";
      break;
    case Result::Tie:
      std::cout << "Tie";
      break;
    case Result::Invalid:
      std::cout << "Invalid Input" << std::endl;
      return 1;
  }

  std::cout << std::endl;
  return 0;
}
