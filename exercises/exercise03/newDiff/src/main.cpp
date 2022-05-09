#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define NOBONUS

void compareFilesLineByLine(const std::vector<std::string>&,
                            const std::vector<std::string>&);

int main(int argc, char** argv) {
  std::vector<std::string> arguments(argv, argv + argc);

  std::ifstream input;

  std::vector<std::string> aContents;
  std::vector<std::string> bContents;

  std::string line;

  input.open(arguments[1]);
  while (std::getline(input, line)) {
    aContents.push_back(line);
  }
  
  input.close();
  input.open(arguments[2]);

  while (std::getline(input, line)) {
    bContents.push_back(line);
  }

  input.close();

  compareFilesLineByLine(aContents, bContents);

  return 0;
}

#if defined(NOBONUS)
void compareFilesLineByLine(const std::vector<std::string>& lines1,
                            const std::vector<std::string>& lines2) {

  // Establish which file is shorter than the other
  const std::vector<std::string>& shortest =
      lines1.size() <= lines2.size() ? lines1 : lines2;
  const std::vector<std::string>& longest =
      lines1.size() >= lines2.size() ? lines1 : lines2;
  
  // Line counter
  size_t i = 0;

  // Compare with the fewest elements
  for (; i < shortest.size(); i++) {
    if (lines1[i] != lines2[i]) {
      std::cout << "<<<" << (i+1) << "<<<" << lines1[i] << std::endl;
      std::cout << ">>>" << (i+1) << ">>>" << lines2[i] << std::endl;
      std::cout << std::endl;
    }
  }

  // publish the rest of the longer file
  for (; i < longest.size(); i++) {
    std::cout << ">>>" << (i+1) << ">>>" << longest[i] << std::endl;
  }
}
#else

void compareFilesLineByLine(const std::vector<std::string>& lines1,
                            const std::vector<std::string>& lines2) {
  // Implement here
}
#endif
