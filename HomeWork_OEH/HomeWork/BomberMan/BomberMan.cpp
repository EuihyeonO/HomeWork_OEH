// Bomberman.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include <conio.h>
#include "Boom.h"

ConsoleGameScreen Screen;
Player MainPlayer;

int main()
{

    // 지역변수로 만들어졌어.
    Screen.ScreenInit({ 15, 10 }, L'■');
    int TimeStack = 0;

    Boom* boom = nullptr;

    // 정상종료를 시켜줘야 하는데.
    while (true)
    {
        ++TimeStack;

        system("cls");
        Screen.ScreenClear();

        boom = MainPlayer.Update(boom, TimeStack);

        if (boom != nullptr && TimeStack - boom->GetDropTime() >= 30)
        {
            delete boom;
            boom = nullptr;
        }

        Screen.ScreenRender();
        Sleep(100);
    }    
    
    LeckCheck();

}
