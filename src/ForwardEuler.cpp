#include "ODEProblem.h"
#include "ForwardEuler.h"

ForwardEuler::ForwardEuler(ODEProblem* eqdef) : ODESolver(eqdef) {}

void ForwardEuler::init() {
  // allocate internal data structure:
  _scratch1.resize(_eqdef->size());
}

void ForwardEuler::advance(vectorr64& y, r64& t, r64& dt) {
  _eqdef->equation(_scratch1, y, t);
  const i32 n = y.size();
  for ( u32 i = 0; i < n; i++ ) {
    y[i] += dt * _scratch1[i];
  }
  t += dt;
}
