/*
1. ������ ���̸� ��ȯ�ϴ� �Լ�

2. ������ ���ڿ��� ��ȯ�ϴ� �Լ� 

3. ���ڿ��� ������ ��ȯ�ϴ� �Լ�
*/

#include <iostream>

int StringSize(char* const _String) //������ ������� ���ڿ��� ���̸� ��ȯ�ϴ� �Լ�
{
	int len = 0;

	for (int i = 0; _String[i] != 0; i++)
	{
		len++;
	}
	return len;
}


int NumberLength(int num) //������ ���̸� ��ȯ�ϴ� �Լ�
{
	int length_num = 0;

	while (num >= 1) 
	{
		length_num++;
		num /= 10;
	}
	
	return length_num;
}

char* ChangeNumberToString(char* const string, int string_len, int number) //������ ���ڿ��� ��ȯ�ϴ� �Լ�
{

	int number_len = NumberLength(number);
	int length_count = 1;


	for (int i = number_len - 1; i >= 0; i--)
	{
		string[i] = (number / length_count) % 10 + '0';
		length_count *= 10;
	}
	
	string[number_len] = 0; //���ڿ��� �������� �˸��� 0�� ����

	return string;
}

int ChangeStringToNumber(char* const string) //���ڿ��� ������ ��ȯ�ϴ� �Լ�
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

	printf_s("1234567�� ���� ��ȯ ���: %d\n\n", num_length);

	ChangeNumberToString(arr1, 30, 987654321);
	printf_s("���� 1324567�� ���ڿ��� ��ȯ ��� : %s\n\n", arr1);
	
	num = ChangeStringToNumber(arr2);
	printf_s("���ڿ� 1234567�� ������ ��ȯ ���: %d\n\n", num);

	return 0;
}


