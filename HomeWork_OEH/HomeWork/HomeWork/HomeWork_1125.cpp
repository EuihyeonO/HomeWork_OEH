/*
1. 정수의 길이를 반환하는 함수

2. 정수를 문자열로 변환하는 함수 

3. 문자열을 정수로 변환하는 함수
*/

#include <iostream>

int StringSize(char* const _String) //이전에 만들었던 문자열의 길이를 반환하는 함수
{
	int len = 0;

	for (int i = 0; _String[i] != 0; i++)
	{
		len++;
	}
	return len;
}


int NumberLength(int num) //정수의 길이를 반환하는 함수
{
	int length_num = 0;

	while (num >= 1) 
	{
		length_num++;
		num /= 10;
	}
	
	return length_num;
}

char* ChangeNumberToString(char* const string, int string_len, int number) //정수를 문자열로 변환하는 함수
{

	int number_len = NumberLength(number);
	int length_count = 1;


	for (int i = number_len - 1; i >= 0; i--)
	{
		string[i] = (number / length_count) % 10 + '0';
		length_count *= 10;
	}
	
	string[number_len] = 0; //문자열의 마지막을 알리는 0을 삽입

	return string;
}

int ChangeStringToNumber(char* const string) //문자열을 정수로 변환하는 함수
{
	int number = 0;
	int length_count=1;

	for (int i = StringSize(string); i > 0; i--)
	{
		number += (string[i - 1] - '0') * length_count;
		length_count *= 10;
	}

	return number;
}


int main()
{
	char arr1[10];
	char arr2[10] = "1234567";
	int num = 0;

	int test_num = 1234567;
	int num_length = NumberLength(test_num);

	printf_s("1234567의 길이 반환 결과: %d\n\n", num_length);

	ChangeNumberToString(arr1, 30, 987654321);
	printf_s("정수 1324567을 문자열로 변환 결과 : %s\n\n", arr1);
	
	num = ChangeStringToNumber(arr2);
	printf_s("문자열 1234567을 정수로 변환 결과: %d\n\n", num);

	return 0;
}


