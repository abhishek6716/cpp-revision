#include <iostream>
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

void reverseLineWordWise(char str[])
{
    int len = length(str);
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
    int s = 0, e = len - 2;
    reverseWord(str, s, e);
    cout << str << endl;
}

int main()
{
    cout << "enter stream of strings: ";
    char str[100];
    cin.getline(str, 100);
    reverseLineWordWise(str);
}