#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int dia;
	int mes;
	int anio;
	
	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;
	cout << "Ingrese el aniio: ";
	cin >> anio;
	
	cout << "La fecha en formato AAAAMMDD es: ";
	cout << setw(4) << setfill('0') << anio << setw(2) << setfill('0') << mes << setw(2) << setfill('0') << dia << endl;
	return 0;
}
