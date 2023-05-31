// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

//M(i,j)= coste minimo para ir de i a j (ejercicio 6)


void funcion(Matriz<int> alquileres, Matriz<int>& M, int N) {
	for (int d = 1; d < N; ++d) {
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			if (i <= j) {
				int min_aux = 1000001;
				for (int k = i + 1; k < j; ++k) {
					if (min_aux > M[i][k] + M[k][j]) {
						min_aux = M[i][k] + M[k][j];
					}
				}
				M[i][j] = min(min_aux, alquileres[i][j]);
			}
		}
	}
}


bool resuelveCaso() {
	int N,valor;
	cin >> N;
	if (!cin)
		return false;
	Matriz<int>alquileres(N,N, 1000001);
	for (int i = 0; i < N; ++i) {
		alquileres[i][i] = 0;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i < j) {
				cin >> valor;
				alquileres[i][j] = valor;
			}
		}
	}
	Matriz<int> M(N, N,1000001);

	funcion(alquileres, M, N);
	for (int i = 0; i <N; ++i) {
		for (int j= 0; j < N; ++j) {
			if (i < j) {
				cout << M[i][j]<<" ";
			}
		}
		cout << '\n';
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