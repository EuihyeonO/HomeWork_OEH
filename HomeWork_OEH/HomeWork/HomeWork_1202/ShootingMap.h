#pragma once
#include "ContentsMath.h"

class ShootingMap
{
public:
	void Render();
	void Init(const char _BaseChar);
	void SetTile(const Int4& _Pos, char _Char);
	char GetTileChar(int x, int y)
	{
		return ArrTile[y][x];
	}

private:
	char ArrTile[30][31];

};

