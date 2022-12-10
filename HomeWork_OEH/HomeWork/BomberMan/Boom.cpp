#include "Boom.h"
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <ctime>
#include <conio.h>

int Boom::NumOfBoom = 0;

Boom::Boom()
{
	++NumOfBoom;
}

Boom::~Boom()
{
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(Boom::GetPos(), L'бс');
	--NumOfBoom;
}

Boom* Boom::DropBoom(int4 _pos, int _timestack)
{
	Boom* _boom = new Boom();
	_boom->SetPos(_pos);
	_boom->SetTimeStack(_timestack);

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(_boom->GetPos(), GetRenderChar());

	return _boom;
}

