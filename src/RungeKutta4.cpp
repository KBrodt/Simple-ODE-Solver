#include "ODEProblem.h"
#include "RungeKutta4.h"

RungeKutta4::RungeKutta4(ODEProblem* eqdef) : ODESolver (eqdef) {}

void RungeKutta4::init() {
  _scratch1.resize(_eqdef->size());
  _scratch2.resize(_eqdef->size());
  _scratch3.resize(_eqdef->size());
  _scratch4.resize(_eqdef->size());
}

void RungeKutta4::advance(vectorr64& v, r64& t, r64& dt) {
  u32 n = v.size()  ;
  r64 dt2 = dt * 0.5;
  r64 dt3 = dt / 3.0;
  r64 dt6 = dt3 * 0.5;
  _eqdef->equation(_scratch1, v, t);

  vectorr64 tmp1(n);
  for ( u32 i = 0; i < n; i++ )
    tmp1[i] = v[i] + dt2 * _scratch1[i];
  _eqdef->equation(_scratch2, tmp1, t + dt2);

  vectorr64 tmp2(n);
  for ( u32 i = 0; i < n; i++ )
    tmp2[i] = v[i] + dt2 * _scratch2[i];
  _eqdef->equation(_scratch3, tmp2, t + dt2);

  vectorr64 k4(n);
  for ( u32 i = 0; i < n; i++ )
    k4[i] = v[i] + dt * _scratch3[i];
  _eqdef->equation(_scratch4, k4, t + dt);

  for ( u32 i = 0; i < n; i++ )
    v[i] +=  dt6 * (_scratch1[i] + _scratch4[i]) + dt3 * (_scratch2[i] + _scratch3[i]);
  t += dt;
}
