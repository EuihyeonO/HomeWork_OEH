#include <iostream>

int StringCount(const char* _String)
{
    int len = 0;

    for (int i = 0; _String[i] != 0; i++)
    {
        len++;
    }
    return len;
}

int main()
{
    int Len0 = StringCount("aaaaa");
    int Len1 = StringCount("fasdjklfasd");
    int Len2 = StringCount("wew00000");
    int Len3 = StringCount("gnvmkv");

    printf("%d", Len2);
}
