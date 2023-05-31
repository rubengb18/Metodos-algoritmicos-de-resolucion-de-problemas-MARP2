// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

struct tCofre {
	int profundidad, cant;
	bool cogido;
};


void funcion(Matriz<long long int>& m, int F, int C, vector<tCofre>cofres) {
	m[0][0] = 0;
	for (int i = 1;i <= F;i++) {
		m[i][0] = 0;
		for (int j = 1;j <= C;j++) {
			if (j< 3*cofres[i-1].profundidad) {
				m[i][j] = m[i - 1][j];
			}
			else {
				m[i][j] = max(m[i - 1][j], m[i-1][j- 3*cofres[i - 1].profundidad]+cofres[i-1].cant);
			}
		}
	}
}

void rec(Matriz<long long int>& m, int N, int T, vector<tCofre>&cofres, int& cont) {
	int j = T;
	for (int i = N; i > 0; --i) {
		if (m[i][j] != m[i - 1][j]) {
			cofres[i - 1].cogido = true;
			j -= 3 * cofres[i - 1].profundidad;
			cont++;
		}
	}
}
bool resuelveCaso() {
	int T, N;
	cin >> T >> N;
	if (!cin) {
		return false;
	}
	Matriz<long long int>m(N + 1, T + 1, 0);
	vector<tCofre>cofres;
	int pot, coste;
	for (int i = 0;i < N;i++) {
		cin >> pot >> coste;
		cofres.push_back({ pot,coste,false });
	}
	funcion(m, N, T, cofres);
	int cont = 0;
	rec(m, N, T, cofres,cont);
	cout << m[N][T] << '\n'<< cont << '\n';
	for (int i = 0; i < N; ++i){
		if (cofres[i].cogido) {
			cout << cofres[i].profundidad << " " << cofres[i].cant << '\n';
		}
	}
	cout << "---" << '\n';

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