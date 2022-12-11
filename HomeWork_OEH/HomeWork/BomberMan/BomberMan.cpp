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
    int TimeCount = 0;

    Boom* boom[5];

    for (int i = 0; i < 5; i++)
    {
        boom[i] = nullptr;
    }

    while (true)
    {
        ++TimeCount;

        system("cls");

        Screen.ScreenClear();
        MainPlayer.Update(TimeCount, boom);
        
        (*boom)->deleteBoom(boom, TimeCount);

        Screen.ScreenRender();
        Sleep(100);
    }    
    
    LeckCheck();

}
