// Bomberman.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include "Boom.h"
#include "obstacle.h"
#include <iostream>
#include <conio.h>

ConsoleGameScreen Screen;
Player MainPlayer;
obstacle MapObstacle;

int main()
{
    LeckCheck();


    Screen.ScreenInit({ 15, 10 }, L'■');

    MapObstacle.SetObstacle({ 15,10 });

    bool Exit = false;

    while (true)
    {

        system("cls");

        Screen.ScreenClear();
        MapObstacle.RenderObstacle();

        Exit = MainPlayer.Update(MapObstacle);

        MainPlayer.deleteBoom();

        Screen.ScreenRender();

        if (Exit == true)
        {
            break;
        }

        Sleep(100);
    }    

    MapObstacle.deleteObstacle();

}
