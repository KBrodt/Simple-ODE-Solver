# Simple-ODE-Solver
Simple ODE Solver written on C++

This program is ispired by Langtangen's book Computational Partial Differential Equations 2002.

The sources are in src/

To compile just run scripts make_debug or make_release in project/

The binary is in bin/ folder.

Example of usage. Suppose we want to solve a simple ODE:

	y' = -ky in (a, b) with y(0) = y_0

We write a class named, for example, Pb001.h inherits class ODEProblem.h and we describe the method equation() getting right hand side of the equation and the method scan() reading some parameters of the equation. In main() we just create an instance of our new problem Pb001.h and solve it.