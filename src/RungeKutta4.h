#ifndef _RUNGEKUTTA4_H_
#define _RUNGEKUTTA4_H_

#include "ODESolver.h"

class RungeKutta4 : public ODESolver {
  vectorr64 _scratch1, _scratch2, _scratch3, _scratch4;
 public:
  RungeKutta4 (ODEProblem *eqdef);
  virtual void init();
  virtual void advance(vectorr64&, r64&, r64&);
};

#endif
