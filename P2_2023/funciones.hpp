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

/*void ordernacionSeleccion();
void tiemposOrdenacionSelección(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);

void ordenacionSeleccion(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
void ajusteCuadratico(vector <double>&numeroElementos, vector <double> &tiemposReales, vector <double>&a);
double sumatorio(vector <double> &n, vector <double> &t,int expN, int expT);
void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double>&tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a);*/




#endif