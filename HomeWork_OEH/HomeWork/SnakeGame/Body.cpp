#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

Body* Body::CurBody[100] = { 0, };
int Body::NumOfCurBody = 0;

void Body::CreateBody(int4 _pos)
{
	srand(time(nullptr));

	CurBody[NumOfCurBody] = new Body; //릭을 없애기 위해 배열형으로 선언하여, 인덱스당 하나씩 동적할당

	int4 BodyPos = { rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X, rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };

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
			} //모든 바디의 위치를 전부 다 탐색했을 시 반복문 종료

			if (BodyPos == CurBody[i]->GetPos() || BodyPos == _pos)
			{
				isSame = true;
				break;
			} //같은 위치의 바디가 있다면 IsSame을 true로 값을 변경한 뒤 반복문 종료

			++i;

		}

		if (isSame == false)
		{
			break;
		} //모든 위치를 탐색 후, 같은 위치에 있는 바디가 없다면, 반복문 종료

		BodyPos = { rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X, rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };
		//바디와 동일한 위치에 새로운 바디가 생성될시 BodyPos 의 위치를 다시 랜덤으로 찍어낸 후 반복문 계속 실행
	}

	CurBody[NumOfCurBody]->SetPos(BodyPos); //겹치는 곳이 없는 것이 확인된 BodyPos에 새로운 바디 생성

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
