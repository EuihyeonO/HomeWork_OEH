#include "obstacle.h"
#include "ConsoleGameScreen.h"

obstacle::obstacle()
{
	SetPos({ 0,0 });
	SetRenderChar(L'□');
}	

obstacle::~obstacle()
{
}

void obstacle::SetObstacle(const int4& size)
{
	mySize.X = size.X;
	mySize.Y = size.Y;

	MapObstacle = new obstacle * [size.Y];

	for (int i = 0; i < size.Y; i++)
	{
		MapObstacle[i] = new obstacle[size.X];
	}

	for (int i = 0; i < mySize.Y; i++)
	{
		for (int j = 0; j < mySize.X; j++)
		{
			if (i % 2 == 1 && j % 2 == 1)
			{
				MapObstacle[i][j].SetPos({ j,i }); 
			}
		}
	}

}

void obstacle::RenderObstacle()
{
	for (int i = 0; i < mySize.Y; i++)
	{
		for (int j = 0; j < mySize.X; j++)
		{
			if (i % 2 == 1 && j % 2 == 1)
			{
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(MapObstacle[i][j].GetPos(), MapObstacle[i][j].GetRenderChar());
			}
		}
	}
}

bool obstacle::isThereObstacle(int4 _pos)
{
	for (int i = 0; i < mySize.Y; i++)
	{
		for (int j = 0; j < mySize.X; j++)
		{
			if (MapObstacle[i][j].GetPos() == _pos)
			{
				return true;
			}
		}
	}

	return false;
}

void obstacle::deleteObstacle() // 멤버함수를 통해 할당한 메모리라 그런지 소멸자로 해제하면 오류가 나서 따로 해제 함수 구현
{
	for (int i = 0; i < mySize.Y; i++)
	{
		if (MapObstacle[i] != nullptr)
		{
			delete[] MapObstacle[i];
			MapObstacle[i] = nullptr;
		}
	}

	delete[] MapObstacle;
	MapObstacle = nullptr;
}