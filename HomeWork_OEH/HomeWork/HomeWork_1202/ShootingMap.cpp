#include "ShootingMap.h"
#include <iostream>


void ShootingMap::Init(const char _Char)
{
	for (unsigned int y = 0; y < 30; ++y)
	{
		for (unsigned int x = 0; x < 30; ++x)
		{
			ArrTile[y][x] = _Char;
		}
		ArrTile[y][30] = 0;
	}
}


void ShootingMap::1Render()
{
	for (unsigned int y = 0; y < 30; ++y)
	{
		const char* Ptr = ArrTile[y];
		printf_s(Ptr);
		printf_s("\n");
	}
}

void ShootingMap::SetTile(const Int4& _Pos, char _Char)
{
	ArrTile[_Pos.Y][_Pos.X] = _Char;
}

bool ShootingMap::IsAbleToMoveRight(Int4& pos)
{
	if (pos.X >= 29)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool ShootingMap::IsAbleToMoveLeft(Int4& pos)
{
	if (pos.X <= 0)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool ShootingMap::IsAbleToMoveUp(Int4& pos)
{
	if (pos.Y <= 1)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool ShootingMap::IsAbleToMoveDown(Int4& pos)
{
	if (pos.Y >= 29)
	{
		return false;
	}

	else
	{
		return true;
	}
}
