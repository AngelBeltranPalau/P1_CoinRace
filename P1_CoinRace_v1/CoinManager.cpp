#include <iostream>
#include "CoinManager.h"
#include "Map.h"

int minMonedas, maxMonedas;
int numMonedas;

void CoinManager::rellenarMapa() {
	int i = 0;
	numMonedas = rand() % (maxMonedas - minMonedas) + minMonedas;
	while (i < numMonedas) {
		int x = rand() % mimapa.Filas;
		int y = rand() % mimapa.Columnas;

		if (mimapa.map[x][y] == '.') {
			mimapa.map[x][y] = '$';
			i++;
		}
	}

}

void CoinManager::eliminarMoneda(int x, int y) {
	if (mimapa.map[x][y] == '$') {
		mimapa.map[x][y] = '.';
		numMonedas--;
		if (numMonedas == 0) {
			rellenarMapa();
		}
	}
}


CoinManager::CoinManager(Map &A): mimapa(A)
{
	minMonedas = A.Filas * A.Columnas * 0.03;
	maxMonedas = A.Filas * A.Columnas * 0.13;
}


CoinManager::~CoinManager()
{
}
