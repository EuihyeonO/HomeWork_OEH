#include "VirtualFunc.h"
#include <iostream>

Parent::Parent()
{
}

Parent::~Parent()
{

}

void Parent::ShowMyInfo()
{
	printf("parent\n");
}

Child::Child()
{
}

Child::~Child()
{
}

void Child::ShowMyInfo()
{
	printf("Child\n");
}