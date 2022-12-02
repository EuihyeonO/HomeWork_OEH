#pragma once
#include "ContentsMath.h"
#include "ShootingMap.h"

class Player
{
public:
	// 바꾸기 위한 기능
	void SetPos(const Int4& _Pos)
	{
		Pos = _Pos;
	}

	void Move(const Int4& _Dir, ShootingMap& _map);

	// 외부에 알려주기만 하는 기능을 명확하게 구분
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
