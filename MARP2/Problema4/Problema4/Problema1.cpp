// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;




void funcion(Matriz<long long int>& m, int F, int C, vector<long long int>potencias, vector<long long int>costes) {
	m[0][0] = 0;
	for (int i = 1;i <= F;i++) {
		m[i][0] = 0;
		for (int j = 1;j <= C;j++) {
			if (j< potencias[i-1]) {
				m[i][j] = m[i - 1][j];
			}
			else {
				m[i][j] = min(m[i - 1][j], m[i][j - potencias[i - 1]]+costes[i-1]);
			}
		}
	}
}


bool resuelveCaso() {
	int pMin, pMax,num;
	cin >> num >> pMax>>pMin;
	if (!cin) {
		return false;
	}
	Matriz<long long int>m(num + 1, pMax + 1,1000000000000);
	vector<long long int>potencias,costes;
	long long int pot,coste;
	for (int i = 0;i < num;i++) {
		cin >> pot;
		potencias.push_back(pot);
	}
	for (int i = 0;i < num;i++) {
		cin >> coste;
		costes.push_back(coste);
	}
	funcion(m, num,pMax, potencias,costes);
	long long int minimo = 1000000000000,pos;
	for (int i = pMin;i <= pMax;i++) {
		if (minimo > m[num][i]) {
			minimo=m[num][i];
			pos = i;
		}
	}
	if (minimo!= 1000000000000) {
		cout << minimo<< " "<<pos<< '\n';
	}
	else {
		cout << "IMPOSIBLE" << '\n';
	}

	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while (resuelveCaso()) {
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}