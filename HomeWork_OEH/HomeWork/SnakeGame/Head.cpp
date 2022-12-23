#include "Head.h"
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include "Body.h"

#include <conio.h>

// 1. 새로운 몸통이 빈공간에만 생기게 만들어라.
// 2. 머리가 몸통에 닿으면 게임 오버가 되게 만들어라.
// 3. q를 눌러서 종료했을때 릭도 전부다 없애오세요

Head::Head()
	: Part(L'◆')
{
}

Head::~Head()
{
}


void Head::Update()
{

	if (true == GameEngineInput::GetIsInput())
	{
		int Input = GameEngineInput::GetKey();
		int4 NextPos = GetPos();

		switch (Input)
		{

		case 'a':
		case 'A':
			NextPos += {-1, 0};
			break;
		case 'd':
		case 'D':
		{
			NextPos += {1, 0 };
		}
		break;
		case 's':
		case 'S':
		{
			NextPos += { 0, 1 };
		}
		break;
		case 'w':
		case 'W':
		{
			NextPos += { 0, -1 };
		}
		break;
		case 'q':
		case 'Q':
			return;
		default:
			break;
		}

		bool IsMove = true;

		if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
		{
			IsMove = false;
		}

		if (true == IsMove)
		{			
			Part* LastPart = GetLastPart();
			int4 PrevPos = LastPart->GetPos();

			LastPart->RecursionFrontMove();

			SetPos(NextPos);


			if (GetPos() == Body::GetCurBody()->GetPos())
			{
				Body::GetCurBody()->SetPos(PrevPos);
				Body::GetCurBody()->SetRenderChar(L'●');
				LastPart->SetBack(Body::GetCurBody());
				Body::CreateBody(GetPos());
			}
		}
	}



}