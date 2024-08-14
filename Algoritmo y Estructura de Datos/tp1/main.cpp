#include <iostream>
using namespace std;

struct Familia {
    int idFamilia;
    char tipoVivienda;
    int cantIntegrantes;
};

struct Integrante {
    int dni;
    int edad;
    char sexo;
    char nivelEstudios;
    char estadoNivelEstudios;
};

void MostrarMenu(Familia familias[], Integrante integrantes[], int& cantFamiliasCargadas);
void CargarProcesarEncuesta(Familia familias[], Integrante integrantes[], int& cantFamiliasCargadas);
void CargarDatosIntegrantes(Integrante integrantes[], int cantIntegrantes, int& cantIntegrantesInsertados);
void MostrarResultados(Familia familias[], Integrante integrantes[], int cantFamiliasCargadas);

int main() {
    int cantFamiliasCargadas = 0;
    Familia familias[100];
    Integrante integrantes[100];

    MostrarMenu(familias, integrantes, cantFamiliasCargadas);

    return 0;
}

void MostrarMenu(Familia familias[], Integrante integrantes[], int& cantFamiliasCargadas) {
    int opcion;

    cout << "1. Cargar y procesar encuesta" << endl;
    cout << "2. Mostrar resultados" << endl;
    cout << "3. SALIR" << endl;
    cin >> opcion;

    while(opcion < 1 || opcion > 3) {
        cout << "Ingrese una opcion valida" << endl;
        cin >> opcion;
    }

    switch (opcion) {
        case 1:
            CargarProcesarEncuesta(familias, integrantes, cantFamiliasCargadas);
            break;
        case 2:
            MostrarResultados(familias, integrantes, cantFamiliasCargadas);
            break;
        case 3:
            cout << "Saliendo..." << endl;
            exit(0);
        default:
            break;
    }
}

void CargarProcesarEncuesta(Familia familias[], Integrante integrantes[], int& cantFamiliasCargadas) {

    Familia familia;
    int cantIntegrantesInsertados = 0;

    do{
        int idFamilia;
        cout << "Ingrese el identificador de la familia " << cantFamiliasCargadas + 1 << endl;
        cin >> idFamilia;

        if(idFamilia == 0) {
            break;
        }

        familia.idFamilia = idFamilia;

        cout << "Ingrese tipo de vivienda: C: casa | D: departamento" << endl;
        cin >> familia.tipoVivienda;
        cout << "Ingrese cantidad de integrantes" << endl;
        cin >> familia.cantIntegrantes;

        familias[cantFamiliasCargadas] = familia;

        CargarDatosIntegrantes(integrantes, familia.cantIntegrantes, cantIntegrantesInsertados);

        cantFamiliasCargadas++;
    }while(familia.idFamilia != 0);

    MostrarMenu(familias, integrantes, cantFamiliasCargadas);
}

void CargarDatosIntegrantes(Integrante integrantes[], int cantIntegrantes, int& cantIntegrantesInsertados ) {
    int posicionInicial = cantIntegrantesInsertados;
    int limitePosicion = cantIntegrantesInsertados + cantIntegrantes;
    for(int i = posicionInicial; i < limitePosicion; i++) {
        Integrante integrante;

        cout << "-- Integrante " << i + 1 << endl;
        cout << "Ingresar DNI" << endl;
        cin >> integrante.dni;
        cout << "Ingresar Edad" << endl;
        cin >> integrante.edad;
        cout << "Ingresar Sexo (M | F)" << endl;
        cin >> integrante.sexo;
        cout << "Ingresar nivel de estudios (N: no posee | P: primario | S: secundario | T: terciario | U: universitario)" << endl;
        cin >> integrante.nivelEstudios;
        cout << "Ingresar estado del nivel anterior (I: Incompleto | C: Completo)" << endl;
        cin >> integrante.estadoNivelEstudios;

        cantIntegrantesInsertados++;
        integrantes[i] = integrante;
    }
}

void MostrarResultados(Familia familias[], Integrante integrantes[], int cantFamiliasCargadas) {
    int cantIntegrantes = 0;
    int cantIntegrantesPrimario = 0;
    float cantAnalfabetismo=0;
    float porcentajeAnalfabetismo = 0;
    int idFamiliaConMasIntegrantesDpto = 0;
    int mayorCantIntegrantes = 0;
    int totalEdades = 0;
    int cantEstudiosIncompletos = 0;
    float cantMasculino=0;
    float cantFemenino=0;
    float porcentajeFemenino = 0;
    float porcentajeMasculino = 0;

    for(int i = 0; i < cantFamiliasCargadas; i++) {
        cantIntegrantes += familias[i].cantIntegrantes;
        if(familias[i].cantIntegrantes > mayorCantIntegrantes) {
            mayorCantIntegrantes = familias[i].cantIntegrantes;
        }
        if(familias[i].cantIntegrantes > mayorCantIntegrantes && familias[i].tipoVivienda=='D') {
            idFamiliaConMasIntegrantesDpto = familias[i].idFamilia;
        }
    }

    for(int i = 0; i < cantIntegrantes; i++){

        totalEdades += integrantes[i].edad;
        if(integrantes[i].sexo=='M' || integrantes[i].sexo=='m'){
            cantMasculino++;
        }
        if(integrantes[i].sexo=='F' || integrantes[i].sexo=='F'){
            cantFemenino++;
        }
        porcentajeMasculino = cantMasculino / cantIntegrantes;
        porcentajeFemenino = cantFemenino / cantIntegrantes;

        if(integrantes[i].nivelEstudios == 'P' && integrantes[i].estadoNivelEstudios == 'C'){
            cantIntegrantesPrimario++;
        }

        if(integrantes[i].nivelEstudios == 'N' && integrantes[i].edad>10){
            cantAnalfabetismo++;
            porcentajeAnalfabetismo = cantAnalfabetismo / cantIntegrantes;
        }

        if(integrantes[i].estadoNivelEstudios == 'I'){
            cantEstudiosIncompletos++;
        }
    }

    cout << "Cantidad de integrantes que completaron el primario: " << cantIntegrantesPrimario << endl;
    cout << "Porcentaje de analfabetismo: " << porcentajeAnalfabetismo*100 << "%" << endl;
    cout << "ID de la familia con mayor cantidad de integrantes que viven en departamento: " << idFamiliaConMasIntegrantesDpto << endl;
    cout << "Edad promedio: " << totalEdades / cantIntegrantes << endl;
    cout << "Cantidad de encuestados con estudios incompletos: " << cantEstudiosIncompletos << endl;
    cout << "Porcentaje de encuestados de sexo femenino y masculino: " << "F: " << porcentajeFemenino*100 << "% | M: " << porcentajeMasculino*100 << "%" << endl;
}


