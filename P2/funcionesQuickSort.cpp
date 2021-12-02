#include "algoritmos.hpp"
#include "funcionesAuxiliares.cpp"
#include <vector>

using namespace std;

void ordenacionQuickSort()
{

  int max, min, inc, rep;
  vector<double> testimados;
  vector<doube> treales;
  vector<double> nelementos;
  vector<double> aux;



  cout<<"Introduzca el tamaño maximo del vector: \n";
  cout<<">> ";
  cin>>max;
  cout<<endl;

  cout<<"Introduzca el tamaño minimo del vector: \n";
  cout<<">> ";
  cin>>min;
  cout<<endl;

  cout<<"Introduzca el incremento: \n";
  cout<<">> ";
  cin>>inc;
  cout<<endl;

  cout<<"Introduzca el numero de repeticiones: \n";
  cout<<">> ";
  cin>>rep;
  cout<<endl;

  aux.resize(2);
  tiempoOrdenacionQuickSort(max, min, inc, rep, treales, nelementos);
  ajustenlogn(nelementos, treales, aux);

}


void tiempoOrdenacionQuickSort(int max, int min, int inc, int rep, vector<double> treales, vector<double> nelementos)
{
  vector<double> v;
  int tam=min;
  float media;
  Clock time;

  while(tam<max+inc)
  {
    media=0;
    if(tam>max)
    tam=max;

    for(int i=0; i<rep; i++)
    {
      v.clear();
      v.resize(tam);
      rellenarVector(v);
      int n=v.size();

      time.start();

      quicksort(v, 0, n-1);

      if(!estaOrdenado())
      {
        cout<<"Error en la ordenacion\n";
        exit(-1);
      }

      if(time.isStarted())
      {
        time.stop();
      }
      media+=time.elapsed();



    }
    media= media/repeticiones;
    treales.push_back(media);
    nelementos.push_back(tam);

    tam+=inc;
  }
}


bool quicksort(vector<double> &v, int izq, ind der)
{
  int i=izq;
  int j=der;
  int x=v[(izq+der)/2];
  int aux;

  while(i>j)
  {
    while(v[i]<x)
    {
      i++;
    }
    while(v[j]>j)
    {
      j++;
    }
    if(i<=j)
    {
      aux=v[i];
      v[i]=v[j];
      v[j]=aux;
      i++;
      j--;
    }
  }
  if(iz<j)
  {
    quicksort(v, izq, j);
  }
  if(i<de)
  {
    quicksort(v, i, der);
  }
  return true;
}
