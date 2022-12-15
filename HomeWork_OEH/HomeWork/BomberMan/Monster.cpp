#include "Monster.h"
#include "ConsoleGameScreen.h"

int Monster::NumOfMob = 0;

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::MobInit()
{
	for (int i = 0; i < NumOfMob; i++)
	{
		Mob[i].SetRenderChar(L'ขอ');
	}
}

void Monster::AddMob()
{
	++NumOfMob;
	Mob.ReSize(NumOfMob);

	MobInit();
}

void Monster::SetMob(int MobIndex, int4 _pos)
{
	Mob[MobIndex].SetPos(_pos);
}

void Monster::MobRender()
{
	for (int i = 0; i < NumOfMob; i++)
	{
		Mob[i].Render();
	}
}

void Monster::MobMoveLeftRight(int Mobindex)
{
	if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Mob[Mobindex].GetPos() + RightMove))
	{
		Mob[Mobindex].SetPos(Mob[Mobindex].GetPos() + RightMove);
	}
	else
	{
		RightMove *= -1;
	}
}

void Monster::MobMoveUpDown(int Mobindex)
{
	if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Mob[Mobindex].GetPos() + UpMove))
	{
		Mob[Mobindex].SetPos(Mob[Mobindex].GetPos() + UpMove);
	}
	else
	{
		UpMove *= -1;
	}
}