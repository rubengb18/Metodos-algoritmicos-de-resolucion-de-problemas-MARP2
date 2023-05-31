// Grupo DG, Ruben Gomez Blanco
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <limits>
#include <algorithm>
using namespace std;

//M(i,j)= cantidad maxima de dias que puede comer de bizcocho[i...j]
//Muy parecido al de las vacas (el 13 del juez) pero con mas casos

void funcion(vector<int> bizcocho, Matriz<int>& M, int N) {
	for (int d = 1; d < N; ++d) {
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			if (abs(i - j) % 2 == 1) { // solo conjuntos de cardinal par
				int op1, op2, op3;
				//Si coinciden o no el inicio y el final
				if (i + 1 == j) {
					if (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0) {
						op1 = 1;
					}
					else {
						op1 = 0;
					}
				}
				else if (bizcocho[i] != bizcocho[j]) {
					op1 = M[i+1][j-1];
				}
				else {
					if (bizcocho[i] == 1 || bizcocho[i] == 2) {
						op1 =1+ M[i + 1][j - 1];
					}
					else {
						op1 = M[i + 1][j - 1];
					}
				}
				//Si coinciden o no por la izquierda
				if (i + 1 == j) {
					if (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0) {
						op2 = 1;
					}
					else {
						op2 = 0;
					}
				}
				else if (bizcocho[i] != bizcocho[i+1]) {
					op2= M[i + 2][j];
				}
				else {
					if (bizcocho[i] == 1 || bizcocho[i] == 2) {
						op2 = 1 + M[i + 2][j];
					}
					else {
						op2 = M[i + 2][j];
					}
				}
				//Si coinciden o no por la derecha
				if (i + 1 == j) {
					if (bizcocho[i] == bizcocho[j] && bizcocho[i] != 0) {
						op3 = 1;
					}
					else {
						op3 = 0;
					}
				}
				else if (bizcocho[j-1] != bizcocho[j]) {
					op3 = M[i][j - 2];
				}
				else {
					if (bizcocho[j] == 1 || bizcocho[j] == 2) {
						op3 = 1 + M[i][j - 2];
					}
					else {
						op3 = M[i][j - 2];
					}
				}
				M[i][j] = max(max(op1, op2),op3);
			}	
		}
	}
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;
	vector <int> bizcocho;
	int valor;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		bizcocho.push_back(valor);
	}
	Matriz<int> M(N, N,0);
	funcion(bizcocho, M, N);
	cout <<M[0][N-1]<< '\n';
	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}