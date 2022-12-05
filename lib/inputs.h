#ifndef AOC_22_INPUTS
#define AOC_22_INPUTS

#include <stdint.h>
#include <stdbool.h>
#include <string>
#include <vector>

enum { STRING_COMPARE_EQUAL = 0 };

class Line
{
  public:
    Line();
    Line(std::string &inp);
    ~Line();

    std::string getString();
    void saveLineString(std::string &line);

  private:
    std::string mLine;
};

class InputFile
{
  public:
    InputFile();
    ~InputFile();

    void readFile(std::string fileName);
    uint32_t getNumLines();
    Line getLine(uint32_t lineIndex);

  private:
    std::vector<Line> mLines;
};


#endif