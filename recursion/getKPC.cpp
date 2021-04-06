#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getstring(int d)
{
    if (d == 0)
    {
        return ".;";
    }
    if (d == 1)
    {
        return "abc";
    }
    if (d == 2)
    {
        return "def";
    }
    if (d == 3)
    {
        return "ghi";
    }
    if (d == 4)
    {
        return "jkl";
    }
    if (d == 5)
    {
        return "mno";
    }
    if (d == 6)
    {
        return "pqrs";
    }
    if (d == 7)
    {
        return "tu";
    }
    if (d == 8)
    {
        return "vwx";
    }
    if (d == 9)
    {
        return "yz";
    }
}

vector<string> getKPC(string str)
{
    if (str.length() == 0)
    {
        vector<string> output;
        output.push_back("");
        return output;
    }
    char ch = str.at(0);
    string smallstr = str.substr(1);

    vector<string> smallAns = getKPC(smallstr);
    vector<string> output;

    string codeforch = getstring(ch - '0');
    for (int i = 0; i < codeforch.length(); i++)
    {
        char chcode = codeforch.at(i);
        for (string s : smallAns)
        {
            output.push_back(chcode + s);
        }
    }
    return output;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
