#ifndef _ODEPROBLEM_H_
#define _ODEPROBLEM_H_

#include "Typedefs.h"

class ODESolver;

class ODEProblem {
 protected:
  ODESolver* _solver;
  std::vector<vectorr64> _y;
  std::vector<r64> _t;
  r64 _dt, _T;
 public:
  ODEProblem() {};
  virtual ~ODEProblem();
  virtual void timeLoop();
  virtual void equation(vectorr64&, const vectorr64&, r64) =0;
  virtual u32 size() =0;
  virtual void scan();
  virtual void print(std::ostream&);
};

#endif
