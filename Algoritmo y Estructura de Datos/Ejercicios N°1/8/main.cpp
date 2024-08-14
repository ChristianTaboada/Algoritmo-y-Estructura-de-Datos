#include <iostream>

using namespace std;

int main() {
	
	double importe;
	
	cout << "Ingrese el importe de la compra:  ";
	cin >> importe;
	
	double cuota1 = importe;
	double cuota2 = (importe * 1.05) / 2;
	double total2 = importe * 1.05;
	double cuota6 = (importe * 1.30) / 6;
	double total6 = importe * 1.30;
	double cuota12 = (importe * 1.50) / 12;
	double total12 = importe * 1.50;
	
	cout << "Las formas de pago con el importe ingresado son: " << endl;
	cout << "En 1 Cuota de: $" << cuota1 << endl;
	cout << "En 2 Cuotas de: $" << cuota2 << " Importe Total: $" << total2 << endl;
	cout << "En 6 Cuotas de: $" << cuota6 << " Importe Total: $" << total6 << endl;
	cout << "En 12 Cuotas de: $" << cuota12 << " Importe Total: $" << total12 << endl;
	
	return 0;
}
