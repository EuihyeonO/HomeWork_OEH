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

void Player::Update(int _value, Boom* _arr[])
{
	if (ConsoleGameScreen::GetMainScreen()->GetTileChar(Pos) != myboom->GetRenderChar())
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
	}

	int4 NextPos = Pos;
	Boom* boom = nullptr;

	if (_kbhit() == 0)
	{
		return;
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

		for (int i = 0; i < 5; i++)
		{
			if (_arr[i] == nullptr) 
			{
				_arr[i] = myboom->DropBoom(GetPos(), _value);
				break;
			}
		}
		return;

	default:
		break;
	}


	if (ConsoleGameScreen::GetMainScreen()->IsOver(NextPos) == 0 && ConsoleGameScreen::GetMainScreen()->isthereBoom(NextPos) == 0)
	{
		Pos = NextPos;
	}

		return;

}

