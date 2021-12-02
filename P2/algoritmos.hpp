#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>



//funciones quicksort
void ordenacionQuickSort();
void tiempoOrdenacionQuickSort(int max, int min, int inc, int rep, vector<double> treales, vector<double> nelementos);
bool quicksort(vector<double> &v, int izq, ind der);

//funciones auxiliares
void rellenarVector(vector<double> &v);
bool estaOrdenado(vector<double> &v);
void ajustenlogn(vector<doubel>&nelementos, vector<double> &treales, vector<double> &aux);
