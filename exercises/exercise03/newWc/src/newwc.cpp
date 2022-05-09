#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::istream& is, char delim) {
  std::vector<std::string> result;
  std::string elem;

  while (std::getline(is, elem, delim)) {
    if (elem != "")
      result.push_back(std::move(elem));
  }
  return result;
}

std::vector<std::string> split(const std::string& val, char delim) {
  std::stringstream is(val);
  return split(is, delim);
}

struct WCResult {
  std::string Name;
  std::size_t LineCount;
  std::size_t WordCount;
  std::size_t ByteCount;

  WCResult(const std::string& name = "",
           std::size_t lc = 0,
           std::size_t wc = 0,
           std::size_t bc = 0)
      : Name(name), LineCount(lc), WordCount(wc), ByteCount(bc) {}
  void output(std::ostream& os) {
    os << this->LineCount << " " << this->WordCount << " " << this->ByteCount
       << " " << this->Name << std::endl;
  }
};

WCResult getWordCount(std::istream& input, const std::string& name) {
  // Put file contents into a buffer to avoid constantly changing the current
  // character in the stream
  std::stringstream buf;
  buf << input.rdbuf();

  std::vector<std::string> lines = split(buf.str(), '\n');
  std::vector<std::string> words = split(buf.str(), ' ');

  return WCResult(name, lines.size(), words.size(), buf.str().size());
}

int main(int argc, char** argv) {
  std::vector<std::string> args(argv, argv + argc);

  std::ifstream ifs;
  for (size_t i = 1; i < args.size(); i++) {
    ifs.open(args[i]);
    getWordCount(ifs, args[i]).output(std::cout);
    ifs.close();
  }

  return 0;
}
