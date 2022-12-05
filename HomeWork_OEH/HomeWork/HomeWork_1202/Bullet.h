#pragma once
#include "Monster.h"

class Bullet
{
public:
	void BulletMove(Monster& _Monster, Int4 _pos, ShootingMap& _map, int _input);
	void PosInit(Int4& _pos);

	Int4& GetPos()
	{
		return Pos;
	}

	void SetPos(int x, int y)
	{
		Pos.X += x;
		Pos.Y += y;
	}

	char GetDisplayChar()
	{
		return DisplayChar;
	}

private:
	char DisplayChar = '@';
	Int4 Pos;
};

