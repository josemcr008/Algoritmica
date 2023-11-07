#include "funciones.hpp"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 6) {

        cout<<"Los parametros necesarios son: \n";
        cout<<"1: nMin"<<endl;
        cout<<"2: nMax"<<endl;
        cout<<"3: incremento"<<endl;
        cout<<"4: repeticiones"<<endl;
        cout<<"5: nMediana"<<endl;
        cout<<"6: nElementosMinimo"<<endl;
        
    } else {
        
        srand(time(0));
        int nMin = stoi(argv[1]);
        int nMax = stoi(argv[2]);
        int incremento = stoi(argv[3]);
        int repeticiones = stoi(argv[4]);
        int nMediana = stoi(argv[5]);
        int nElementosMinimo = stoi(argv[6]);


        comparacionVariantesQuicksort(nMin, nMax, incremento, repeticiones, nMediana, nElementosMinimo);
    }


    return 0;
}