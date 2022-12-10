#include "../lib/inputs.h"

#include <stdexcept>
#include <set>
#include <algorithm>

uint32_t getCharacterScore(char c)
{
  uint8_t asciiValue = (uint8_t)c;
  uint8_t retVal = 0;

  // A - Z : ascii values 65-90, mapped to 27-52
  if (asciiValue <= 90)
  {
    retVal = asciiValue - 38;
  }

  // a-z : ascii values 97-122, mapped to 1-26
  if (asciiValue >= 97)
  {
    retVal = asciiValue - 96;
  }

  return retVal;
}

void splitRucksack(std::string &inp, std::string &left, std::string &right)
{
  uint32_t inpSize = inp.size();
  if (inpSize % 2 != 0)
  {
    throw std::invalid_argument("input string has odd number of elements");
  }

  uint32_t halfPoint = inpSize / 2;

  left = inp.substr(0, halfPoint);
  right = inp.substr(halfPoint, halfPoint);
}

std::set<char> stringToSet(std::string string)
{
  std::set<char> out = {};

  for (auto &ch : string)
  {
    out.insert(ch);
  }

  return out;
}

std::set<char> getIntersection(std::set<char> s1, std::set<char> s2)
{
  std::set<char> intersection = {};
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), intersection.begin());

  return intersection;
}

void solve(InputFile &inp)
{

  for (uint32_t i = 0; i < inp.getNumLines(); i++)
  {
    
  }
}

int main()
{
  InputFile inp = {};

  inp.readFile("2/input.txt");

  if (inp.getNumLines() > 0)
  {
    solve(inp);
  }
  else 
  {
    printf("No lines read from input file... does the file exist?\r\n");
  }

  return 0;
}