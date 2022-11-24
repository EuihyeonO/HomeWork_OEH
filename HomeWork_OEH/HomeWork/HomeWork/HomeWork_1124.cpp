/* 
���� 1: bool StringCompare
�ΰ��� ���ڿ��� ���Ͽ� ���� �������� ��ȯ�ϴ� �Լ�

���� 2: char Arr[20] = "aaabbbccc";
StringChange(Arr, "bbb", "ccc");
�ι�° ���ڸ� ����° ���ڷ� �ٲٴ� �� 

���� 3: ���ڿ� �ڿ� ���ڸ� �������� �Լ�
StringMerge �� ������ ��
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

int main() {

	char Arr1[20] = "a111a222a333";
	char Arr2[10] = "111";
	char Arr3[10] = "222";
	char Arr4[10] = "333";
	char Arr5[10] = "111";
	char Arr6[10] = "22";
	char Arr7[10] = "333";

	printf("���Լ� ��� (1�� ��½� ���� ���ڿ�, 0�� ��½� �ٸ� ���ڿ�)\n");
	printf("111, 222 : %d\n", StringCompare(Arr1, Arr2));
	printf("111, 111 : %d\n", StringCompare(Arr2, Arr5));
	printf("222, 111 : %d\n", StringCompare(Arr3, Arr2));
	printf("222, 22 : %d\n", StringCompare(Arr3, Arr6));
	printf("333, 333 : %d\n\n", StringCompare(Arr4, Arr7));

	printf("��ü�Լ� ���\n\n(a222a222a333)�� ��µǾ�� ��\n");
	printf("%s\n\n", StringChange(Arr1,Arr2,Arr3));
	printf("(a333a222a333)�� ��µǾ�� ��\n");
	printf("%s\n\n", StringChange(Arr1, Arr3, Arr4));
	printf("(a111a222a333)�� ��µǾ�� ��\n");
	printf("%s\n\n", StringChange(Arr1, Arr4, Arr2));
	printf("(a111a222a111)�� ��µǾ�� ��\n");
	printf("%s\n\n", StringChange(Arr1, Arr4, Arr2));


	_getch();
}