#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
#include "Matriz.h"
using namespace std;


void resolver(Matriz<int>& lista, vector<int>anchuras_maquinas, vector<int> anchuras_carreteras, int k, int num_maquinas, int num_carreteras,int& calidad,int& calidad_maxima, vector<bool>& usadas_maq, vector<bool>& usadas_car, vector< int>maximos) {
	if (k == num_maquinas) {
		if (calidad > calidad_maxima) {
			calidad_maxima = calidad;
		}
	}
	else {
		for (int i = 0;i < num_carreteras;i++) {
			if (anchuras_maquinas[k] <= anchuras_carreteras[i] && !usadas_maq[k] && !usadas_car[i]) { // && calidad + maximos[k + 1] > calidad_maxima
				calidad += lista[k][i];
				usadas_maq[k] = true;
				usadas_car[i] = true;
				resolver(lista, anchuras_maquinas, anchuras_carreteras, k + 1, num_maquinas, num_carreteras, calidad, calidad_maxima, usadas_maq, usadas_car, maximos);
				usadas_maq[k] = false;
				usadas_car[i] = false;
				calidad -= lista[k][i];
			}
		}
		resolver(lista, anchuras_maquinas, anchuras_carreteras, k + 1, num_maquinas, num_carreteras, calidad, calidad_maxima, usadas_maq, usadas_car, maximos);
	}
}

/*
void hacervectormaximos(vector<long long int>& maximos, int num) {
	for (long long int i = num - 2;i >= 0;i--) {
		maximos[i] += maximos[i + 1];
	}
}
*/

void resuelveCaso() {
	int calidad = 0, calidad_maxima = -1;
	int num_maquinas, num_carreteras, aux;
	cin >> num_maquinas >> num_carreteras;
	vector<int>anchuras_maquinas, anchuras_carreteras, maximos(num_maquinas + 1);
	Matriz<int>lista(num_maquinas, num_carreteras);
	vector<bool>usadas_maq, usadas_car;
	for (int i = 0;i < num_maquinas;i++) {
		cin >> aux;
		anchuras_maquinas.push_back(aux);
		usadas_maq.push_back(false);
		maximos[i] = -1;
	}
	for (int i = 0;i < num_carreteras;i++) {
		cin >> aux;
		anchuras_carreteras.push_back(aux);
		usadas_car.push_back(false);
	}
	for (int i = 0;i < num_maquinas;i++) {
		for (int j = 0;j < num_carreteras;j++) {
			cin >> aux;
			lista[i][j] = aux;
			if (aux > maximos[i]) {
				maximos[i] = aux;
			}
		}
	}
	//hacervectormaximos(maximos, num_maquinas);
	resolver(lista, anchuras_maquinas, anchuras_carreteras, 0, num_maquinas, num_carreteras, calidad, calidad_maxima, usadas_maq, usadas_car, maximos);
	if (calidad_maxima == -1) {
		calidad_maxima = 0;
	}
	cout << calidad_maxima << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	for (int j = 0;j < num;j++) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}