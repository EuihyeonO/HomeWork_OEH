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


    Screen.ScreenInit({ 15, 10 }, L'■');
    int TimeStack = 0;

    Boom* boom[5];

    for (int i = 0; i < 5; i++)
    {
        boom[i] = nullptr;
    }


    while (true)
    {
        ++TimeStack;

        system("cls");

        Screen.ScreenClear();
        MainPlayer.Update(TimeStack, boom);


        for (int i = 0; i < 5; i++)
        {
            if (boom[i] != nullptr && TimeStack - (boom[i]->GetDropTime()) >= 50)
            {
                delete boom[i];
                boom[i] = nullptr;
            }
        }

        Screen.ScreenRender();
        Sleep(100);
    }    
    
    LeckCheck();

}
