#include "ODEProblem.h"
#include "MenuSystem.h"

class Pb001 : public ODEProblem {
 protected:
  r64 _alpha, _a;
 public:
  Pb001() {}
  virtual void equation(vectorr64&, const vectorr64&, r64);
  virtual u32 size() { return 1; }
  virtual void scan();
  virtual void print(std::ostream&);
};

void Pb001::equation(vectorr64& f, const vectorr64& y, r64 t) {
  u32 n = y.size();
  for ( u32 i = 0; i < n; i++ )
    f[i] = -_alpha * (y[i] * y[i] * y[i] * y[i] - _a);
}

void Pb001::scan() {
  // first we need to do everything that ODEProblem::scan does:
  ODEProblem::scan();
  // additional reading here:
  initFromCommandLine("-alpha", _alpha, 1.0);
  initFromCommandLine("-a", _a, 0.0);
  // convenient check for the user
  //std::cout << _alpha << " " << _a << std::endl;
}

void Pb001::print(std::ostream& os) {
  os << "\n\n# Problem y' = -"<< _alpha << "(y^4 - " << _a << ")\n";
  ODEProblem::print(os);
}
