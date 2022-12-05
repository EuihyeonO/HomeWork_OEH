#pragma once
#include "ShootingMap.h"
#include "Bullet.h"

class Player
{
public:
	// �ٲٱ� ���� ���
	void SetPos(const Int4& _Pos)
	{
		Pos = _Pos;
	}

	void Move(const Int4& _Dir, ShootingMap& _map);

	// �ܺο� �˷��ֱ⸸ �ϴ� ����� ��Ȯ�ϰ� ����
	Int4 GetPos()
	{
		return Pos;
	}

	char GetDisplayChar()
	{
		return DisplayChar;
	}

	void Update(ShootingMap& _map, Bullet& _bullet, Monster& _monster);

	void ShootBullet(Monster& _monster, Int4 Pos, ShootingMap& _map, Bullet& _bullet);
private:
	char DisplayChar = '*';
	Int4 Pos;
};
