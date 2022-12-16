
#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "player.h"
#include "Wall.h"
#include "Monster.h"
#include <Windows.h>

GameEngineArray<GameEngineArray<Boom*>> Boom::BoomMap;

/*static */void Boom::BoomMapInit(int4 _Size)
{
	BoomMap.ReSize(_Size.Y);

	for (size_t y = 0; y < BoomMap.GetCount(); y++)
	{
		BoomMap[y].ReSize(_Size.X);
		for (size_t x = 0; x < BoomMap[y].GetCount(); x++)
		{
			BoomMap[y][x] = nullptr;
		}
	}
}

/*static */Boom* Boom::GetBoom(int4 _Size)
{
	return BoomMap[_Size.Y][_Size.X];
}


Boom::Boom()
{
	SetRenderChar(L'¡Ý');
}

Boom::~Boom()
{

}

void Boom::MapClear()
{
	for (int y = 0; y < BoomMap.GetCount(); y++)
	{
		for (int x = 0; x < BoomMap[y].GetCount(); x++)
		{
			if (BoomMap[y][x] != nullptr && true == BoomMap[y][x]->IsDeath())
			{
				BoomMap[y][x] = nullptr;
			}
		}
	}
}

void Boom::Update()
{
	if (CurRange >= Range)
	{
		return;
	}


	int4 BoomPos = GetPos();

	BoomMap[BoomPos.Y][BoomPos.X] = this;

	if (0 > --Time)
	{
		++CurRange;
		// return;
	}

	// ÆøÅº ±×ÀÚÃ¼´Â ±×³É Ãâ·Â
	int4 Pos = GetPos();
	wchar_t MyChar = GetRenderChar();
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(Pos, MyChar);

	bool LeftWall = false;
	bool RightWall = false;
	bool UpWall = false;
	bool DownWall = false;

	for (int i = 1; i <= CurRange; i++)
	{
		int4 Left = Pos + int4{ -i, 0 };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Left) && true == Wall::GetIsWall(Left))
		{
			LeftWall = true;
		}

		if (false == LeftWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Left))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Left, L'¡ß');
			Monster::killmonster(Left);

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Left) && GetBoom(Left) != nullptr)
			{
				GetBoom(Left)->BoomByFire();
			}
		}

		int4 Right = Pos + int4{ i, 0 };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Right) && true == Wall::GetIsWall(Right))
		{
			RightWall = true;
		}


		if (false == RightWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Right))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Right, L'¡ß');
			Monster::killmonster(Right);

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Right) && GetBoom(Right) != nullptr)
			{
				GetBoom(Right)->BoomByFire();
			}
		}

		int4 Up = Pos + int4{ 0, i };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Up) && true == Wall::GetIsWall(Up))
		{
			UpWall = true;
		}
		if (false == UpWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Up))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Up, L'¡ß');
			Monster::killmonster(Up);

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Up) && GetBoom(Up) != nullptr)
			{
				GetBoom(Up)->BoomByFire();
			}
		}

		int4 Down = Pos + int4{ 0, -i };

		if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Down) && true == Wall::GetIsWall(Down))
		{
			DownWall = true;
		}

		if (false == DownWall && false == ConsoleGameScreen::GetMainScreen()->IsOver(Down))
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(Down, L'¡ß');
			Monster::killmonster(Down);

			if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Down) && GetBoom(Down) != nullptr)
			{
				GetBoom(Down)->BoomByFire();
			}
		}
	}
}


