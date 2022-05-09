#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define NOBONUS

void compareFilesLineByLine(const std::vector<std::string>&,
                            const std::vector<std::string>&);

int main(int argc, char** argv)
{
    std::vector<std::string> arguments(argv, argv + argc);
    // Implement here
    return 0;
}

#if defined(NOBONUS)
void compareFilesLineByLine(const std::vector<std::string>& lines1,
                            const std::vector<std::string>& lines2)
{
    // Implement here
}          
#else

void compareFilesLineByLine(const std::vector<std::string>& lines1,
                            const std::vector<std::string>& lines2)    
{
    // Implement here
}    
#endif


