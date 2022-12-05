#include "../lib/inputs.h"

#include <array>

enum { NUM_LARGEST = 3 };

uint32_t getLowestIndexInArray(std::array<uint32_t, NUM_LARGEST> arr)
{
  uint32_t lowestIndex = 0;
  for (uint32_t i = 1; i < arr.size(); i++)
  {
    if (arr.at(i) < arr.at(lowestIndex))
    {
      lowestIndex = i;
    }
  }
  return lowestIndex;
}

uint32_t getLowestInArray(std::array<uint32_t, NUM_LARGEST> arr)
{
  uint32_t lowestIndex = getLowestIndexInArray(arr);
  return arr.at(lowestIndex);
}

void replaceLowestInArray(std::array<uint32_t, NUM_LARGEST> &arr, uint32_t incoming)
{
  arr.at(getLowestIndexInArray(arr)) = incoming;
}

void solve(InputFile &inp)
{
  std::array<uint32_t, NUM_LARGEST> currentMaxes = {};
  uint32_t runningTotal = 0;

  for (uint32_t i = 0; i < inp.getNumLines(); i++)
  {
    try
    {
      uint32_t newVal = std::stol(inp.getLine(i).getString());
      runningTotal += newVal;
    }
    catch (...)
    {
      if (runningTotal > getLowestInArray(currentMaxes))
      {
        replaceLowestInArray(currentMaxes, runningTotal);
      }
      runningTotal = 0;
    }
  }

  printf("Highest counts =\r\n");
  for (uint32_t i = 0; i < NUM_LARGEST; i++)
  {
    printf("%d, ", currentMaxes.at(i));
  }
}

int main()
{
  InputFile inp = {};

  inp.readFile("1/input.txt");

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