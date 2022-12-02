#include "Player.h"
#include "ShootingMap.h"
#include <conio.h>

bool Player::IsAbleToMoveRight(Int4& pos)
{
	if (pos.X >= 30)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool Player::IsAbleToMoveLeft(Int4& pos)
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

bool Player::IsAbleToMoveUp(Int4& pos)
{
	if (pos.Y <= 0)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool Player::IsAbleToMoveDown(Int4& pos)
{
	if (pos.Y >= 30)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void Player::Move(const Int4& _Dir, ShootingMap& _map)
{
	
	{
		_map.SetTile(Pos, 'o');
	}

	Pos += _Dir;
}

void Player::Update(ShootingMap& _map)
{


	if (0 == _kbhit())
	{
		return;
	}

	int Input = _getch();


	switch (Input)
	{
	case 'a':
	case 'A':
		if (IsAbleToMoveLeft(Pos) == true) 
		{
			Move({ -1, 0 }, _map);
		}
		break;
	case 'd':
	case 'D':
		if (IsAbleToMoveRight(Pos) == true)
		{
			Move({ 1, 0 }, _map);
		}
		break;
	case 's':
	case 'S':
		if (IsAbleToMoveDown(Pos) == true)
		{
			Move({ 0, 1 }, _map);
		}
		break;
	case 'w':
	case 'W':
		if (IsAbleToMoveUp(Pos) == true)
		{
			Move({ 0, -1 }, _map);
		}
		break;
	default:
		break;
	}
}