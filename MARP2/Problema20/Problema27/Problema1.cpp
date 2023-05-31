#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct cancion {
	int dur;
	int punt;
	double ppd;
};

/*
Se llevan las canciones ordenadas en un vector según sus puntos por duración y se podan las ramas en las que se prueba una canción ya usada
Tampoco se sigue con las ramas en las que rellenando los huecos disponibles con el mayor rendimiento que queda no se llegaría al maximo

O(3^n) donde n es el número de canciones
*/

void resolver(int& N, int& T, vector<cancion>& X, int& totaldur1, int& totaldur2, int& ptos, int& max, int k) {
	if (k < N) {
		totaldur1 += X[k].dur;
		if (totaldur1 <= T) {
			ptos += X[k].punt;
			if ((2 * T - totaldur1 - totaldur2) * X[k + 1].ppd + ptos > max) {
				resolver(N, T, X, totaldur1, totaldur2, ptos, max, k + 1);
			}
			ptos -= X[k].punt;
		}
		totaldur1 -= X[k].dur;
		totaldur2 += X[k].dur;
		if (totaldur2 <= T) {
			ptos += X[k].punt;
			if ((2 * T - totaldur1 - totaldur2) * X[k + 1].ppd + ptos > max) {
				resolver(N, T, X, totaldur1, totaldur2, ptos, max, k + 1);
			}
			ptos -= X[k].punt;
		}
		totaldur2 -= X[k].dur;
		resolver(N, T, X, totaldur1, totaldur2, ptos, max, k + 1);
	}
	else if (k == N && ptos > max) { max = ptos; }
}

bool resuelveCaso() {
	int N, T, max = 0, ptos = 0, t1 = 0, t2 = 0;
	cancion aux;
	cin >> N;
	if (N == 0) { return false; }
	cin >> T;
	vector<cancion> X;
	for (int i = 0; i < N; i++) {
		int j = 0, n = X.size();
		cin >> aux.dur;
		cin >> aux.punt;
		aux.ppd = aux.punt * 1.0 / aux.dur;
		while (j <= n) {
			if (j == n) { X.push_back(aux); }		//Se ordena el vector de forma decreciente segun los puntos por duracion para probar antes con los más prometedores
			else if (aux.ppd > X[j].ppd) {
				X.insert(X.begin() + j, aux);
				j = n + 1;
			}
			j++;
		}
	}
	aux.ppd = 0;
	X.push_back(aux);
	resolver(N, T, X, t1, t2, ptos, max, 0);
	std::cout << max << endl;
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