// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

int funcion(Matriz<long long int>& m, int n1,int n2, string p1,string p2) {
	for (int i = 1; i <= n1; i++){
		for (int j = 1; j <= n2; j++){
			if (p1[i - 1] == p2[j - 1]) {
				m[i][j] = m[i - 1][j - 1] + 1;
			}
			else {
				m[i][j] = max(m[i - 1][j], m[i][j - 1]);
			}
		}
	}
	return m[n1][n2];
}

void rec(Matriz<long long int>& m, int n1, int n2, string p1, string p2, vector<char>& sol) {
	int i = n1, j = n2;
	int cont = sol.size();
	while (i > 0 && j > 0){
		if (p1[i - 1] == p2[j - 1]){
			sol[cont - 1] = p1[i - 1];
			i--;
			j--;
			cont--;
		}
		else if (m[i - 1][j] > m[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
}

bool resuelveCaso() {
	string p1,p2;
	cin >> p1 >> p2;
	if (!cin) {
		return false;
	}
	int n1 = p1.size(), n2 = p2.size();
	Matriz<long long int>m(n1+1, n2+1, 0);
	int num_letras = funcion(m, n1,n2,p1,p2);
	vector<char> sol(num_letras);
	rec(m, n1, n2, p1, p2, sol);
	string subcad;
	for (int i = 0;i < num_letras;i++) {
		subcad.push_back(sol[i]);
	}
	cout << subcad << '\n';

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