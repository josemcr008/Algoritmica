#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "ClaseTiempo.cpp"
#include "funciones.hpp"

using namespace std;


////////////////////////// Metodos Ordenación Seleccion //////////////////////////////////////////


void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int
repeticiones, int nMediana, int nElementosMinimo, vector <double>
&tiemposRealesQS1, vector <double> &tiemposRealesQS2, vector <double>
&numeroElementos)
{
	Clock time, time2;
    int izq = 0;
	float med = 0.0, med2 = 0.0;
	vector<int> v, v2;
	while(nMin < nMax + incremento)
	{
        if(nMin > nMax){
            nMin = nMax;
        }

		for(int n = 0; n < repeticiones; n++)
		{
	
			//funcion que rellena los elementos del vector
			v.clear();
			v.resize(nMin);
			rellenarVector(v);
            v2 = v;
            int der = v.size();

			time.start();
			//funcion que ordena mediante el metodo quicksort
			quickSort_variante1(v, izq, der-1);

            if(estaOrdenado(v)){
                //detenemos el tiempo de ordenacion
                if (time.isStarted())
                    time.stop();


                //tiempo medio de ordenacion del vector
                med= med + time.elapsed();
            }


            time2.start();
            quickSortMedian(v2,  izq,  der,  nElementosMinimo,  nMediana);
            if(estaOrdenado(v2)){
                //detenemos el tiempo de ordenacion
                if (time2.isStarted())
                    time2.stop();


                //tiempo medio de ordenacion del vector
                med2= med2 + time2.elapsed();
            } else {
                cout<<"No se ordena "<<endl;
            }



           
		}

		med /= repeticiones;
        med2 /= repeticiones;

        cout<<"Tamanio" <<" = "  << nMin << endl;
        cout<<"Tmedio metodo1" << " = " << med<<" microsegundos" << endl;
        cout<<"Tmedio metodo2" << " = " << med2<<" microsegundos" << endl;


		tiemposRealesQS1.push_back(med);
        tiemposRealesQS2.push_back(med2);
		numeroElementos.push_back(nMin);

		nMin += incremento;
        
	}

 
}

void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo){

    vector <double> tiemposRealesQS1, tiemposRealesQS2, numeroElementos;

    if (nMin > nMax){
        cout<<"nMax no puede ser menor que nMin, se le dan la vuelta"<<endl;
        int a = nMin;
        nMin = nMax;
        nMax = a;
    }
    
    tiemposOrdenacionVariantesQuicksort(nMin, nMax, incremento,  repeticiones,  nMediana, nElementosMinimo, tiemposRealesQS1, tiemposRealesQS2, numeroElementos);

    ofstream fichero("tiempos.txt");

    for(size_t i=0; i < tiemposRealesQS1.size(); i++){
        fichero << numeroElementos[i] << " " << tiemposRealesQS1[i]<< " "<< tiemposRealesQS2[i] << endl;;
    }
    fichero.close();

    double media1 = calcularMedia(tiemposRealesQS1);
    double media2 = calcularMedia(tiemposRealesQS2);

    cout << "Cociente = "<< media2/media1<<endl;
    
}

double calcularMedia(const vector<double> &tiemposRealesQS1) {
    double suma = 0.0;
    for (size_t i = 0; i < tiemposRealesQS1.size(); i++) {
        suma += tiemposRealesQS1[i];
    }
    double media = suma / tiemposRealesQS1.size();
    return media;
}

//Función para rellenar el vector que se le pasa como parámetro con valores aleatorios
void rellenarVector(vector<int> &v){

    int valor;
    for(size_t i=0; i<v.size(); i++){                             

        valor=rand()%10000000;                                      
        v[i]=valor;                                             
    }
}

bool estaOrdenado(const vector <int> &v){

    for (size_t i = 0; i < v.size()-1; i++){    

        if(v[i]>v[i+1]){                                           

            return false;        
        }
    }
    return true;                                                   
}


//Funcion que realiza la ordenacion quicksort
void  quickSort_variante1(vector<int> &v, int izq, int der)
    {
    int i = izq;
    int j = der;
    int piv = v[(izq+der)/2];

        while (i <= j)
        {
            while (v[i] < piv)
            {
                i++;
            }
        
            while (v[j] > piv)
            {
                j--;
            }

            if(i <= j)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;

                i++;
                j--;
            }
        }

        if(izq < j)
        {
            quickSort_variante1(v, izq, j);
        }
        if(i < der)
        {
            quickSort_variante1(v, i, der);   
        }
    }


int mediana(vector<int> &arr, int left, int right, int nMediana) {
    vector<int> temp;
    for (int i = 0; i < nMediana; i++) {
        int idx = left + rand() % (right - left + 1);
        temp.push_back(arr[idx]);
    }
    int k = nMediana / 2 + 1;
    return seleccion(temp, 0, nMediana - 1, k);
}

int seleccion(vector<int> &arr, int left, int right, int k) {
    for (int i = left; i <= right; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= right; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return arr[k - 1];
}

void quickSortMedian(vector<int> &v, int izq, int der, int sizeMin, int nMediana) {

    int piv, i = izq, j = der;
    if((der - izq) < sizeMin){
        piv = v[(izq+der)/2];
    }

    else{
        piv = mediana(v, i, j, nMediana);
    }

        while (i <= j)
        {
            while (v[i] < piv)
            {
                i++;
            }
        
            while (v[j] > piv)
            {
                j--;
            }

            if(i <= j)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;

                i++;
                j--;
            }
        }

        if(izq < j)
        {
            quickSortMedian(v, izq, j, sizeMin, nMediana);
        }
        if(i < der)
        {
            quickSortMedian(v, i, der, sizeMin, nMediana);   
        }
}