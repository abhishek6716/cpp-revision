#include <iostream>
#include <vector>
using namespace std;

vector<string> getSubSeq(string s)
{

    if (s == "")
    {
        vector<string> output;
        output.push_back("");
        return output;
    }

    char ch = s[0];
    string ros = s.substr(1);

    vector<string> subAns = getSubSeq(ros);
    vector<string> output;

    for (string s : subAns)
    {
        output.push_back(s);
    }

    for (string s : subAns)
    {
        output.push_back(ch + s);
    }

    return output;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = getSubSeq(s);
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