#include <iostream>
#include "CoinManager.h"
#include "Input.h"
#include "Map.h"
#include "Player.h"

void main() {
	//Declarar la dificultad
	int aux;
	dificultad dif;
	std::cout << "Introduce la dificultad:";
	std::cin >> aux;
	dif = static_cast <dificultad> (aux);

	//Instanciar el Mapa
	Map map(dif);
	
	
	//Instanciar el CoinManager
	CoinManager monedas(map);

	//Instanciar el Player
	Player jugador(map, monedas);

	//Se declara una variable que determina el máximo de monedas que el jugador debe conseguir para finalizar el juego
	int minAux = 30 * static_cast <int> (dif);
	int maxAux = 60 * static_cast <int> (dif);
	int maxMonedas = (rand() % (maxAux - minAux)) + minAux;

	//Variable que recoge la tecla pusada
	Input::Key tecla;
	map.printMap();
	std::cout << std::endl << std::endl << "Tu puntuación es de: " << jugador.puntos;
	//GameLoop
	while (jugador.puntos < maxMonedas || jugador.gameESC == false) {
		tecla = Input::getKey();
		if (tecla != Input::Key::NONE) {
			system("cls");
			jugador.mover(jugador.x, jugador.y, tecla);
			map.printMap();
			std::cout << std::endl << std::endl << "Tu puntuación es de: " << jugador.puntos << std::endl;
		}
		

	}

}