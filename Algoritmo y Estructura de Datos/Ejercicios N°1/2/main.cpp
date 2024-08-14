#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int numero1;
	int numero2;
	int suma;
	int resta;
	int producto;
	int division;
	
	cout << "Ingrese un numero" << endl;
	cin >> numero1;
	cout << "Ingrese el segundo numero" << endl;
	cin >> numero2;
	
	suma = numero1 + numero2;
	resta= numero1 - numero2;
	producto= numero1 * numero2;
	division= numero1/numero2;
	
	cout << "La suma entre los dos numeros ingresados es: " << suma << endl;
	cout << "La resta entre los dos numeros ingresados es: " << resta << endl;
	cout << "El producto entre los dos numeros es: " << producto << endl;
	cout << "La division entre los dos numeros es: " << division << endl;
}
