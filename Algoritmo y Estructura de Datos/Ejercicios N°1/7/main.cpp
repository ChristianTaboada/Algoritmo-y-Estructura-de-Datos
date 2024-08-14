#include <iostream>

using namespace std;

int main() {
	int valor;
	
	cout << "Ingrese un valor entero: ";
	cin >> valor;
	
	double quintaParte = valor/5.0;
	
	int resto = valor % 5;
	
	double septimaParte = quintaParte / 7.0;
	
	cout << "La quinta parte de " << valor << " es: " <<quintaParte << endl;
	cout << "El resto de la division por 5 de " << valor << " es: " << resto << endl;
	cout << "La septima parte de " << quintaParte << " es: " << septimaParte << endl;
	
	return 0;
}
