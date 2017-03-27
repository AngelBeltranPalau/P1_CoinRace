#include "Player.h"
#include "Map.h"
#include "Input.h"
#include "CoinManager.h"
#include <conio.h>


//CoinManager Z;
bool gameESC;

void Player::mover(int x, int y, Input::Key tecla/*, Map A, CoinManager Z*/) {
	
	switch (tecla)
	{
	case Input::Key::NONE:
		break;
	case Input::Key::W:
		if (y != 0) {
			mimapa.map[x][y] = '.';
			if (y - 1 == '$') {
				puntos++;
				micoinmanager.eliminarMoneda(x, y-1);
			}
			y--;
			mimapa.map[x][y] = '@';
		}
		break;
	case Input::Key::A:
		if (x != 0) {
			mimapa.map[x][y] = '.';
			if (x - 1 == '$') {
				puntos++;
				micoinmanager.eliminarMoneda(x - 1, y);
				x--;
			}
			mimapa.map[x][y] = '@';
		}
		
		break;
	case Input::Key::S:
		if (x != mimapa.Columnas) {
			mimapa.map[x][y] = '.';
			if (y + 1 == '$') {
				puntos++;
				micoinmanager.eliminarMoneda(x, y + 1);
			}
			x++;
			mimapa.map[x][y] = '@';
		}
		break;
	case Input::Key::D:
		if (y != mimapa.Filas) {
			mimapa.map[x][y] = '.';
			if (x + 1 == '$') {
				puntos++;
				micoinmanager.eliminarMoneda(x + 1, y);
			}
			y = y + 1;
			mimapa.map[x][y] = '@';
		}
		break;
	case Input::Key::ENTER:
		break;
	case Input::Key::ESC:
		gameESC = true;
		break;
	default:
		break;
	}
}


Player::Player(Map &a, CoinManager &b): mimapa(a), micoinmanager(b)
{
	x = 0;
	y = 0;
}


Player::~Player()
{
}
