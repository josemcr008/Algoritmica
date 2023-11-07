#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;

void ordernacionSeleccion();
void tiemposOrdenacionSelección(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);
void rellenarVector(vector <int> &v);
void ordenacionSeleccion(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
void ajusteCuadratico(vector <double>&numeroElementos, vector <double> &tiemposReales, vector <double>&a);
double sumatorio(vector <double> &n, vector <double> &t,int expN, int expT);
void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double>&tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a);



void matrizCuadrado();
void tiemposProductoMatrices(int nMin, int nMax, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);
void rellenaMatriz(vector < vector <double> > &m, int n, int modo);
void productoMatrices(vector < vector <double> > m1,vector < vector <double> > m2,vector < vector <double> > mResult);
void ajusteCubico(vector <double> &n, vector <double> &tiemposReales, vector <double> &a);

void calcularTiemposEstimadosPolinomico(const vector <double> &n, const vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados);



void fibonacciRecursivo();
void tiemposFibonacciRecursivo(int nMin, int nMax, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);
int fibonacciRecursivo(int n);
void ajusteExponencial(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &a);
void calcularTiemposEstimadosExponencial(const vector <double> &n, const vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularTiempoEstimadoExponencial(const double &n, vector <double> &a);



#endif