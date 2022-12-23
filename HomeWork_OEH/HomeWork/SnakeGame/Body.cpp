#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

Body* Body::CurBody[100] = { 0, };
int Body::NumOfCurBody = 0;

void Body::CreateBody(int4 _pos)
{
	srand(time(nullptr));

	CurBody[NumOfCurBody] = new Body;

	int4 BodyPos = { rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X, rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };
	
	while(BodyPos == _pos)
	{
		BodyPos = { rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X, rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };
	}

	int i = 0;
	bool isSame = false;

	while (true)
	{
		i = 0;
		isSame = false;

		while (true)
		{
			if (i == NumOfCurBody)
			{
				break;
			}

			if (BodyPos == CurBody[i]->GetPos())
			{
				isSame = true;
				break;
			}
			++i;
		}

		if (isSame == false)
		{
			break;
		}

		BodyPos = { rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X, rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };
	}

	CurBody[NumOfCurBody]->SetPos(BodyPos);

	++NumOfCurBody;
}

Body* Body::GetCurBody()
{
	return CurBody[NumOfCurBody-1];
}

Body::Body()
	: Part(L'★')
{
}

Body::~Body()
{
}

void Body::deleteBody()
{
	for (int i = 0; i < NumOfCurBody; i++)
	{
		delete CurBody[i];
	}
}

void Body::Update()
{
	// 나중에 이 제한을 풀어야 할 가능성이 높다.
	if (true == GameEngineInput::GetIsInput())
	{
		if (nullptr == GetFront())
		{
			return;
		}

		SetPos(GetFront()->GetPos());
	}
}
