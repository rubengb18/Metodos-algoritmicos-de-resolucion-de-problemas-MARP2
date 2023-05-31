#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
#include"Matriz.h"
using namespace std;


bool esValida(vector<int>& prod_en_mercado, int& coste, int& coste_min, int i) {
	if (prod_en_mercado[i] > 3 || coste > coste_min) {
		return false;
	}
	return true;
}

void resolver(Matriz<int>& lista, int k, int& coste, int& coste_min, int num, vector<bool>& usados, vector<int>minimos) {
	if (k == num) {
		if (coste < coste_min) {
			coste_min = coste;
		}

	}
	else {
		for (int i = 0;i < num;i++) {
			coste += lista[i][k];
			if (coste + minimos[k + 1] < coste_min && !usados[i]) {
				usados[i] = true;
				resolver(lista, k + 1, coste, coste_min, num, usados, minimos);
				usados[i] = false;
			}
			coste -= lista[i][k];
		}
	}
}

void hacervectorminimos(vector<int>& minimos, int num) {
	for (int i = num - 2;i >= 0;i--) {
		minimos[i] += minimos[i + 1];
	}
}


bool resuelveCaso() {
	int num, aux, tiempo = 0, tiempo_min = 10000000;
	cin >> num;
	if (num == 0) {
		return false;
	}
	Matriz<int>lista(num,num);
	vector<bool>usados;
	vector<int>minimos(num + 1);
	for (int i = 0;i < num;i++) {
		minimos[i] = (10000000);
	}
	for (int i = 0;i < num;i++) {
		vector<int>col;
		usados.push_back(false);
		for (int j = 0;j < num;j++) {
			cin >> aux;
			lista[i][j] = aux;
			if (aux < minimos[j]) {
				minimos[j] = aux;
			}
		}
	}
	hacervectorminimos(minimos, num);
	resolver(lista, 0, tiempo, tiempo_min, num, usados, minimos);
	cout << tiempo_min << '\n';
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