#pragma once
#include "ContentsMath.h"
#include "ShootingMap.h"

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

	bool IsAbleToMoveRight(Int4& pos);
	bool IsAbleToMoveLeft(Int4& pos);
	bool IsAbleToMoveUp(Int4& pos);
	bool IsAbleToMoveDown(Int4& pos);

	void Update(ShootingMap& _map);

private:
	char DisplayChar = '*';
	Int4 Pos;
};
