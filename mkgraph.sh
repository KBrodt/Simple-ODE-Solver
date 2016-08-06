#!/usr/bin/gnuplot

f(x) = 1.0/(1.0+3.0*x)**(1.0/3.0)
datafile1 = "fe.dat"
datafile2 = "rk4.dat"
datafile3 = "res.dat"

set terminal png size 800,480 enhanced font 'Arial, 16'
set output 'odeos.png'

#set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
#set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2

set border linewidth 1
set key top left
set grid
set mytics 0
set format y "%.6f"
#set xlabel "Number of elements" font "Arial, 16"
#set format x "%.3f"
#set ylabel "Execution time (sec)" font "Arial, 16"
#set xtics 100000 font "Arial, 12"
#set ytics font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

#plot f(x) t "Exact" w l ls 1,\
#     datafile1 u 1:2 t "Forward Euler" w lp ls 2,\
#     datafile2 u 1:2 t "Runge Kutta 4" w lp ls 3
plot datafile3 u 1:2 t "$y_1$" w lp ls 2,\
     datafile3 u 1:3 t "$y_2$" w lp ls 3
