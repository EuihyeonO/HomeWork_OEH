#include "Player.h"
#include <conio.h>

Player::Player()
{
}

Player::~Player()
{
}

void Player::Move(ConsoleGameScreen& _screen)
{
	if (_kbhit() == 0)
	{
		return;
	}

	int input = _getch();

	switch (input)
	{
	case 'a':
	case 'A':
		if (_screen.IsOver(Pos) == 0)
		{
			Pos += {-1, 0};
		}
		break;

	case 'd':
	case 'D':
		if (_screen.IsOver(Pos) == 0)
		{
			Pos += {1, 0};
		}
		break;

	case 's':
	case 'S':
		if (_screen.IsOver(Pos) == 0)
		{
			Pos += {0, 1};
		}
		break;
	case 'w':
	case 'W':
		if (_screen.IsOver(Pos) == 0)
		{
			Pos += {0, -1};
		}
		break;
	default:
		break;
	}
}

