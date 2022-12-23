// SnakeGame.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>

#include "Head.h"
#include "Body.h"
#include <conio.h>

ConsoleGameScreen Screen;
int4 ScreenSize = { 5, 5 };

int main()
{
    LeckCheck();

    Part* StartPart = new Head();

    // Part* CurBody = new Body();
    Screen.ScreenInit(ScreenSize, L'��');

    Body::CreateBody(StartPart->GetPos());

    while (true)
    {
        GameEngineInput::ConsoleInputCheck();

        if (
            true == GameEngineInput::GetIsInput()
            && ('q' == GameEngineInput::GetKey() || 'Q' == GameEngineInput::GetKey())
            )
        {
            break;
        }

        system("cls");
        Screen.ScreenClear();

        //Body::GetCurBody()->Update();

       StartPart->Update();

       if (true == StartPart->RecursionCheckOver(StartPart->GetPos()))
       {
           printf("GameOver");
           break;
       } //���� �Ӹ��� �ε����� ���ӿ���

        StartPart->RecursionBackRender();

        Body::GetCurBody()->Render();

        // CurBody->Render();

        Screen.ScreenRender();
        Sleep(100);
    }

    if (nullptr != StartPart)
    {
        Body::deleteBody(); 
        delete StartPart;
        StartPart = nullptr;
    }

}
