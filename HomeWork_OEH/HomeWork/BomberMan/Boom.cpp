#include "Boom.h"
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <ctime>
#include <conio.h>

void BoomFire::Flowfire()
{

	upfire += {0, -1};
	downfire += {0, 1};
	leftfire += {-1, 0};
	rightfire += {1, 0};

	if (ConsoleGameScreen::GetMainScreen()->IsOver(upfire) == false && (upfire.X%2!=1 || upfire.Y%2!=1)) 
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(upfire, GetRenderChar());
	}
	else if (upfire.X % 2 == 1 || upfire.Y % 2 == 1)
	{
		upfire += {0, 1};
	}

	if (ConsoleGameScreen::GetMainScreen()->IsOver(downfire) == false && (downfire.X % 2 != 1 || downfire.Y % 2 != 1))
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(downfire, GetRenderChar());
	}
	else if (downfire.X % 2 == 1 || downfire.Y % 2 == 1)
	{
		downfire += {0, -1};
	}

	if (ConsoleGameScreen::GetMainScreen()->IsOver(leftfire) == false && (leftfire.X % 2 != 1 || leftfire.Y % 2 != 1))
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(leftfire, GetRenderChar());
	}
	else if (leftfire.X % 2 == 1 || leftfire.Y % 2 == 1)
	{
		leftfire += {1, 0};
	}

	if (ConsoleGameScreen::GetMainScreen()->IsOver(rightfire) == false && (rightfire.X % 2 != 1 || rightfire.Y % 2 != 1))
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(rightfire, GetRenderChar());
	}
	else if (rightfire.X % 2 == 1 || rightfire.Y % 2 == 1)
	{
		rightfire += {-1, 0};
	}
}

Boom::Boom()
{
	SetRenderChar(L'¡Ø');
	Player::SetNumOfBoom(1);

	boomfire = new BoomFire();

	boomfire->SetRenderChar(L'¡Ø');
}

Boom::~Boom()
{
	Player::SetNumOfBoom(-1);
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), L'¡á');

	if (boomfire != nullptr)
	{
		delete boomfire;
		boomfire = nullptr;
	}

}

void Boom::BombTimeCount()
{
	--bombtime;
}

void Boom::Explode()
{
	if (bombtime == 0)
	{
		return;
	}

	if (bombtime <= range) 
	{
		GetBoomFire()->SetPos(GetPos());

		for (int i = 0; i < range - bombtime + 1; i++)
		{
		GetBoomFire()->Flowfire();
		}
	}
}