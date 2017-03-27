#pragma once
#include "Map.h"
class CoinManager
{

public:
	int numMonedas;
	void rellenarMapa();
	void eliminarMoneda( int x, int y);
	Map &mimapa;
	CoinManager(Map &A);
	~CoinManager();
};

