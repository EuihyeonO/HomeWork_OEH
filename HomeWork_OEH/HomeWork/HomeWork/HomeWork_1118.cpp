//#include <iostream>
//#include <conio.h>
//
//int PlayerAtt = 20;
//int PlayerHp = 200;
//
//int MonsterAtt = 10;
//int MonsterHp = 100;
//
//void PlayerStatus()
//{
//    printf_s("플레이어=====================================\n");
//    printf_s("공격력 = %d \n", PlayerAtt);
//    printf_s("체  력 = %d \n", PlayerHp);
//    printf_s("============================================\n");
//}
//
//void MonsterStatus()
//{
//    printf_s("몬스터=====================================\n");
//    printf_s("공격력 = %d \n", MonsterAtt);
//    printf_s("체  력 = %d \n", MonsterHp);
//    printf_s("===========================================\n");
//}
//
//void PlayerDamage(int _Damage)
//{
//    PlayerHp -= _Damage;
//    int Input = 0;
//    printf_s("플레이어가 %d데미지를 받았습니다.\n", _Damage);
//    Input = _getch();
//    printf_s("플레이어는 %d체력이 남았습니다.\n", PlayerHp);
//    Input = _getch();
//}
//
//void MonsterDamage(int _Damage)
//{
//    MonsterHp -= _Damage;
//
//    int Input = 0;
//    printf_s("몬스터가 %d데미지를 받았습니다.\n", _Damage);
//    Input = _getch();
//    printf_s("몬스터는 %d체력이 남았습니다.\n", MonsterHp);
//    Input = _getch();
//}
//
//int main()
//{
//    PlayerStatus();
//    MonsterStatus();
//
//    _getch();
//
//    while (MonsterHp > 0 && PlayerHp > 0)
//    {
//
//
//        {
//            MonsterHp -= PlayerAtt;
//
//            system("cls");
//            int Input = 0;
//
//            PlayerStatus();
//            MonsterStatus();
//
//            printf_s("몬스터가 %d데미지를 받았습니다.\n", PlayerAtt);
//            printf_s("몬스터는 %d체력이 남았습니다.\n", MonsterHp);
//            Input = _getch();
//        }
//
//        {
//            PlayerHp -= MonsterAtt;
//            system("cls");
//            int Input = 0;
//
//            PlayerStatus();
//            MonsterStatus();
//
//            printf_s("플레이어가 %d데미지를 받았습니다.\n", MonsterAtt);
//            printf_s("플레이어는 %d체력이 남았습니다.\n", PlayerHp);
//            Input = _getch();
//        }
//    }
//}
