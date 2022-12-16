#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameMath.h"
#include <GameEngineArray.h>

class Monster : public ConsoleGameObject
{

public:

	Monster();
	~Monster();

	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;

	Monster& operator=(const Monster& _Other)
	{
		return *this;
	}

	Monster& operator=(Monster&& _Other) noexcept = delete;

	void MobMoveLeftRight(int Mobindex);

	void MobMoveUpDown(int Mobindex);

	void AddMob();

	static int GetNumOfMob()
	{
		return NumOfMob;
	}

	void MobInit();

	void SetMob(int MobIndex, int4 _pos);

	void MobRender();

protected:

private:
	GameEngineArray<Monster> Mob; //static 으로 선언하면, 관리가 좀 더 쉬워질듯?
	static int NumOfMob;
	int4 RightMove = {1,0};
	int4 UpMove = {0,1};
};

