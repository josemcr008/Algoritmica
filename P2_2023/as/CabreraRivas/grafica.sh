#!/bin/bash

cat << _end_|gnuplot
set terminal png
set output "comparacion.png"
set key right bottom
set xlabel "nElementos
set ylabel "Tiempo (ms)"
plot 'tiempos_5_5000.txt' using 1:2 t "algoritmo1" w l, 'tiempos_5_5000.txt' using 1:3 t 'algoritmo2' w p

_end_
