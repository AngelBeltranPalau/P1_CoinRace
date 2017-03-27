#include <iostream>
#include "CoinManager.h"
#include "Map.h"

int minMonedas, maxMonedas;
int numMonedas;

void CoinManager::rellenarMapa(Map A) {
	int i = 0;
	numMonedas = rand() % (maxMonedas - minMonedas) + minMonedas;
	while (i < numMonedas) {
		int x = rand() % A.Filas;
		int y = rand() % A.Columnas;

		if (A.map[x][y] == '.') {
			A.map[x][y] = '$';
			i++;
		}
	}

}

void CoinManager::eliminarMoneda(Map A, int x, int y) {
	if (A.map[x][y] == '$') {
		A.map[x][y] = '.';
		numMonedas--;
		if (numMonedas == 0) {
			rellenarMapa(A);
		}
	}
}


CoinManager::CoinManager(Map A)
{
	minMonedas = A.Filas * A.Columnas * 0.03;
	maxMonedas = A.Filas * A.Columnas * 0.13;
}


CoinManager::~CoinManager()
{
}
