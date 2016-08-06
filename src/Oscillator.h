#include "ODEProblem.h"
#include "MenuSystem.h"

class Oscillator : public ODEProblem {
 protected:
  r64 _c1, _c2, _c3, _c4, _omega;
 public:
  Oscillator() {}
  virtual void equation(vectorr64&, const vectorr64&, r64);
  virtual u32 size() { return 2; }
  virtual void scan();
  virtual void print(std::ostream&);
};

void Oscillator::equation(vectorr64& f, const vectorr64& y, r64 t) {
  f[0] = y[1];
  f[1] = -_c1 * (y[1] + _c2 * y[1] * abs(y[1])) - _c3 * (y[0] + _c4 * pow(y[0], 3.0)) + sin(_omega * t);
}

void Oscillator::scan() {
  // first we need to do everything that ODEProblem::scan does:
  ODEProblem::scan();
  // additional reading here:
  initFromCommandLine("-c1", _c1, 0.0);
  initFromCommandLine("-c2", _c2, 0.0);
  initFromCommandLine("-c3", _c3, 1.0);
  initFromCommandLine("-c4", _c4, 0.0);
  initFromCommandLine("-omega", _omega, 0.5);
  // convenient check for the user
  //std::cout << _c1 << _c2 << _c3 << _c4 << _omega;
}

void Oscillator::print(std::ostream& os) {
  os << "\n\n# Problem y_1' = y_2\n";
  os << "#         y_2' = " << -_c1 << "(y_2 + " << _c2 << "y_2|y_2|) " << -_c3 << "(y_1 + "<< _c4 << "y_1^3) + sin(" << _omega << "*t)\n";
  ODEProblem::print(os);
}
