#include "Player.h"
#include "Boom.h"
#include <conio.h>
#include <ctime>

Player::Player()
{
	myboom = new Boom();
}

Player::~Player()
{
	delete myboom;
}

Boom* Player::Update(Boom* _boom, int _value)
{
	if (ConsoleGameScreen::GetMainScreen()->GetTileChar(Pos) != myboom->GetRenderChar())
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
	}

	int4 NextPos = Pos;
	Boom* boom = nullptr;

	if (_kbhit() == 0)
	{
		return _boom;
	}

	int input = _getch();

	switch (input)
	{
	case 'a':
	case 'A':
		NextPos += {-1, 0};
		break;

	case 'd':
	case 'D':
		NextPos += {1, 0};
		break;

	case 's':
	case 'S':
		NextPos += {0, 1};
		break;
	case 'w':
	case 'W':
		NextPos += {0, -1};
		break;
	case 'f':
	case 'F':
		boom = myboom->DropBoom(GetPos(), _value);
		break;
	default:
		break;
	}


	if (ConsoleGameScreen::GetMainScreen()->IsOver(NextPos) == 0 && ConsoleGameScreen::GetMainScreen()->isthereBoom(NextPos) == 0)
	{
		Pos = NextPos;
	}

	if (boom != nullptr)
		return boom;
	else return _boom;
}

