#include "algoritmos.hpp"

using namespace std;

void rellenarVector(vector<double> &v)
{
  int n;
  for(int i=0; i<v.size(); i++)
  {
    n=rand()%10000000;
    v[i]=n;
  }
}

bool estaOrdenado(vector<double> &v)
{
  for(int i=0; i<v.size(); i++)
  {
    if(v[i]>v[i+1])
    {
      return false;
    }
  }
  return true;
}

double sumatorio(vector<double> &n, vector<double> &t, int expN, int expT)
{
  double sumatorio=0;
  for(int i=0; i<n.size();i++)
  {
    sumatorio+=(pow(n[i],expN)*pow(t[i],expT));
  }
  return sumatorio;
}




void ajustenlogn(vector<doubel>&nelementos, vector<double> &treales, vector<double> &aux)
{
  vector<vector <double>> A(2, vector<double>(2));
  vector<vector <double>> B(2, vector<double>(1));
  vector<vector <double>> X(2, vector<double>(1));

  vector<double> opera = nelementos;

  for(int i=0; i<nelementos.size(); i++)
  {
    opera[i]= opera[i]*log10(nelementos[i]);
  }

  A[0][0]=nelementos.size();
  A[0][1]=sumatorio(opera,opera,1,0);
  A[1][0]=sumatorio(opera,opera,1,0);
  A[1][1]=sumatorio(opera,opera,2,0);
  B[0][0]=sumatorio(opera, treales,0,1);
  B[1][0]=sumatorio(opera,treales,1,1);

  resolverSistemaEcuaciones(A,B,2,X);

  a[0]=X[0][0];
  a[1]=X[1][0];

}
