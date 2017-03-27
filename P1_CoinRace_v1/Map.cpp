#include <iostream>
#include "Map.h"

int Filas, Columnas;
char **map;

void Map::matriz(int numFilas, int numColumnas, char **map)
{
	
};



	Map::Map(dificultad A)
	{
		Filas = rand() % (10 * static_cast<int>(A) - 5 * static_cast<int>(A)) + 5 * static_cast<int>(A);
		Columnas = rand() % (10 * static_cast<int>(A) - 5 * static_cast<int>(A)) + 5 * static_cast<int>(A);
		map = new char *[Filas];
		for (int i = 0; i < Filas; i++)
		{
			map[i] = new char[Columnas];
			//Rellenar el array con puntos (mapa vacío)
			for (int j = 0; j < Columnas; j++) {
				map[i][j] = '.';
			}
		}
	}

	//Función para cambiar el contenido de las celdas
	void cambiarContenido(int &x, int &y, char casilla)
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
