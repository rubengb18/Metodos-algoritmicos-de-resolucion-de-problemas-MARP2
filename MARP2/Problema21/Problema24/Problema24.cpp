#include <fstream>
#include<iostream>
#include <vector>
#include<algorithm>
#include "Matriz.h"
using namespace std;



bool esValida(vector<int>& prod_en_mercado, int& coste, int& coste_min,int i) {
	if (prod_en_mercado[i] > 3||coste>coste_min) {
		return false;
	}
	return true;
}

void resolver(Matriz<int>&lista,int k,int &soluciones,int &coste,int &coste_min,int& num_supermercados, int& num_productos, vector<int>&prod_en_mercado,vector<int>&minimos) {
	if (k == num_productos) {
		if (coste < coste_min) {
			coste_min = coste;
		}
		soluciones++;
	}
	else {
		for (int i = 0;i< num_supermercados;i++) {
			coste += lista[i][k];
			prod_en_mercado[i]++;
			if (prod_en_mercado[i]<4 && coste+minimos[k+1] < coste_min) {
				resolver(lista, k+1, soluciones, coste, coste_min, num_supermercados, num_productos, prod_en_mercado,minimos);
			}
			coste -= lista[i][k];
			prod_en_mercado[i]--;
		}
	}
}


void creaMinimosParciales(vector<int>& minimos, int numprod) {
	for (int i = numprod - 2; i >= 0; i--) {
		minimos[i] += minimos[i + 1];
	}
}

void resuelveCaso() {
	
	int num_productos,n, num_supermercados,coste=0, soluciones=0, coste_min=1000000;
	
	cin >> num_supermercados >> num_productos;
	Matriz<int>lista(num_supermercados, num_productos);
	vector<int>prod_en_mercado(num_supermercados), minimos(num_productos + 1);
	for (int j = 0;j < num_productos;j++) {
		minimos[j] = 10000000;
	}
	for (int i = 0;i < num_supermercados;i++) {
		for (int j = 0;j < num_productos;j++) {
			cin >> n;
			lista[i][j] = n;
			if (n < minimos[j]) {
				minimos[j] = n;
			}
		}
	}
	creaMinimosParciales(minimos, num_productos);
	resolver(lista, 0,soluciones,coste,coste_min, num_supermercados, num_productos, prod_en_mercado,minimos);
		if (soluciones == 0) {
			cout <<"Sin solucion factible" << '\n';
		}
		else {
			cout << coste_min << '\n';
		}
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;

	for (int i = 0;i < num;i++ ){
		(resuelveCaso());
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}