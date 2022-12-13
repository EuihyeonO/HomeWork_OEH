#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

class obstacle : public ConsoleGameObject
{

public:
	obstacle();
	~obstacle();

	obstacle(const obstacle& _Other) = delete;
	obstacle(obstacle&& _Other) noexcept = delete;
	obstacle& operator=(const obstacle& _Other) = delete;
	obstacle& operator=(obstacle&& _Other) noexcept = delete;

	void SetObstacle(const int4& size);

	void RenderObstacle();
	
	bool isThereObstacle(int4 _pos);

protected:

private:
	
	int4 mySize = {0,0};
	obstacle** MapObstacle;
};

