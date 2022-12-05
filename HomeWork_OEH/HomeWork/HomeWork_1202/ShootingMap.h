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
	bool IsAbleToMoveRight(Int4& pos);
	bool IsAbleToMoveLeft(Int4& pos);
	bool IsAbleToMoveUp(Int4& pos);
	bool IsAbleToMoveDown(Int4& pos);

private:
	char ArrTile[30][31];

};

