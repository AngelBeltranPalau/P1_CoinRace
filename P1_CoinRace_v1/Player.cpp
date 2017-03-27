#include "Player.h"
#include "Map.h"
#include "Input.h"
#include "CoinManager.h"
#include <conio.h>


//CoinManager Z;
bool gameESC;

void Player::mover(int x, int y, Input::Key tecla, Map A, CoinManager Z) {
	
	switch (tecla)
	{
	case Input::Key::NONE:
		break;
	case Input::Key::W:
		if (y > 0) {
			A.map[x][y] = '.';
			if (y - 1 == '$') {
				puntos++;
				Z.eliminarMoneda(A, x, y-1);
			}
			y--;
			A.map[x][y] = '@';
		}
		break;
	case Input::Key::A:
		if (x > 0) {
			A.map[x][y] = '.';
			if (x - 1 == '$') {
				puntos++;
				Z.eliminarMoneda(A, x - 1, y);
				x--;
			}
			A.map[x][y] = '@';
		}
		
		break;
	case Input::Key::S:
		if (x < A.Columnas) {
			A.map[x][y] = '.';
			if (y + 1 == '$') {
				puntos++;
				Z.eliminarMoneda(A, x, y + 1);
			}
			x++;
			A.map[x][y] = '@';
		}
		break;
	case Input::Key::D:
		if (y < A.Filas) {
			A.map[x][y] = '.';
			if (x + 1 == '$') {
				puntos++;
				Z.eliminarMoneda(A, x + 1, y);
			}
			y = y + 1;
			A.map[x][y] = '@';
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


Player::Player()
{
	x = 0;
	y = 0;
}


Player::~Player()
{
}
