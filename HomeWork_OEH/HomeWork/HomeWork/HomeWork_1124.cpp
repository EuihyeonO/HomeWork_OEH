/* 
숙제 1: bool StringCompare
두개의 문자열을 비교하여 참과 거짓으로 반환하는 함수

숙제 2: char Arr[20] = "aaabbbccc";
StringChange(Arr, "bbb", "ccc");
두번째 인자를 세번째 인자로 바꾸는 것 

숙제 3: 문자열 뒤에 문자를 덛붙히는 함수
StringMerge 를 구현할 것
*/

#include <iostream>
#include <conio.h>

int StringSize(const char* _String)
{
    int len = 0;

    for (int i = 0; _String[i] != 0; i++)
    {
        len++;
    }
    return len; 
}

bool StringCompare(const char* Text_1, const char* Text_2) 
{

	{
		for (int i = 0; Text_1[i] != 0; i++)
		{
			if (Text_1[i] != Text_2[i] || Text_2[i] == 0)
			{
				return false;
			}
		}
		return true;
	}
}

char* StringChange(char* String, const char* Text_1, const char* Text_2) 
{
	int count = 0;
	int compare_count = 0;

	while (String[count] != 0)
	{
		if (StringCompare(Text_1, String + count) == true)
		{
			for (int i = 0; i < StringSize(Text_1); i++)
			{
				String[count + i] = Text_2[i];
			}

			return String;
		}
		count++;
	}
}

char* StringMerge(char* String, const int String_len, const char* Text_1)
{
	int count = StringSize(String);
	
	for (int i = 0; (count + i < String_len) || i < StringSize(Text_1); i++)
	{
		String[count + i] = Text_1[i];
	}

	String[String_len - 1] = 0;

	return String;
}

int main() {

	char Arr1[20] = "a111a222a333";
	char Arr2[10] = "111";
	char Arr3[10] = "222";
	char Arr4[10] = "333";
	char Arr5[10] = "111";
	char Arr6[10] = "22";
	char Arr7[10] = "333";

	printf("비교함수 결과 (1이 출력시 같은 문자열, 0이 출력시 다른 문자열)\n");
	printf("111, 222 : %d\n", StringCompare(Arr1, Arr2));
	printf("111, 111 : %d\n", StringCompare(Arr2, Arr5));
	printf("222, 111 : %d\n", StringCompare(Arr3, Arr2));
	printf("222, 22 : %d\n", StringCompare(Arr3, Arr6));
	printf("333, 333 : %d\n\n", StringCompare(Arr4, Arr7));

	printf("교체함수 결과\n\na111a222a333에서 111을 333으로 교체\n");
	printf("%s\n\n", StringChange(Arr1,Arr2,Arr3));
	printf("a333a222a333에서 222를 333으로 교체\n");
	printf("%s\n\n", StringChange(Arr1, Arr3, Arr4));
	printf("a333a222a333에서 앞의 333을 111으로 교체\n");
	printf("%s\n\n", StringChange(Arr1, Arr4, Arr2));
	printf("a111a222a333에서 333을 111으로 교체\n");
	printf("%s\n\n", StringChange(Arr1, Arr4, Arr2));

	printf("덛붙히는 함수 결과\n");
	printf("111 뒤에 222붙힘\n");
	printf("%s\n\n", StringMerge(Arr2, 10, Arr3));
	printf("111222뒤에 333붙힘\n");
	printf("%s\n\n", StringMerge(Arr2, 10, Arr4));
	printf("222뒤에 22붙힘\n");
	printf("%s\n\n", StringMerge(Arr3, 10, Arr6));
	printf("333뒤에 111붙힘\n");
	printf("%s\n\n", StringMerge(Arr7, 10, Arr5));



	_getch();
}