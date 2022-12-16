// Bomberman.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Wall.h"
#include "GameEngineDebug.h"
#include "Monster.h"
#include <conio.h>

ConsoleGameScreen Screen;
Player MainPlayer;
Monster monster;

// 1. 몬스터를 1개 화면에 나오게 한다.
// 2. 몬스터a가 왼쪽으로 움직이다가 끝을 만나면 오른쪽으로 가게 만드세요.
// 3. 몬스터b를 만들고 위로 움직이다가 끝을 만나면 반대로 움직이기.

int4 ScreenSize = { 15, 11 };

int main()
{
    LeckCheck();

    Screen.ScreenInit(ScreenSize, L'■');

    monster.AddMob({3,0});
    monster.AddMob({0,4});
    monster.AddMob({5,6});

    Boom::BoomMapInit(ScreenSize);
    Wall::WallMapInit(ScreenSize);

    while (true)
    {

        system("cls");
  
        Screen.ScreenClear();

        Wall::WallUpdate();

        monster.MobMoveLeftRight(1);
        monster.MobMoveUpDown(2);
        monster.MobMoveLeftRight(3);  //간결하게 할 방법?

        monster.MobRender(); //3번째 몹은 왜 끝에 1칸을 안가지?

        bool End = MainPlayer.Update();

        Screen.ScreenRender();
    
        Sleep(500);
 

        Boom::MapClear();

        if (false == End)
        {
            printf_s("게임을 종료했습니다.");
            break;
        }
    }

}
