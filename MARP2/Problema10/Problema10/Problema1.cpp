// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

void funcion_mat(vector <pair<int, int>> pelis, Matriz<int>&M,int N) { 
	for (int i = 0; i < N + 1; ++i) {
		M[i][0] = 0;
	}
	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j <= 1440; ++j) {
			if (j < pelis[i - 1].first + pelis[i - 1].second + 10) {
				M[i][j] = M[i - 1][j];
			}
			else {
				M[i][j] = max(M[i - 1][j], M[i - 1][pelis[i - 1].first] + pelis[i - 1].second);
			}
		}
}
//M[i][j]=numero maximo de minutos que estara viendo peliculas en el tiempo j cogiendo lasa pelis de 1...i

void funcion_vec(vector <pair<int, int>> pelis, vector<int>& V, int N) {
	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1450; j > 0; --j) {
			if (j >= pelis[i - 1].first + pelis[i - 1].second + 10) {
				V[j] = max(V[j], V[pelis[i - 1].first] + pelis[i - 1].second);
			}
		}
	}
}

bool resuelveCaso() {
	int  N;
	cin>>N;
	if (N==0) {
		return false;
	}
	char aux;
	int horas, minutos, dur, ini;
	vector <pair<int, int>> pelis;
	for (int i = 0; i < N; ++i) {
		cin >> horas >> aux >> minutos >> dur;
		ini = horas * 60 + minutos;
		pelis.push_back({ ini, dur });
	}
	sort(pelis.begin(), pelis.end());
	// 1441 = 24*60 +1 (minutos del dia)
	Matriz <int> M(N+1, 1441);
	vector<int>V;
	for (int j = 0; j < 1451; ++j) {
		V.push_back(0);
	}
	funcion_vec(pelis, V, N);
	cout <<V[1450] << '\n';

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