#include "Pb001.h"
#include "Oscillator.h"

int main(int argc, char* argv[]) {
  init(argc, argv);
  Oscillator problem;
  problem.scan();
  problem.timeLoop();
  problem.print(std::cout);
  return 0;
}
