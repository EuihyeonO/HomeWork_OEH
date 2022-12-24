#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

Body* Body::CurBody[100] = { 0, };
int Body::NumOfCurBody = 0;

void Body::CreateBody(int4 _pos)
{
	srand(time(nullptr));

	CurBody[NumOfCurBody] = new Body; //���� ���ֱ� ���� �迭������ �����Ͽ�, �ε����� �ϳ��� �����Ҵ�

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
			} //��� �ٵ��� ��ġ�� ���� �� Ž������ �� �ݺ��� ����

			if (BodyPos == CurBody[i]->GetPos() || BodyPos == _pos)
			{
				isSame = true;
				break;
			} //���� ��ġ�� �ٵ� �ִٸ� IsSame�� true�� ���� ������ �� �ݺ��� ����

			++i;

		}

		if (isSame == false)
		{
			break;
		} //��� ��ġ�� Ž�� ��, ���� ��ġ�� �ִ� �ٵ� ���ٸ�, �ݺ��� ����

		BodyPos = { rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X, rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y };
		//�ٵ�� ������ ��ġ�� ���ο� �ٵ� �����ɽ� BodyPos �� ��ġ�� �ٽ� �������� �� �� �ݺ��� ��� ����
	}

	CurBody[NumOfCurBody]->SetPos(BodyPos); //��ġ�� ���� ���� ���� Ȯ�ε� BodyPos�� ���ο� �ٵ� ����

	++NumOfCurBody;
}

Body* Body::GetCurBody()
{
	return CurBody[NumOfCurBody-1];
}

Body::Body()
	: Part(L'��')
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
	// ���߿� �� ������ Ǯ��� �� ���ɼ��� ����.
	if (true == GameEngineInput::GetIsInput())
	{
		if (nullptr == GetFront())
		{
			return;
		}

		SetPos(GetFront()->GetPos());
	}
}
