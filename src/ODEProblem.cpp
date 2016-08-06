#include "ODEProblem.h"
#include "ODESolver.h"
#include "ODESolver_prm.h"
#include "MenuSystem.h"

void ODEProblem::timeLoop() {
  r64 t = 0.0;
  _t.push_back(t);
  vectorr64 y = _y.back();
  while ( t <= _T) {
    _solver->advance(y, t, _dt);
    _t.push_back(t);
    _y.push_back(y);
  }
}

void ODEProblem::scan() {
  const u32 n = size();  // call size in actual subclass
  vectorr64 y0(n);
  string ic;
  char ic0[80];
  strcpy(ic0, "");
  for ( u32 i = 0; i < n; i++ )
   strcat(ic0, "1 ");
  initFromCommandLine("-ic", ic, ic0);
  
  istringstream iss(ic);
  u32 i = 0;
  while (iss && i != n) {
    string subs;
    iss >> subs;
    std::string::size_type sz;   // alias of syze_t
    y0[i++] = std::stod(subs, &sz);
  }
  
  _y.push_back(y0);
  initFromCommandLine("-dt", _dt, 0.1);
  initFromCommandLine("-T", _T, 30.0);

  ODESolver_prm solver_prm;
  initFromCommandLine("-m", solver_prm.method, "RungeKutta4");
  solver_prm.problem = this;
  _solver = solver_prm.create();
  _solver->init();
  // more reading in user's subclass
}

void ODEProblem::print(std::ostream& os) {
  os << "\n# Integrating ODE system from t=0 to t=" << _T
	    << ", with initial time step dt=" << _dt << "\n# and " << _y[0].size() << " initials conditions: ";
  for ( u32 i = 0; i < _y[0].size(); i++ )
    os << _y[0][i] << " ";
  os << "\n\n";
  for ( u32 n = 0; n < _y.size(); n++ ) {
    os << _t[n];
    for ( u32 i = 0; i < _y[n].size(); i++ ) {
      os << " " << _y[n][i];
    }
    os << "\n";
  }
  // more printing in user's subclass
}

ODEProblem::~ODEProblem () {
  // solver is created in scan, by createODESolver:
  delete _solver;  
  // following the Diffpack standard, we would have used a
  // Handle(ODESolver) solver and thereby avoided the explict
  // (and dangerous) call to delete (note that two-handles
  // are illegal, so in class ODESolver we must use a pure
  // ODEProblem* pointer)
}
