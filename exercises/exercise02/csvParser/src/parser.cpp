/**
 * @file parser.cpp
 */
#include "parser.h"
#include <sstream>

std::vector<std::string> split(std::istream &is, char delim) {
  std::vector<std::string> result;

  for (std::string field; std::getline(is, field, delim);) {
    // skip empty fields
    if (field.empty()) {
      continue;
    }

    result.push_back(field);
  }

  return result;
}

std::vector<IndexedString> parse(std::istream &is) {
  std::vector<IndexedString> strings;

  // First, split all entries
  std::vector<std::string> results = split(is, ';');

  // Then, iterate over each result
  for (auto it = std::begin(results); it != std::end(results); ++it) {
    // Assuming each CSV is a perfect pair, we can just increase the iterator
    strings.push_back({std::stoi(*it), *++it});
  }

  return strings;
}

void writeSentence(std::ostream &os,
                   const std::vector<IndexedString> &strings) {
  // Because there was no mention of the <algorithm> header in the assignment, I
  // will not be using std::sort or std::find
  for (int i = 0; i < strings.size(); i++) {
    // search for i in the vector
    for (IndexedString s : strings) {
      // if we find the wanted index, write it
      if (std::get<0>(s) == i) {
        os << std::get<1>(s);
      }
    }
  }
}
