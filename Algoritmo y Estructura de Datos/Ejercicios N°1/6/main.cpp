#include <iostream>

using namespace std;

int main() {
	float bitcoin = 45000;
	float dolares;
	float resultado;
	
	cout << "Ingrese la cantidad de dolares" << endl;
	cin >> dolares;
	resultado = dolares/bitcoin;
	cout << resultado << "BTC" << endl;
	
	return 0;
}
