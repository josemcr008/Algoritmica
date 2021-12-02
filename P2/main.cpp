#include <iostream>
#include "algoritmos.hpp"

using namespace std;



int main()
{

  int opcion=0;

  cout<<"--MENU--"<<endl;
  cout<<"1. Ordenación quicksort."<<endl;
  cout<<"2. Ordenación por fusión."<<endl;
  cout<<"3.Salir"<<endl;

  while(opcion!=3)
  {
    cout<<">> ";
    cin>>opcion;

    switch (opcion) {
      case 1:
      {
        //ordenacionQuickSort();
      }
      case 2:
      {
        //ordenacionFusion();
      }
      default:
      {
        break;
      }
    }
  }


/*


  int max, min, inc, rep;
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

  cout<<"-- ORDENACIÓN QUICKSORT -- \n";
  void ordenacionQuickSort();

*/
}
