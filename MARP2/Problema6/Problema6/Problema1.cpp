// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

int funcion(Matriz<long long int>& m, int n, string palabra) {
	for (int cont = 1; cont < n; ++cont) {
		for (int i = 0, j = cont; j < n; ++i, ++j) {
			if (palabra[i] == palabra[j]) {
				m[i][j] = m[i + 1][j - 1];
			}
			else {
				m[i][j] = min(m[i][j - 1], m[i + 1][j]) + 1;
			}
		}
	}
	return m[0][n - 1];
}

void rec(Matriz<long long int>& m, int n, string palabra, vector<char>& sol) {
	int cont = 0;
	int tam = sol.size() - 1;
	int i = 0, j = n - 1;
	while (i <= j) {
		if (palabra[i] == palabra[j]) {
			sol[cont] = palabra[i];
			sol[tam - cont] = palabra[j];
			i++;
			j--;
		}
		else {
			if (m[i + 1][j] < m[i][j - 1]) {
				sol[cont] = palabra[i];
				sol[tam - cont] = palabra[i];
				i++;
			}
			else {
				sol[cont] = palabra[j];
				sol[tam - cont] = palabra[j];
				j--;
			}
		}
		cont++;
	}
}

bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	if (!cin) {
		return false;
	}
	int n = palabra.size();
	Matriz<long long int>m(n, n, 0);
	int num_letras = funcion(m, n, palabra);
	int tam = n + num_letras;
	vector<char> sol(tam);
	rec(m, n, palabra, sol);
	string palindromo;
	for (int i = 0;i < tam;i++) {
		palindromo.push_back(sol[i]);
	}
	cout << num_letras << " " << palindromo << '\n';

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