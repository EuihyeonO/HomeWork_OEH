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

	void MobMoveLeftRight(int MobNumber);

	void MobMoveUpDown(int MobNumber);

	void AddMob(int4 pos);

	static int GetNumOfMob()
	{
		return NumOfMob;
	}

	void MobInit();

	void SetMob(int MobNumber, int4 _pos);

	void MobRender();

	static bool isThereMob(int4 pos);

protected:

private:
	static GameEngineArray<Monster> Mob; 
	static int NumOfMob;

	int MobIndex = 0;

	int4 RightMove = {1,0};
	int4 UpMove = {0,1};
};

