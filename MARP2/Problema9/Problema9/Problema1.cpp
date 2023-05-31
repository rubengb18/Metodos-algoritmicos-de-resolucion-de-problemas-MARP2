// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

int ordenarCortes(vector<int> Marcas, Matriz<int>&Esfuerzo,int N) { //O(n^3) tiempo, O(n^2) espacio
	 for (int d = 1; d <= N ; ++d) {
		 for (int i = 0; i < N - d; ++i) {
			 int j = i + d;
			 Esfuerzo[i][j] = 9999999999999;
			 for (int k = i; k < j; ++k) {
				 int esf_actual =  Esfuerzo[i][k]+Esfuerzo[k+1][j]+2*(Marcas[j+1] - Marcas[i]);
				 if (esf_actual < Esfuerzo[i][j]) {
					 Esfuerzo[i][j] = esf_actual;
				 }
			 }
		 }
	 }
	return Esfuerzo[0][N-1];
}


bool resuelveCaso() {
	int L, N;
	cin >> L>>N;
	if (L==0 && N==0) {
		return false;
	}
	int c;
	vector<int>Marcas(N+2,0);
	for (int i = 1;i < N+1;i++) {
		cin >> c;
		Marcas[i] = c;
	}
	Marcas[N+1] = L;
	Matriz<int> Esfuerzo(N + 1, N + 1, 0);
	int min_esf = ordenarCortes(Marcas, Esfuerzo,N+1);
	cout << min_esf << '\n';
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