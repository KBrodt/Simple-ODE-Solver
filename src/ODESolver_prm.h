#ifndef _ODESOLVER_PRM_H_
#define _ODESOLVER_PRM_H_

#include "Typedefs.h"

class ODEProblem;
class ODESolver;

class ODESolver_prm {
 public:
  string method;
  ODEProblem* problem;
  ODESolver* create();
};

#endif
