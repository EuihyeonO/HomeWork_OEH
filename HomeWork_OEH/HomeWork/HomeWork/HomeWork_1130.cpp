#include <iostream>


class Test {

public:
	int num = 10;

public:
	Test operator+(Test& _test)
	{
		Test test;
		test.num += _test.num;
		return test;
	}

	Test operator-(Test& _test)
	{
		Test test;
		test.num -= _test.num;
		return test;
	}

	Test operator*(Test& _test)
	{
		Test test;
		test.num *= _test.num;
		return test;
	}
	Test operator/(Test& _test)
	{
		Test test;
		test.num /= _test.num;
		return test;
	}

};

int main()
{

	Test test0;
	Test test1;
	Test test2;

	test0 = test1 + test2;
	
	printf("���ϱ� ��� : %d\n", test0.num);

	test0 = test1 - test2;

	printf("���� ��� : %d\n", test0.num);

	test0 = test1 * test2;

	printf("���ϱ� ��� : %d\n", test0.num);

	test0 = test1 / test2;

	printf("������ ��� : %d\n", test0.num);

}