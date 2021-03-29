#include <iostream>
#include <cstring>
using namespace std;

int length(char name[])
{
    int cnt = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        cnt++;
    }
    return cnt;
}

bool checkPalindrome(char str[])
{
    int len = length(str);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}

void replaceChar(char str[], char c1, char c2)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c1)
        {
            str[i] = c2;
        }
    }
    cout << str;
}

void reverseStr(char str[])
{
    int len = length(str);
    int i = 0, j = len - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    cout << str;
}

void printAllPrefixes(char str[])
{
    int len = length(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << str[j];
        }
        cout << endl;
    }
}

void trimSpaces(char str[])
{
    int i = 0, j = 0;
    while (str[i] != '\n')
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
}

void PrintAllSubstrings(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << str[k];
            }
            cout << endl;
        }
    }
}

int main()
{
    char name[100];
    cin >> name;
    printAllPrefixes(name);
}