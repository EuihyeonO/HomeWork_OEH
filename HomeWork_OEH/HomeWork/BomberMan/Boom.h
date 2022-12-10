#pragma once
#include "ConsoleGameMath.h"

class Player;

class Boom
{

public:

	Boom();
	~Boom();

	int4 GetPos()
	{
		return Pos;
	}

	void SetPos(int4 _pos)
	{
		Pos += _pos;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}
	Boom* DropBoom(int4 _pos, int _value);

	Boom(const Boom& _Other) = delete;
	Boom(Boom&& _Other) noexcept = delete;
	Boom& operator=(const Boom& _Other) = delete;
	Boom& operator=(Boom&& _Other) noexcept = delete;

	static int GetNumOfBoom()
	{
		return NumOfBoom;
	}
	
	void SetTimeStack(int _value)
	{
		DropTime = _value;
	}

	int GetDropTime()
	{
		return DropTime;
	}

	Boom* Boomtimer(Player& _player, Boom* _boom, int timestack);

protected:

private:
	static int NumOfBoom;

	int4 Pos;
	int DropTime;

	wchar_t RenderChar = L'¢Â';
};

