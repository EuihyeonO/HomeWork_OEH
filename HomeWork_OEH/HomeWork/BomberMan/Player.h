#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameScreen.h"
#include "ConsoleGameObject.h"


// Ό³Έν :
class Boom;
class obstacle;

class Player : public ConsoleGameObject
{
public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	bool Update(obstacle& obstacle);
	
	Boom** GetMyboom()
	{
		return myboom;
	}

	static int GetNumOfBoom()
	{
		return NumOfBoom;
	}

	static void SetNumOfBoom(int _value)
	{
		NumOfBoom += _value;
	}

	static int GetMaxNumOfBoom()
	{
		return MaxNumOfBoom;
	}

	static void SetMaxNumOfBoom(int _value)
	{
		MaxNumOfBoom += _value;
	}


	void deleteBoom();
	Boom* DropBoom();
	bool isThereMyBoom(const int4& pos);

protected:

private:
	static int NumOfBoom;
	static int MaxNumOfBoom;


	Boom** myboom;
};

