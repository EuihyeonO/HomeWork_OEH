#include "VirtualFunc.h"
#include <iostream>


//객체를 배열로 선언했기에, 모든 객체가 메모리에 연속적으로 위치
//아래 메인함수의 각각의 결과를 보면
//객체의 위치 +8 -> 멤버함수 name의 위치
//멤버함수 name의 위치 +4 -> 멤버함수 age의 위치
//멤버함수 age의 위치 +4 -> 다음 객체의 위치

//이렇게 위치하고 있다.
//바이트패딩에 의해, char형인 name이 4바이트를 차지하고, int형인 age가 4바이트를 차지하므로
//멤버함수 name과 age의 주소에서 4바이트 이후에 다음 데이터를 위치하게 된다.

//반면, 객체의 첫 주소와 멤버함수 name의 주소차이는 8만큼이 나는데, 그렇다면 8의 크기만큼의 무언가를 앞에 가지고 있다는 것이다.
//이는 가상함수 포인터 vfptr의 크기 8바이트와 일치하며, 모든 객체가 객체의 첫 주소와 name의 주소가 8만큼 차이나는 것으로 보아
//모든 객체는 생성당시 맨 앞에 vfptr을 할당하고, 그 뒤에 멤버변수를 할당하게 되는 것을 알 수 있다.

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