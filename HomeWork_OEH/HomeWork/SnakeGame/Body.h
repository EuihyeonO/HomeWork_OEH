#pragma once
#include "Part.h"

// Ό³Έν :
class Body : public Part
{
public:
	static void CreateBody(int4 _pos);

	static Body* GetCurBody();

	// constrcuter destructer
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	void Update() override;
	void static deleteBody();

	static int GetNumOfCurBody()
	{
		return NumOfCurBody;
	}

protected:

private:
	Body();

	static Body* CurBody[100];
	static int NumOfCurBody;
};

