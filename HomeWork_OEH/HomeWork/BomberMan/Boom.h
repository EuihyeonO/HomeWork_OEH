#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

class Player;
class ConsoleGameScreen;

class BoomFire
{
public:

	bool isThereBoom(int4 pos)
	{
		if (upfire == pos)
		{
			return true;
		}
		if (downfire == pos)
		{
			return true;
		}
		if (leftfire == pos)
		{
			return true;
		}
		if (rightfire == pos)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	void SetPos(int4 pos)
	{
		upfire = pos;
		downfire = pos;
		leftfire = pos;
		rightfire = pos;
	}

	wchar_t GetRenderChar() 
	{
		return RenderChar;
	}

	void SetRenderChar(wchar_t _value)
	{
		RenderChar = _value;
	}

	void Flowfire();


private:
	int4 upfire = {0,0};
	int4 downfire = {0,0};
	int4 leftfire = {0,0};
	int4 rightfire = {0,0};

	wchar_t RenderChar = L'¡Ø';
};



// Boom Å¬·¡½º
class Boom : public ConsoleGameObject
{
public:

	Boom();
	~Boom();

	Boom(const Boom& _Other) = delete;
	Boom(Boom&& _Other) noexcept = delete;
	Boom& operator=(const Boom& _Other) = delete;
	Boom& operator=(Boom&& _Other) noexcept = delete;
	
	int GetBombTime()
	{
		return bombtime;
	}

	void SetBombTime(int _value)
	{
		bombtime = _value;
	}

	void BombTimeCount();

	int GetRange()
	{
		return range;
	}

	BoomFire* GetBoomFire()
	{
		return boomfire;
	}

	void Explode();

protected:

private:

	int bombtime = 50;
	int range = 4;
	BoomFire* boomfire;
};

