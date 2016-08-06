#ifndef _ODESOLVER_H_
#define _ODESOLVER_H_

#include "Typedefs.h"

class ODEProblem;

class ODESolver {
 protected:
  ODEProblem* _eqdef;
 public:
  ODESolver(ODEProblem* eqdef) { _eqdef = eqdef; }
  virtual ~ODESolver() {};
  virtual void init() =0;
  virtual void advance(vectorr64&, r64&, r64&) =0;
};

#endif
