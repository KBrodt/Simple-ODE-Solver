#include "ODESolver_prm.h"
#include "ODESolver.h"
#include "ForwardEuler.h"
#include "RungeKutta4.h"

ODESolver* ODESolver_prm::create() {
  ODESolver* ptr = NULL;
  if ( method == "ForwardEuler" ) {
    ptr = new ForwardEuler(problem);
  } else if ( method == "RungeKutta4" )
    ptr = new RungeKutta4(problem);
  else {
    std::cout << "\nODESolver_prm::create, Method " + method + " is not available, please try again\n";
  }
  return ptr;
}
