// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

struct festivales {
	int cantidad, precio;
};

//Misma idea que el 4 del juez pero ahora solo se puede ir una vez a cada festival, asique hay que mirar siempre a la fila anterior
//m(i,j)= max numero de grupops que puedo ver con presupuesto j teniendo en cuenta los festivales 1...i

void funcion(Matriz<int>& m, int F, int C, vector<festivales>v) {
	for (int i = 1;i <= F;i++) {
		for (int j = 1;j <= C;j++) {
			if (j< v[i-1].precio) {
				m[i][j] = m[i - 1][j];
			}
			else {
				m[i][j] = max(m[i - 1][j], m[i-1][j - v[i - 1].precio]+v[i-1].cantidad);
			}
		}
	}
}


bool resuelveCaso() {
	int presupuesto,festis;
	cin >> presupuesto>>festis;
	if (!cin) {
		return false;
	}
	Matriz<int>m(festis + 1, presupuesto + 1,0);
	vector<festivales>v;
	int a,b;
	for (int i = 0;i < festis;i++) {
		cin >> a>>b;
		v.push_back({ a,b });
	}
	funcion(m, festis, presupuesto, v);
	cout << m[festis][presupuesto] << '\n';
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