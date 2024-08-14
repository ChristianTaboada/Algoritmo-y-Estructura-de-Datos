#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float producto1;
	float producto2;
	float producto3;
	float promedio;
	
	cout << "Ingrese el precio del primer producto" << endl;
	cin >> producto1;
	cout << "Ingrese el precio del segundo producto" << endl;
	cin >> producto2;
	cout << "Ingrese el precio del tercer producto" << endl;
	cin >> producto3;
	
	promedio = (producto1 + producto2 + producto3)/3;
	
	cout << "El promedio de los tres productos es: " << promedio << endl;
	return 0;
}
