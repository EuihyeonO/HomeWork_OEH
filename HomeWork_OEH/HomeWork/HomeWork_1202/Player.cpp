#include "player.h"
#include <conio.h>
#include <Windows.h>



void Player::Move(const Int4& _Dir, ShootingMap& _map)
{
	
	{
		_map.SetTile(Pos, 'o');
	}

	Pos += _Dir;
}
void Player::ShootBullet(Monster& _monster, Int4 Pos, ShootingMap& _map, Bullet& _bullet)
{
	if (0 == _kbhit())
	{
		return;
	}

	int Input1 = _getch();

	if (Input1 == 224)
	{
		int Input2 = _getch();
		_bullet.BulletMove(_monster, Pos, _map, Input2);
	}


}


void Player::Update(ShootingMap& _map, Bullet& _bullet, Monster& _monster)
{


	if (0 == _kbhit())
	{
		return;
	}

	int Input = _getch();
	int input2 = 0;

	switch (Input)
	{
	case 'a':
	case 'A':
		if (_map.IsAbleToMoveLeft(Pos) == true) 
		{
			Move({ -1, 0 }, _map);
		}
		break;
	case 'd':
	case 'D':
		if (_map.IsAbleToMoveRight(Pos) == true)
		{
			Move({ 1, 0 }, _map);
		}
		break;
	case 's':
	case 'S':
		if (_map.IsAbleToMoveDown(Pos) == true)
		{
			Move({ 0, 1 }, _map);
		}
		break;
	case 'w':
	case 'W':
		if (_map.IsAbleToMoveUp(Pos) == true)
		{
			Move({ 0, -1 }, _map);
		}
		break;
	case 224:
		input2 = _getch();
		_bullet.BulletMove(_monster, Pos, _map, input2);
		break;
	default:
		break;
	}
}