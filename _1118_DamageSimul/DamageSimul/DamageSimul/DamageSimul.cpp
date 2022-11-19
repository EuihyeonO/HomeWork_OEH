//#include <iostream>
//#include <conio.h>
//
//void CharacterStatus(int* PlayerHP, int* PlayerATT, int* MonsterHP, int* MonsterATT)
//{
//	printf("Player HP : %d\n", *PlayerHP);
//	printf("Player ATT : %d\n\n", *PlayerATT);
//	printf("Monster HP : %d\n", *MonsterHP);
//	printf("Monster ATT : %d\n\n", *MonsterATT);
//
//}
//
//
//int main()
//{
//
//	int playerHP = 100;
//	int playerATT = 10;
//	int monsterHP = 200;
//	int monsterATT = 20;
//
//	CharacterStatus(&playerHP, &playerATT, &monsterHP, &monsterATT);
//
//	while (monsterHP != 0) {
//		_getch();
//		monsterHP -= playerATT;
//		system("cls");
//		CharacterStatus(&playerHP, &playerATT, &monsterHP, &monsterATT);
//		printf("%d의 데미지를 입혔습니다.\n\n", playerATT);
//
//	}
//
//
//	printf("몬스터를 처치했습니다!!!");
//	_getch();
//
//	return 0;
//}