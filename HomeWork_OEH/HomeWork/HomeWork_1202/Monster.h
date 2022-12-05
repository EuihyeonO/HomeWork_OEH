#pragma once
#include "ShootingMap.h"

class Monster
{
public:

	void DeadByBullet(ShootingMap& _map, Int4& _pos);

	void SetPos(const Int4& _pos)
	{
		Pos = _pos;
	}

	Int4 GetPos()
	{
		return Pos;
	}

	char GetDisplayChar()
	{
		return DisplayChar;
	}

private:
	char DisplayChar = 'X';
	Int4 Pos;
};

