#include <iostream>
#include "Map.h"

void Map::matriz(int numFilas, int numColumnas, char **map)
{
	map = new char *[numFilas];
	for (int i = 0; i < numFilas; i++)
	{
		map[i] = new char[numColumnas];
		//Rellenar el array con puntos (mapa vacío)
		for (int j = 0; j < numColumnas; j++) {
			map[i][j] = '.';
		}
	}
};

	int Filas, Columnas;
	char **map;

	Map::Map(dificultad A)
	{
		Filas = rand() % (10 * static_cast<int>(A) - 5 * static_cast<int>(A)) + 5 * static_cast<int>(A);
		Columnas = rand() % (10 * static_cast<int>(A) - 5 * static_cast<int>(A)) + 5 * static_cast<int>(A);
		matriz(Filas, Columnas, map);
	}

	//Función para cambiar el contenido de las celdas
	void cambiarContenido(int x, int y, char casilla)
	{
		map[x][y] = casilla;
	}

	void Map::printMap() {
		for (int i = 0; i < Filas; i++)
		{
			for (int j = 0; j < Columnas; j++) {
				std::cout << map[i][j];
			}
			std::cout << std::endl;
		}
	}

	Map::~Map()
	{
		delete[]map;
	}
