// 숙제 1. 화면 바깥으로 못나가게 만드세요. (완)
// 숙제 2. 잔상 지우세요. (완)

// 이건 안해도 됩니다.
// 이것도 다했다.
// 숙제 3. 몬스터를 1마리 만드세요.
// 숙제 4. 총알을 1개 만드세요
// 숙제 5. 총알이 몬스터를 만나면 둘다 사라지게 하세요.

#include <iostream>
#include "ShootingMap.h"
#include "Player.h"
#include <Windows.h>
#include "Monster.h"

int main()
{
    ShootingMap NewMap;
    Player NewPlayer;
    Monster NewMonster;
    Bullet NewBullet;

    NewPlayer.SetPos({ 2, 2 });
    NewMonster.SetPos({ 9, 2 });
 

    NewMap.Init('o');
    NewMap.SetTile(NewMonster.GetPos(), NewMonster.GetDisplayChar());

    while (true)
    {
        system("cls");

        // 움직이고
        NewPlayer.Update(NewMap, NewBullet,NewMonster);

        // 적용하고.
        NewMap.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

        // 그려진다.
        NewMap.Render();
        // 1000 이
        Sleep(500);
    }

}