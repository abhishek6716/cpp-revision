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

bool checkPermutation(char str1[], char str2[])
{
    int freq[256];
    for (int i = 0; i < 256; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; str1[i] != '\0'; i++)
    {
        freq[str1[i]]++;
    }

    for (int j = 0; str2[j] != '\0'; j++)
    {
        freq[str2[j]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void removeConseDup(char str[])
{
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (str[i] == str[i - 1])
        {
            str[i - 1] = ' ';
        }
    }

    int space = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            char temp = str[i];
            str[i] = str[space];
            str[space] = temp;
            space++;
        }
    }
}

void removeAllOccurenceOfChar(char str[], char c)
{
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != c)
        {
            str[k] = str[i];
            k++;
        }
    }
    str[k] = '\0';
}

char heighestOccuringChar(char str[])
{
    int arr[26] = {0};
    int maxFreq = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        arr[int(str[i]) - 'a']++;
        maxFreq = max(maxFreq, arr[int(str[i]) - 'a']);
    }

    char ans;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (arr[int(str[i]) - 'a'] == maxFreq)
        {
            ans = str[i];
            break;
        }
    }
    return ans;
}

void stringCompression(char str[])
{
    int cnt = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == str[i + 1])
        {
            cnt++;
        }
        else
        {
            if (cnt != '1')
            {
                str[i] = char(cnt);
            }
            cnt = '1';
        }
    }
    removeConseDup(str);
}

int main()
{
    char name[100];
    cin >> name;
    printAllPrefixes(name);
}