#include "../lib/inputs.h"

void solve(InputFile &inp)
{
  uint32_t currentMax = 0;
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
      if (runningTotal > currentMax)
      {
        currentMax = runningTotal;
      }
      runningTotal = 0;
    }
  }

  printf("Highest count = %d\r\n", currentMax);
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