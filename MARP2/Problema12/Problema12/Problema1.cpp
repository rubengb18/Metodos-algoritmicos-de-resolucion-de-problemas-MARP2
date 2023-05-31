// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

struct tMoneda {
	int valor, cantidad;
};


void funcion(vector<tMoneda> moneda, Matriz<int>&M,int N,int C) {
	for (int i = 1; i < N + 1; ++i) {
		M[i][0] = 0;
		for (int j = 1; j < C + 1; ++j) {
			int min_aux = 999999999;
			for (int k = 0; k * moneda[i - 1].valor <= j && k <= moneda[i - 1].cantidad; ++k) {
				if (M[i - 1][j - k * moneda[i - 1].valor] != 999999999) {
					min_aux = min(min_aux, M[i - 1][j - k * moneda[i - 1].valor] + k);
				}
			}
			M[i][j] = min_aux;
		}
	}
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;
	vector<tMoneda> monedas(N);
	for (int i = 0; i < N; ++i) {
		cin >> monedas[i].valor;
	}
	for (int i = 0; i < N; ++i) {
		cin >> monedas[i].cantidad;
	}
	reverse(monedas.begin(), monedas.end());
	int C;
	cin >> C;
	Matriz<int> M(N + 1, C + 1, 999999999);
	M[0][0] = 0;
	funcion(monedas, M, N, C);
	if (M[N][C] == 999999999) {
		cout << "NO";
	}
	else {
		cout << "SI " << M[N][C] ;
	}
	cout << '\n';

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