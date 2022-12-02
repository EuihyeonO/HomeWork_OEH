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


void ShootingMap::Render()
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