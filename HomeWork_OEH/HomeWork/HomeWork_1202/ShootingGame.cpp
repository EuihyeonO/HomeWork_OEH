// ���� 1. ȭ�� �ٱ����� �������� ���弼��. (��)
// ���� 2. �ܻ� ���켼��. (��)

// �̰� ���ص� �˴ϴ�.
// �̰͵� ���ߴ�.
// ���� 3. ���͸� 1���� ���弼��.
// ���� 4. �Ѿ��� 1�� ���弼��
// ���� 5. �Ѿ��� ���͸� ������ �Ѵ� ������� �ϼ���.

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

        // �����̰�
        NewPlayer.Update(NewMap, NewBullet,NewMonster);

        // �����ϰ�.
        NewMap.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

        // �׷�����.
        NewMap.Render();
        // 1000 ��
        Sleep(500);
    }

}