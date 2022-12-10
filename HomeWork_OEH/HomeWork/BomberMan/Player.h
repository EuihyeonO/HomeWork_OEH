#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameScreen.h"


// ¼³¸í :
class Boom;

class Player
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	int4 GetPos()
	{
		return Pos;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}

	Boom* Update(Boom* _boom, int _value);
	
	Boom* GetMyboom()
	{
		return myboom;
	}

protected:

private:
	int4 Pos = { 0, 0 };
	wchar_t RenderChar = L'¡Ú';

	Boom* myboom;
};

