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

int main()
{
    ShootingMap NewMap;
    Player NewPlayer;

    NewPlayer.SetPos({ 2, 2 });

    NewMap.Init('o');


    while (true)
    {
        system("cls");

        // �����̰�
        NewPlayer.Update(NewMap);

        // �����ϰ�.
        NewMap.SetTile(NewPlayer.GetPos(), NewPlayer.GetDisplayChar());

        // �׷�����.
        NewMap.Render();
        // 1000 ��
        Sleep(100);
    }

}