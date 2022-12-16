#include "Monster.h"
#include "ConsoleGameScreen.h"

int Monster::NumOfMob = 0;
GameEngineArray<Monster> Monster::Mob;
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
		Mob[i].SetRenderChar(L'��');
		Mob[i].MobIndex = i;
	}
}

void Monster::AddMob(int4 pos)
{
	int4* CopyPos = new int4[NumOfMob];

	for (int i = 0; i < NumOfMob; i++) //Resize�� �ϸ�, �⺻ �����Ͱ� ������� ������ ������ �����Լ� �߰� ( �ٵ� �� �����Ͱ� �������? )
	{
		CopyPos[i] = Mob[i].GetPos();
	}

	++NumOfMob;

	Mob.ReSize(NumOfMob);

	for (int i = 0; i < NumOfMob-1; i++)
	{
		Mob[i].SetPos(CopyPos[i]);
	}

	MobInit();

	SetMob(NumOfMob, pos);
}

void Monster::SetMob(int MobNumber, int4 _pos)
{
	Mob[MobNumber-1].SetPos(_pos);
}

void Monster::MobRender()
{
	for (int i = 0; i < NumOfMob; i++)
	{
		Mob[i].Render();
	}
}

void Monster::MobMoveLeftRight(int MobNumber)
{
	if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Mob[MobNumber-1].GetPos() + Mob[MobNumber - 1].RightMove)
		/* && false == isThereMob(Mob[MobNumber - 1].GetPos() + Mob[MobNumber - 1].RightMove)*/)
	{
		Mob[MobNumber-1].SetPos(Mob[MobNumber-1].GetPos() + Mob[MobNumber - 1].RightMove);
	}
	else
	{
		Mob[MobNumber - 1].RightMove *= -1;
	}
}

void Monster::MobMoveUpDown(int MobNumber)
{
	if (false == ConsoleGameScreen::GetMainScreen()->IsOver(Mob[MobNumber-1].GetPos() + Mob[MobNumber - 1].UpMove)
		/* && false == isThereMob(Mob[MobNumber - 1].GetPos() + Mob[MobNumber - 1].UpMove) */ )
	{
		Mob[MobNumber-1].SetPos(Mob[MobNumber-1].GetPos() + Mob[MobNumber - 1].UpMove);
	}

	else
	{
		Mob[MobNumber - 1].UpMove *= -1;
	}
}

bool Monster::isThereMob(int4 pos)
{
	for (int i = 0; i < NumOfMob; i++)
	{
		if (pos == Mob[i].GetPos())
		{
			return true;
		}
	}

	return false;
}