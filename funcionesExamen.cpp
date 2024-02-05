//////////////////// P1 - P2


double sumatorio(vector <double> &n, vector <double> &t,int expN, int expT){
    double resultado = 0.0;

    for (size_t i = 0; i < n.size(); ++i) {
        double termino = pow(n[i], expN) * pow(t[i], expT);
        resultado += termino;
    }

    return resultado;
}


//Bien
double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double>&tiemposEstimados){

    double varianzaTiemposReales = 0.0;
    double varianzaTiemposEstimados = 0.0;
    double mediaTiemposReales = 0.0;

    // Calcular la media de los tiempos reales
    for (size_t i = 0; i < tiemposReales.size(); ++i) {
        mediaTiemposReales += tiemposReales[i];
    }
    mediaTiemposReales /= tiemposReales.size();

    // Calcular las varianzas
    for (size_t i = 0; i < tiemposReales.size(); ++i) {
        double diferenciaReal = tiemposReales[i] - mediaTiemposReales;
        varianzaTiemposReales += diferenciaReal * diferenciaReal;

        double diferenciaEstimada = tiemposEstimados[i] - mediaTiemposReales;
        varianzaTiemposEstimados += diferenciaEstimada * diferenciaEstimada;
    }

    // Calcular el coeficiente de determinación
    double coeficienteDeterminacion = varianzaTiemposEstimados / varianzaTiemposReales;

    return coeficienteDeterminacion;
}


//return a[0] + a[1]*pow(2,n);
//Bien
double calcularTiempoEstimadoPolinomico(const double &n, vector <double> &a){
    double estimado = a[0] + a[1]*n + a[2]*pow(n,2);
    return estimado;

}

//BIEN
void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados){

    // Calcular los tiempos estimados utilizando la función de ajuste polinómico
    for (size_t i = 0; i < numeroElementos.size(); i++) {
        //double n = numeroElementos[i];
        //double estimado = a[0] + a[1] * n + a[2] * n * n;
        tiemposEstimados.push_back(calcularTiempoEstimadoPolinomico(numeroElementos[i], a));
    }
}


//Bien
void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos){
    Clock tiempo;
    vector<int> v;

    while(nMin < (nMax + incremento)){
        float media = 0, suma = 0;

        if(nMin > nMax)
            nMin = nMax;

        for(int i=0; i<repeticiones; i++){
            v.clear();
            v.resize(nMin);
            rellenarVector(v);
            tiempo.restart();
            ordenacionSeleccion(v);
            if(!estaOrdenado(v)){
                cout << "El vector no se ha ordenado correctamente"<<endl;
            }
            else{
                if(tiempo.isStarted()){
                    tiempo.stop();
                }
                suma += tiempo.elapsed();
            }
        }
        media = suma/repeticiones;
        tiemposReales.push_back(media);
        numeroElementos.push_back(nMin);
        nMin += incremento;
    }

}


//Repasar
void ajusteExponencial(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &a){

    vector <vector <double> > A(2, vector<double>(2));
    vector <vector <double> > B(2, vector<double>(1));
    vector <vector <double> > X(2, vector<double>(1));

    vector <double> aux = numeroElementos;

    for (size_t i=0; i<numeroElementos.size(); i++){

      aux[i]= pow(2,numeroElementos[i]);
    }

    A[0][0] = numeroElementos.size();
    A[0][1] = sumatorio(aux,aux,1,0);

    A[1][0] = sumatorio(aux,aux,1,0);
    A[1][1] = sumatorio(aux,aux,2,0);

    B[0][0] = sumatorio(aux,tiemposReales,0,1);
    B[1][0] = sumatorio(aux,tiemposReales,1,1);

    resolverSistemaEcuaciones(A,B,2,X);

    a[0] = X[0][0];
    a[1] = X[1][0];

}
////////////////////// P3

