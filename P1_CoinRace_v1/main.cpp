#include <iostream>
#include "CoinManager.h"
#include "Input.h"
#include "Map.h"
#include "Player.h"
#include <ctime>


void main() {
	//Generando valores aleatorios
	srand(time(NULL));

	//Declarar la dificultad
	int aux = 4;
	dificultad dif;

	int HORA, MINUTO, SEGUNDO, ML = 0;

	while (aux != 1 && aux != 2 && aux != 3) {
		std::cout << "Introduce la dificultad:";
		std::cin >> aux;
		dif = static_cast <dificultad> (aux);
	}

	//Instanciar el Mapa
	Map map(dif);
	
	
	//Instanciar el CoinManager
	CoinManager monedas(map);
	monedas.rellenarMapa();

	//Instanciar el Player
	Player jugador(map, monedas);

	jugador.gameESC = false;

	//Se declara una variable que determina el máximo de monedas que el jugador debe conseguir para finalizar el juego
	int minAux = 30 * static_cast <int> (dif);
	int maxAux = 60 * static_cast <int> (dif);
	int maxMonedas = (rand() % (maxAux - minAux)) + minAux;

	//Variable que recoge la tecla pusada
	Input::Key tecla;
	map.printMap();
	std::cout << std::endl << std::endl << "Tu puntuacion es de: " << jugador.puntos << std::endl << "Tienes que llegar a :" << maxMonedas;
	//GameLoop


	std::clock_t start;
	double duration;

	start = std::clock();


	while (jugador.puntos < maxMonedas && jugador.gameESC == false) {
		tecla = Input::getKey();
		if (tecla != Input::Key::NONE) {
			system("cls");
			jugador.mover(jugador.x, jugador.y, jugador.puntos, tecla);
			monedas.eliminarMoneda(jugador.x, jugador.y);
			map.printMap();
			if (monedas.numMonedas == 0) {
				monedas.rellenarMapa();
			}
		std::cout << std::endl << std::endl << "Tu puntuacion es de: " << jugador.puntos << std::endl << "Tienes que llegar a :" << maxMonedas;
		}
	}

	system("cls");
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
     

	std::cout << "Enhorabuena, has conseguido los " << maxMonedas << " puntos!" << std::endl;
	std::cout << "Tu tiempo ha sido de " << duration << " segundos!" << std::endl << std::endl;

	std::cout << "Pulsa ENTER para salir";

	while(tecla != Input::Key::ENTER)
	{ 
		tecla = Input::getKey();
		continue;
	}
	
	system("break");

}

					