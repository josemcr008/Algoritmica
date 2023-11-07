#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;

void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo, vector <double> &tiemposRealesQS1, vector <double> &tiemposRealesQS2, vector <double> &numeroElementos);
void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo);
void rellenarVector(vector <int> &v);
void  quickSort_variante1(vector<int> &v, int izq, int der);
void quickSortMedian(vector<int> &arr, int left, int right, int sizeMin, int nMediana);
int mediana(vector<int> &arr, int left, int right, int nMediana);
int seleccion(vector<int> &arr, int left, int right, int k);
bool estaOrdenado(const vector <int> &v);
double calcularMedia(const vector<double> &tiemposRealesQS1);

#endif