// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

//M(i,j)= cantidad maxima que puede comer de cubos[i...j]


void funcion(vector<int> cubos, Matriz<int>& M, int N) {
	for (int d = 1; d < N; ++d) {
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			int op1, op2;
			if (i + 1 == j) {
				op1 = cubos[i];
			}
			else if (cubos[i + 1] >= cubos[j]) {
				op1 = cubos[i] + M[i + 2][j];
			}
			else {
				op1 = cubos[i] + M[i + 1][j - 1];
			}

			if (j - 1 == i) {
				op2 = cubos[j];
			}
			else if (cubos[j - 1] >= cubos[i]) {
				op2 = cubos[j] + M[i][j - 2];
			}
			else {
				op2 = cubos[j] + M[i + 1][j - 1];
			}
			M[i][j] = max(op1, op2);
		}
	}
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)
		return false;
	vector <int> cubos;
	int valor;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		cubos.push_back(valor);
	}
	Matriz<int> M(N, N,0);
	for (int i = 0; i < N; ++i) {
		M[i][i] = cubos[i];
	}
	funcion(cubos, M, N);
	cout <<M[0][N-1]<< '\n';
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