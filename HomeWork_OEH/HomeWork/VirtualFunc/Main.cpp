#include "VirtualFunc.h"
#include <iostream>


//��ü�� �迭�� �����߱⿡, ��� ��ü�� �޸𸮿� ���������� ��ġ
//�Ʒ� �����Լ��� ������ ����� ����
//��ü�� ��ġ +8 -> ����Լ� name�� ��ġ
//����Լ� name�� ��ġ +4 -> ����Լ� age�� ��ġ
//����Լ� age�� ��ġ +4 -> ���� ��ü�� ��ġ

//�̷��� ��ġ�ϰ� �ִ�.
//����Ʈ�е��� ����, char���� name�� 4����Ʈ�� �����ϰ�, int���� age�� 4����Ʈ�� �����ϹǷ�
//����Լ� name�� age�� �ּҿ��� 4����Ʈ ���Ŀ� ���� �����͸� ��ġ�ϰ� �ȴ�.

//�ݸ�, ��ü�� ù �ּҿ� ����Լ� name�� �ּ����̴� 8��ŭ�� ���µ�, �׷��ٸ� 8�� ũ�⸸ŭ�� ���𰡸� �տ� ������ �ִٴ� ���̴�.
//�̴� �����Լ� ������ vfptr�� ũ�� 8����Ʈ�� ��ġ�ϸ�, ��� ��ü�� ��ü�� ù �ּҿ� name�� �ּҰ� 8��ŭ ���̳��� ������ ����
//��� ��ü�� ������� �� �տ� vfptr�� �Ҵ��ϰ�, �� �ڿ� ��������� �Ҵ��ϰ� �Ǵ� ���� �� �� �ִ�.

int main()
{
	Parent testparent[3];


	Child testchild[3];


	printf("%p\n", &testparent[0]);
	printf("%p\n", &testparent[0].name);
	printf("%p\n\n", &testparent[0].age);

	printf("%p\n", &testparent[1]);
	printf("%p\n", &testparent[1].name);
	printf("%p\n\n", &testparent[1].age);

	printf("%p\n", &testparent[2]);
	printf("%p\n", &testparent[2].name);
	printf("%p\n\n", &testparent[2].age);

	printf("%p\n", &testchild[0]);
	printf("%p\n", &testchild[0].name);
	printf("%p\n\n", &testchild[0].age);

	printf("%p\n", &testchild[1]);
	printf("%p\n", &testchild[1].name);
	printf("%p\n\n", &testchild[1].age);

	printf("%p\n", &testchild[2]);
	printf("%p\n", &testchild[2].name);
	printf("%p\n\n", &testchild[2].age);
	
	return 0;


}