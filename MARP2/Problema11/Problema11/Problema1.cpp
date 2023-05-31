// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

struct tDato {
	vector<bool>v = { false,false,false };
};

//m(i,j)=si es posible insertar parentesis para conseguir una a en la cadena[i...j] y ademas llevo el resultado de lo que vale multiplicar

void funcion(Matriz<char> tabla, Matriz<tDato>&m,int N,string pal) {
	 for (int d = 0; d <= N ; ++d) {
		 for (int i = 0; i < N - d; ++i) {
			 int j = i + d;
			 if (i == j) {	//Estas en la diagonal principal
				 if (pal[i] == 'a') {
					 m[i][j].v[0]=true;
				 }
				 else if (pal[i] == 'b') {
					 m[i][j].v[1] = true;
				 }
				 else {
					 m[i][j].v[2] = true;
				 }
				
			 }
			 else {
				 for (int k = i; k < j; ++k) {
					 for (int l = 0;l < 3;l++) {
						 for (int l2 = 0;l2 < 3;l2++) {
							 if (m[i][k].v[l] && m[k + 1][j].v[l2]) {
								 char letra_actual = tabla[l][l2];
								 if (letra_actual == 'a') {
									 m[i][j].v[0] = true;
								 }
								 else if (letra_actual == 'b') {
									 m[i][j].v[1] = true;
								 }
								 else {
									 m[i][j].v[2] = true;
								 }
							 }
							 
						 }
						 
					 }
				 }
			 }
		 }
	 }
}


bool resuelveCaso() {
	string pal;
	cin >>pal;
	if (!cin) {
		return false;
	}
	int N=pal.size();
	Matriz<char> tabla(3, 3, 'b');
	Matriz<tDato>m(N, N);

	tabla[0][2] = 'a';
	tabla[1][0] = 'c';
	tabla[1][2] = 'a';
	tabla[2][0] = 'a';
	tabla[2][1] = 'c';
	tabla[2][2] = 'c';

	funcion(tabla, m, N,pal);
	if (m[0][N - 1].v[0]) {
	cout << "SI" << '\n';
	}
	else {
		cout <<"NO" << '\n';
	}
	
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