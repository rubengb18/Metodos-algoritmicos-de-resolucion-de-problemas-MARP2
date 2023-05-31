// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;




void funcion(Matriz<int>& m, Matriz<int>& tablero, int F, int C) {
	for (int i = 1;i <= F;i++) {
		for (int j = 1;j <= C;j++) {
			if (j < C && j>1) {
				m[i][j] = max(max(m[i - 1][j - 1], m[i - 1][j]), m[i - 1][j + 1]) + tablero[F-i][j-1];
			}
			else if (j == C) {
				m[i][j] = max(m[i - 1][j - 1], m[i - 1][j])+  tablero[F - i][j - 1];
			}
			else {
				m[i][j] = max(m[i - 1][j], m[i -1][j+1]) + tablero[F - i][j-1];
			}
		}
	}
}



bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin) {
		return false;
	}
	Matriz<int>m(num + 1, num + 1, 0),tablero(num, num,0);
	vector<int>v;
	int dato;
	for (int i = num-1;i >=0;i--) {
		for (int j = 0;j < num;j++) {
			cin >> dato;
			tablero[i][j] = dato;
		}
	}
	funcion(m, tablero, num,num);
	int max = -1,col;
	for (int i = 1;i <= num;i++) {
		if (m[num][i] > max) {
			max = m[num][i];
			col = i;
		}
	}
	cout << max<<" "<<col<<'\n';
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