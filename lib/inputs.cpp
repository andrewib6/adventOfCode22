#include "inputs.h"
#include <fstream>

Line::Line()
{}

Line::Line(std::string &inp)
{
  mLine = inp;
}

Line::~Line()
{}

std::string Line::getString(void)
{
  return mLine;
}

void Line::saveLineString(std::string &line)
{
  mLine = line;
}

InputFile::InputFile()
{
  mLines.resize(0);
}
InputFile::~InputFile()
{}

void InputFile::readFile(std::string fileName)
{
  printf("Reading file at %s\r\n", fileName.c_str());
  std::ifstream file(fileName);
  if (file.is_open())
  {
    std::string line;
    while (std::getline(file, line))
    {
      mLines.push_back(Line(line));
    }
    file.close();
  } else {
  }
}

uint32_t InputFile::getNumLines()
{
  return mLines.size();
}

Line InputFile::getLine(uint32_t lineIndex)
{
  return mLines.at(lineIndex); 
}
