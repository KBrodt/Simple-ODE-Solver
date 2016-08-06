#ifndef _RUNGEKUTTA4ADAPT_H_
#define _RUNGEKUTTA4ADAPT_H_

#include "ODESolver.h"

class RungeKutta4Adapt : public ODESolver {
  vectorr64 _scratch1, _scratch2, _scratch3, _scratch4;
  r64 _tol;
  r64 _ec;
 public:
  RungeKutta4Adapt(ODEProblem *eqdef);
  virtual void init();
  virtual void advance(vectorr64&, r64&, r64&);
};

#endif
