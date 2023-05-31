// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

struct cuerda{
	int longitud, precio;
};

bool esPosible_rect(Matriz<bool>& esPosible, int N, int L, vector<cuerda>v) {
	esPosible[0][0] = true;
	for (int i = 1;i <= N;i++) {
		esPosible[i][0] = true;
		for (int j = 1;j <= L;j++) {
			if (v[i-1].longitud > j) {
				esPosible[i][j] = esPosible[i - 1][j];
			}
			else {
				esPosible[i][j] = esPosible[i-1][j] || esPosible[i-1][j - v[i-1].longitud];
			}
		}
	}
	return esPosible[N][L];
}


long long int formas_rect(Matriz<long long int>& formas, int N, int L, vector<cuerda>v) {
	formas[0][0] = 1;
	for (int i = 1;i <= N;i++) {
		formas[i][0] = 1;
		for (int j = 1;j <= L;j++) {
			if (v[i - 1].longitud > j) {
				formas[i][j] = formas[i - 1][j];
			}
			else {
				formas[i][j] = formas[i-1][j]+ formas[i-1][j- v[i - 1].longitud];
			}
		}
	}
	return formas[N][L];
}

long long int minCuerdas_reg(Matriz<long long int>& minCuerdas, int N, int L, vector<cuerda>v) {
	minCuerdas[0][0] = 0;
	for (int i = 1;i <= N;i++) {
		minCuerdas[i][0] = 0;
		for (int j = 1;j <= L;j++) {
			if (v[i - 1].longitud > j) {
				minCuerdas[i][j] = minCuerdas[i - 1][j];
			}
			else {
				minCuerdas[i][j] = min(minCuerdas[i - 1][j], minCuerdas[i - 1][j - v[i - 1].longitud]+1);
			}
		}
	}
	return minCuerdas[N][L];
}

long long int minCoste_reg(Matriz<long long int>& minCoste, int N, int L, vector<cuerda>v) {
	minCoste[0][0] = 0;
	for (int i = 1;i <= N;i++) {
		minCoste[i][0] = 0;
		for (int j = 1;j <= L;j++) {
			if (v[i - 1].longitud > j) {
				minCoste[i][j] = minCoste[i - 1][j];
			}
			else {
				minCoste[i][j] = min(minCoste[i - 1][j], minCoste[i - 1][j - v[i - 1].longitud]+v[i-1].precio);
			}
		}
	}
	return minCoste[N][L];
}

bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!cin) {
		return false;
	}
	Matriz<bool>esPosible(N + 1, L + 1, false);
	Matriz<long long int>formas(N + 1, L + 1,0);
	Matriz<long long int>minCuerdas(N + 1, L + 1, 9999999999999);
	Matriz<long long int>minCoste(N + 1, L + 1, 9999999999999);
	vector<cuerda>v;
	int longitud, precio;
	for (int i = 0;i < N;i++) {
		cin >> longitud >> precio;
		v.push_back({longitud, precio});
	}
	if (esPosible_rect(esPosible, N, L, v)) {
		cout << "SI "<<formas_rect(formas, N, L, v)<<" "<< minCuerdas_reg(minCuerdas, N, L, v) << " " << minCoste_reg(minCoste, N, L, v) <<'\n';

	}
	else {
		cout << "NO" << '\n';
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