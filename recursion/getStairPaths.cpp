#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getStairPaths(int n)
{
    if (n <= 0)
    {
        vector<string> output;
        if (n == 0)
        {
            output.push_back("");
        }
        return output;
    }

    vector<string> smallAns1 = getStairPaths(n - 1);
    vector<string> smallAns2 = getStairPaths(n - 2);
    vector<string> smallAns3 = getStairPaths(n - 3);
    vector<string> output;

    for (string s : smallAns1)
    {
        output.push_back('1' + s);
    }

    for (string s : smallAns2)
    {
        output.push_back('2' + s);
    }

    for (string s : smallAns3)
    {
        output.push_back('3' + s);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<string> output = getStairPaths(n);
    int cnt = 0;

    cout << '[';
    for (string str : output)
    {
        if (cnt != output.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}