//Bien
void cargarSistemaMonetario(std::vector<Moneda> &sistemaMonetario, const char *nombreFichero) {
    ifstream file(nombreFichero);
    if (file.is_open()) {
        int valor;
        while (file >> valor) {
            Moneda moneda(valor);
            sistemaMonetario.push_back(moneda);
        }
        file.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}


//Bien
void cambio(int cantidad, vector<Moneda> sistemaMonetario, vector<int> &solucion) { 
    solucion.clear();  // Limpiar el vector de solución

    /**
    for (size_t i = 0; i < sistemaMonetario.size(); ++i) {
        const Moneda& moneda = sistemaMonetario[i];
        int numMonedas = cantidad / moneda.getValor();
        solucion.push_back(numMonedas);
        cantidad -= numMonedas * moneda.getValor();
    }
    */

    for (const Moneda& moneda : sistemaMonetario) {
        int numMonedas = cantidad / moneda.getValor();
        solucion.push_back(numMonedas);
        cantidad -= numMonedas * moneda.getValor();
    }

    if (cantidad != 0) {
        std::cout << "No encuentro solucion." << std::endl;
        solucion.clear();  // Limpiar el vector de solución si no se encontró una solución válida
    }
}


//Bien
void cargarMateriales(std::vector<Material> &materiales, const char *nombreFichero) {
    std::ifstream archivo(nombreFichero);
    int etiqueta;
    float volumen, precio;

    while (archivo >> etiqueta >> volumen >> precio) {
        materiales.emplace_back(etiqueta, volumen, precio);
    }

    archivo.close();
}

//Repasar
void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado> &solucion) {
    int n = materiales.size();
    float resto = volumenMochila;
    bool materialDisponible = false;

    // Marcar materiales como no usados
    for (int i = 0; i < n; ++i) {
        solucion.push_back(MaterialUsado(materiales[i], 0));
    }

    do {
        float valorMaximo = 0;
        int materialMaximo = -1;
        

        // Selecciona el material de máximo valor
        for (int i = 0; i < n; ++i) {
            if (solucion[i].getVolumenUsado() == 0) {
                materialDisponible = true;

                if (materiales[i].getPrecio() > valorMaximo) {
                    valorMaximo = materiales[i].getPrecio();
                    materialMaximo = i;
                }
            }
        }

        // Comprueba si el material de máximo valor cabe en la mochila
        if (materialDisponible) {
            if (resto >= materiales[materialMaximo].getVolumen()) {
                solucion[materialMaximo].setVolumenUsado(materiales[materialMaximo].getVolumen());
                resto -= materiales[materialMaximo].getVolumen();
            } else {
                solucion[materialMaximo].setVolumenUsado(resto);
                resto = 0;
            }
        } else {
            break;
        }
    } while (resto > 0 || materialDisponible == false);
}


///////////////////// P4

//Bien
void cambio2(int cantidad, const vector<Moneda>& sistemaMonetario, vector<vector<int>>& matrizEstados) {
    int numMonedas = sistemaMonetario.size();

    for (int i = 0; i < numMonedas; ++i) {
        for (int j = 0; j <= cantidad; ++j) {
            if (i == 0) {
                // Rellenamos fila 0
                if (j >= sistemaMonetario[i].getValor()) {
                    matrizEstados[i][j] = 1 + matrizEstados[i][j - sistemaMonetario[i].getValor()];
                } else {
                    matrizEstados[i][j] = 0;
                }
            } else {
                // Rellenamos el resto de filas
                if (j < sistemaMonetario[i].getValor()) {
                    matrizEstados[i][j] = matrizEstados[i - 1][j];
                } else {
                    matrizEstados[i][j] = min(matrizEstados[i - 1][j], 1 + matrizEstados[i][j - sistemaMonetario[i].getValor()]);
                }
            }
        }
    }
}



