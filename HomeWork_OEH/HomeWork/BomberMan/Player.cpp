#include "Player.h"
#include "Boom.h"
#include "obstacle.h"
#include <conio.h>
#include <ctime>

int Player::NumOfBoom = 0;
int Player::MaxNumOfBoom = 10;

Player::Player()
{
	SetRenderChar(L'¡Ú');

	myboom = new Boom*[MaxNumOfBoom];

	for (int i = 0; i < MaxNumOfBoom; i++)
	{
		myboom[i] = nullptr;
	}
}

Player::~Player()
{
	for (int i = 0; i < MaxNumOfBoom; i++)
	{
		delete myboom[i];
		myboom[i] = nullptr;
	};

	delete[] myboom;
}

Boom* Player::DropBoom()
{
	if (Player::GetNumOfBoom() >= 11)
	{
		return nullptr;
	}

	Boom* _boom = new Boom;

	_boom->SetPos(GetPos());
	_boom->GetBoomFire()->SetPos(GetPos());

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(_boom->GetPos(), _boom->GetRenderChar());
	return _boom;
}

void Player::deleteBoom()
{
	for (int i = 0; i < MaxNumOfBoom; i++)
	{
		if (myboom[i] == nullptr)
		{
			continue;
		}

		myboom[i]->Explode();

		for (int j = 0; j < MaxNumOfBoom; j++)
		{
			if (i == j || myboom[j]==nullptr)
			{
				continue;
			}
			
			if(myboom[i]->GetBoomFire()->isThereBoom(myboom[j]->GetPos()) //ºÒ²ÉÀÌ ÆøÅº°ú ¸¸³ª°í
				&& myboom[j]->GetBombTime() > myboom[j]->GetRange()) // ±× ÆøÅºÀÌ ¾ÆÁ÷ ÅÍÁöÁö ¾Ê¾Ò´Ù¸é
			{
				myboom[j]->SetBombTime(myboom[j]->GetRange()); //ÆøÅºÀ» Áï½Ã Æø¹ßÇÏ°Ô ¸¸µë
			}
		}

		if (myboom[i]->GetBombTime() == 0)
		{
			delete myboom[i];
			myboom[i] = nullptr;
		}	
	}
}

bool Player::isThereMyBoom(const int4& pos)
{
	for (int i = 0; i < GetMaxNumOfBoom(); i++)
	{
		if (myboom[i] == nullptr)
		{
			continue;
		}
		else if (myboom[i]->GetPos() == pos)
		{
			return true;
		}
	}

	return false;
}

bool Player::Update(obstacle& obstacle)
{
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	for (int i = 0; i < Player::GetMaxNumOfBoom(); i++)
	{
		if (myboom[i] != nullptr)
		{
			ConsoleGameScreen::GetMainScreen()->SetPixelChar(myboom[i]->GetPos(), myboom[i]->GetRenderChar());
			myboom[i]->BombTimeCount();
		}
	}


	if (_kbhit() == 0)
	{
		return false;
	}

	int4 NextPos = GetPos();

	int input = _getch();

	switch (input)
	{
	case 'a':
	case 'A':
		NextPos += {-1, 0};
		break;

	case 'd':
	case 'D':
		NextPos += {1, 0};
		break;

	case 's':
	case 'S':
		NextPos += {0, 1};
		break;

	case 'w':
	case 'W':
		NextPos += {0, -1};
		break;

	case 'f':
	case 'F':

		for (int i = 0; i < Player::GetMaxNumOfBoom(); i++)
		{
			if (myboom[i] == nullptr)
			{
				myboom[i] = DropBoom();
				break;
			}
		}
		break;
	case 'q':
	case 'Q':
		return true;
	default:
		break;
	}


	if (ConsoleGameScreen::GetMainScreen()->IsOver(NextPos) == 0 
		&& isThereMyBoom(NextPos) == 0 
		&& obstacle.isThereObstacle(NextPos) == 0)
	{
		SetPos(NextPos);
	}

		return false;



}

