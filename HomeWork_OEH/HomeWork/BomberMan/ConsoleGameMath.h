#pragma once


class int4
{
public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 0;

	int4& operator+=(const int4& _pos)
	{
		X += _pos.X;
		Y += _pos.Y;

		return *this;
	}

	bool operator==(const int4& _pos)
	{
		return X == _pos.X && Y == _pos.Y;
	}
};