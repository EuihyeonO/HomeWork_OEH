#include "Part.h"
#include "Body.h"

Part::Part()
{
}

Part::Part(wchar_t _Renderchar)
	: ConsoleGameObject(_Renderchar)
{

}

Part::~Part()
{
}


void Part::Update()
{

}

void Part::RecursionFrontMove()
{
	// �ǵڿ��� ȣ��ƴٰ� ġ��.

	if (nullptr == Front)
	{
		return;
	}

	SetPos(Front->GetPos());

	return Front->RecursionFrontMove();
}

void Part::RecursionBackRender()
{
	Render();

	if (nullptr == Back)
	{
		return;
	}

	return Back->RecursionBackRender();
}

bool Part::RecursionCheckOver(int4 _pos)
{
	if (Back == nullptr && Front == nullptr)
	{
		return false;
	} //���ۺ��� �����Ǵ� �� ����

	if (Back == nullptr)
	{
		if (GetPos() == _pos)
		{
			return true;
		}
		return false;
	}

	if (_pos == Back->GetPos())
	{
		return true;
	} 

	return Back->RecursionCheckOver(_pos);
}