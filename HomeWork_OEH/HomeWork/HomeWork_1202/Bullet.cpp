#include "Bullet.h"
#include <Windows.h> 

void Bullet::BulletMove(Monster& _Monster, Int4 _pos, ShootingMap& _map, int _input)
{
	PosInit(_pos);

	if (_input == 75 && _map.IsAbleToMoveLeft(Pos))
	{
		SetPos(-1,0);
		_map.SetTile(Pos, GetDisplayChar());
		while (_map.IsAbleToMoveLeft(Pos))
		{
			if (Pos == _Monster.GetPos())
			{
				break;
			}

			_map.SetTile(Pos, 'o');
			SetPos(-1, 0);
			_map.SetTile(Pos, GetDisplayChar());
		}
		_map.SetTile(Pos, 'o');
	}

	else if (_input == 77 && _map.IsAbleToMoveRight(Pos))
	{
		SetPos(1, 0);
		_map.SetTile(Pos, GetDisplayChar());
		while (_map.IsAbleToMoveRight(Pos))
		{
			if (Pos == _Monster.GetPos())
			{
				break;
			}

			_map.SetTile(Pos, 'o');
			SetPos(1, 0);
			_map.SetTile(Pos, GetDisplayChar());
		}
		_map.SetTile(Pos, 'o');
	}

	else if (_input == 80 && _map.IsAbleToMoveDown(Pos))
	{
		SetPos(0,1);
		_map.SetTile(Pos, GetDisplayChar());
		while (_map.IsAbleToMoveDown(Pos))
		{
			if (Pos == _Monster.GetPos())
			{
				_Monster.DeadByBullet(_map, Pos);
				break;
			}

			_map.SetTile(Pos, 'o');
			SetPos(0, 1);
			_map.SetTile(Pos, GetDisplayChar());
		}
		_map.SetTile(Pos, 'o');
	}

	else if (_input == 72 && _map.IsAbleToMoveUp(Pos))
	{
		SetPos(0,- 1);
		_map.SetTile(Pos, GetDisplayChar());
		while (_map.IsAbleToMoveUp(Pos))
		{
			if (Pos == _Monster.GetPos())
			{
				break;
			}

			_map.SetTile(Pos, 'o');
			SetPos(0, -1);
			_map.SetTile(Pos, GetDisplayChar());
		}
		_map.SetTile(Pos, 'o');
	}

	else return;
}

void Bullet::PosInit(Int4& _Pos)
{
	Pos.X = _Pos.X;
	Pos.Y = _Pos.Y;
}