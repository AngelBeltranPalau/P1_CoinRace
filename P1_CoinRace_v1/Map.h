#pragma once

enum class dificultad { FACIL = 1, NORMAL = 2, DIFICIL = 3 };

class Map
{
public:
	
	void matriz(int numFilas, int numColumnas, char **map);
	void printMap();
	Map(dificultad A);
	~Map();

	int Filas, Columnas;
	char **map;
};

