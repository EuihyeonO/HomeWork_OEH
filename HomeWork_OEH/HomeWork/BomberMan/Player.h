#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameScreen.h"


// ���� :
class Boom;

class Player
{
public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void Update(int _value, Boom* _arr[]);

	int4 GetPos()
	{
		return Pos;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}
	
	Boom* GetMyboom()
	{
		return myboom;
	}

protected:

private:
	int4 Pos = { 0, 0 };
	wchar_t RenderChar = L'��';

	Boom* myboom;
};

