#ifndef _FORWARDEULER_H_
#define _FORWARDEULER_H_

#include "ODESolver.h"

class ForwardEuler : public ODESolver {
  vectorr64 _scratch1;
 public:
  ForwardEuler (ODEProblem *eqdef);
  virtual void init();
  virtual void advance(vectorr64&, r64&, r64&);
};

#endif
