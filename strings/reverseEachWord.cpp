#include <iostream>
#include <cstring>
using namespace std;

void reverseWord(char str[], int s, int e)
{
    while (s < e)
    {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;
    }
}

void reverseEachWord(char str[])
{
    int len = strlen(str);
    str[len] = ' ';
    str[len + 1] = '\0';
    len++;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            reverseWord(str, j, i - 1);
            j = i + 1;
        }
    }
    cout << str;
}

int main()
{
    char str[100];
    cin >> str;
    reverseEachWord(str);
}