//Aprender
void obtenerSolucion(const vector<vector<int>>& matrizEstados, const vector<Moneda>& sistemaMonetario, vector<int>& solucion) {
    int numMonedas = sistemaMonetario.size();
    int cantidad = matrizEstados[0].size() - 1;

    // Inicializa la solución con ceros
    solucion.resize(numMonedas, 0);


    int i = numMonedas - 1;
    while (i >= 0 && cantidad > 0) {
        // Verifica si la cantidad actual se puede formar con la moneda actual
        while (i > 0 && cantidad >= sistemaMonetario[i].getValor() && matrizEstados[i][cantidad] == matrizEstados[i - 1][cantidad]) {
            // Mueve a la moneda anterior si la cantidad no cambia
            --i;
        }

        if (cantidad >= sistemaMonetario[i].getValor()) {
            // Actualiza la solución
            solucion[i] += cantidad / sistemaMonetario[i].getValor();
            cantidad %= sistemaMonetario[i].getValor();
        }

        --i;
    }

}
//Aprender
void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados) {
    int numMateriales = materiales.size();

    // Rellenamos columna 0
    for (int i = 0; i < numMateriales; ++i) {
        matrizEstados[i][0] = 0;
    }

    // Rellenamos fila 0
    for (int j = 0; j <= volumenMochila; ++j) {
        //matrizEstados[0][j] = (j < materiales[0].getVolumen()) ? 0 : materiales[0].getPrecio() * materiales[0].getVolumen();
        if (j < materiales[0].getVolumen()) {
        matrizEstados[0][j] = 0;
        } else {
        matrizEstados[0][j] = materiales[0].getPrecio() * materiales[0].getVolumen();
        }    
    }

    // Rellenamos resto de filas
    for (int i = 1; i < numMateriales; ++i) {
        for (int j = 1; j <= volumenMochila; ++j) {
            if (j < materiales[i].getVolumen()) {
                matrizEstados[i][j] = matrizEstados[i - 1][j];
            } else {
                matrizEstados[i][j] = max(matrizEstados[i - 1][j], materiales[i].getPrecio() * materiales[i].getVolumen() + matrizEstados[i - 1][j - materiales[i].getVolumen()]);
            }
        }
    }
}

for(int i=0; i<materiales.size(); i++){
    matrizEstados[i][0] = 0;
}

for(int j=0; j<volumenMochila; j++){
    if(j < materiales[0].getVolumen){
        matrizEstados[0][j] = 0;
    } else {
        matrizEstados[0][j] = materiales[0].getPrecio * materiales[0].getVolumen;
    }
}

for(int i = 1; i<materiales.size(); i++){
    for(int j=1; j<volumenMochila; j++){
        if(j <  materiales[0].getVolumen){
            matrizEstados[0][1] = matrizEstados[i-1][j];
        } else {
            matrizEstados[0][1] = max(matrizEstados[i-1][j], materiales[i].getPrecio * materiales[i]*getVolumen() + matrizEstados[i][j -materiales[i].getVolumen])
        }
    }
}

//Aprender
void obtenerSolucion_mochila(vector<vector<double>> &matrizEstados, vector<Material> &materiales, vector<MaterialUsado> &solucion) {
    int numMateriales = materiales.size();
    int volumenMochila = matrizEstados[0].size() - 1;

    solucion.clear();

    int i = numMateriales - 1;
    while (i >= 0 && volumenMochila > 0) {
        if (i == 0 || matrizEstados[i][volumenMochila] != matrizEstados[i - 1][volumenMochila]) {
            float volumenUsado = materiales[i].getVolumen();
            solucion.push_back(MaterialUsado(materiales[i], volumenUsado));
            volumenMochila -= volumenUsado;

            cout << "Añadido Material " << i << ": Volumen usado = " << volumenUsado << ", Volumen restante = " << volumenMochila << endl;
        }
        --i;
    }
}

///////////////////// P5 

//Repasar
bool esSeguro(int k, int x, vector<int>& tablero) { //Lugar
    for (int i = 0; i < k; ++i) {
        if (tablero[i] == x || abs(tablero[i] - x) == abs(i - k)) {
            return false;
        }
    }
    return true;
}

if (tablero[i] = x || abs(tabl))


//Aprender
bool nReinasLasVegas(int n, vector<int>& solucion) {
    solucion.resize(n, 0);
    int intentos = 0;

    srand(static_cast<unsigned int>(time(0)));

    for (int k = 0; k < n; ++k) {
        int contador = -1;
        vector<int> ok(n, 0);

        for (int j = 0; j < n; ++j) {
            solucion[k] = j;
            if (esSeguro(k, solucion[k], solucion)) {
                contador++;
                ok[contador] = j;
            }
        }

        if (contador == -1) {
            break;
        }

        int columna = ok[rand() % (contador + 1)];
        solucion[k] = columna;
    }

    if (esSeguro(n - 1, solucion[n - 1], solucion)) {
        return true;
    }

    return false;
}
