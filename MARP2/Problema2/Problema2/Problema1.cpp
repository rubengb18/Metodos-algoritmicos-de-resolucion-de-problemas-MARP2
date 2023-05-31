// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;




int num_lanzamientos(Matriz<int>& m, int N, int L, vector<int>v) {
	m[0][0] = 0;
	for (int i = 1;i <= N;i++) {
		m[i][0] = 0;
		for (int j = 1;j <= L;j++) {
			if (v[i - 1] > j) {
				m[i][j] = m[i - 1][j];
			}
			else {
				m[i][j] = min(m[i - 1][j], m[i][j - v[i - 1]]+1);
			}
		}
	}
	return m[N][L];
}

vector<int> rec(Matriz<int>& m,int f,int c, vector<int>&v) {
	int i = f, j = c;
	vector<int>reconstruccion;
	while (j > 0) {
		if (v[i-1] <= j) {
			if (m[i-1][j] >= m[i][j-v[i-1]]+1) {
				reconstruccion.push_back(v[i - 1]);
				j = j - v[i - 1];
			}
			else {
				i--;
			}
		}
		else {
			i--;
		}
	}
	return reconstruccion;
}

bool resuelveCaso() {
	int numMonedas, puntuacion,punt;
	cin >> puntuacion >> numMonedas;
	if (!cin) {
		return false;
	}
	Matriz<int>m(numMonedas + 1, puntuacion + 1, 501);
	vector<int>v;
	int longitud, precio;
	for (int i = 0;i < numMonedas;i++) {
		cin >> punt;
		v.push_back(punt);
	}
	long long int res = num_lanzamientos(m, numMonedas,puntuacion, v);
	
	if (res!= 501) {
		cout << res<<": ";
		vector<int>reconstruccion = rec(m, numMonedas, puntuacion, v);
		int tam = reconstruccion.size();
		for (int i = 0;i < tam;i++) {
			cout << reconstruccion[i] << " ";
		}
		cout << '\n';
	}
	else {
		cout << "Imposible" << '\n';
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