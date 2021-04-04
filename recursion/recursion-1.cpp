#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallAns = factorial(n - 1);
    return n * smallAns;
}

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallAns = power(x, n - 1);
    return x * smallAns;
}

void print(int n)
{
    if (n == 1)
    {
        return;
    }
    print(n - 1);
    cout << n << " ";
}

int noOfDigits(int n)
{
    if (n / 10 == 0)
    {
        return 1;
    }
    int smallAns = noOfDigits(n / 10);
    return smallAns + 1;
}

int nthfibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int smallAns = nthfibo(n - 1) + nthfibo(n - 2);
    return smallAns;
}

bool IsSorted1(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    bool smallAns = IsSorted1(arr + 1, n - 1);
    return smallAns;
}

bool IsSorted2(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    int smallAns = IsSorted2(arr + 1, n - 1);
    if (!smallAns || arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

int sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallAns = sum(arr + 1, n - 1);
    return arr[0] + smallAns;
}

bool checkNo1(int arr[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == x)
    {
        return true;
    }
    bool smallAns = checkNo1(arr + 1, n - 1, x);
    return smallAns;
}

bool checkNo2(int arr[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    bool smallAns = checkNo2(arr + 1, n - 1, x);
    if (smallAns)
    {
        return true;
    }
    else
    {
        if (arr[0] == x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// good solution
int firstIndex_1(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == x)
    {
        return 0;
    }
    int smallAns = firstIndex_1(arr + 1, n - 1, x);
    if (smallAns != -1)
    {
        return smallAns + 1;
    }
    else
    {
        return smallAns;
    }
}

// not good solution
int firstIndex_2(int arr[], int n, int x)
{
    if (n == 1)
    {
        if (arr[0] == x)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    int ans = firstIndex_2(arr + 1, n - 1, x);
    if (ans == -1)
    {
        if (arr[0] == x)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (arr[0] == x)
        {
            return 0;
        }
        else
        {
            return ans + 1;
        }
    }
}

// forward
int lastIndex_1(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    int ans = lastIndex_1(arr + 1, n - 1, x);
    if (ans != -1)
    {
        return ans + 1;
    }
    else
    {
        if (arr[0] != x)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

// backward
int lastIndex_2(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[n - 1] == x)
    {
        return n - 1;
    }
    int ans = lastIndex_2(arr, n - 1, x);
    if (ans == -1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

// backward
int RetAllIndexes_1(int arr[], int n, int x, int output[])
{
    if (n == 0)
    {
        return 0;
    }
    int ans = RetAllIndexes_1(arr, n - 1, x, output);
    if (arr[n - 1] == x)
    {
        int res = ans + 1;
        output[res - 1] = n - 1;
        return res;
    }
    else
    {
        return ans;
    }
}

// forward
int RetAllIndexes_2(int arr[], int n, int x, int output[])
{
    if (n == 0)
    {
        return 0;
    }
    int ans = RetAllIndexes_2(arr + 1, n - 1, x, output);
    for (int i = 0; i < ans; i++)
    {
        output[i] = output[i] + 1;
    }
    if (arr[0] == x)
    {
        int res = ans + 1;
        for (int i = res - 1; i >= 1; i--)
        {
            output[i] = output[i - 1];
        }
        output[0] = 0;
        return res;
    }
    else
    {
        return ans;
    }
}

int multiplication(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    int smallAns = multiplication(m, n - 1);
    return smallAns + m;
}

int noOfZeroes(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n >= 1 && n <= 9)
    {
        return 0;
    }
    int ans = noOfZeroes(n / 10);
    if (n % 10 == 0)
    {
        return ans + 1;
    }
    else
    {
        return ans;
    }
}

double geometricSum(int k)
{
    if (k == 0)
    {
        return 1;
    }
    double smallAns = geometricSum(k - 1);
    return smallAns + (1 / power(2, k));
}

bool helper(char input[], int start, int end)
{
    if (end <= 0)
    {
        return true;
    }
    if (input[start] != input[end])
    {
        return false;
    }
    bool ans = helper(input, start + 1, end - 1);
    if (ans)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Ispelindrome(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    cout << len << endl;
    return helper(input, 0, len - 1);
}

int sumOfDigits(int n)
{
    if (n <= 9)
    {
        return n;
    }
    int smallAns = sumOfDigits(n / 10);
    return smallAns + (n % 10);
}

// m-1
void replacePI(char str[])
{
    if (strlen(str) <= 0)
    {
        return;
    }
    if (str[0] == 'p')
    {
        if (str[1] == 'i')
        {
            int len = strlen(str);
            for (int i = len; i >= 0; i--)
            {
                str[i + 2] = str[i];
            }
            str[0] = '3';
            str[1] = '.';
            str[2] = '1';
            str[3] = '4';
            replacePI(str + 4);
        }
        else
        {
            replacePI(str + 2);
        }
    }
    else
    {
        replacePI(str + 1);
    }
}

// m-2
void helper(char input[], int start)
{
    if (input[start] == '\0')
    {
        return;
    }
    helper(input, start + 1);
    if (input[start] == 'p' && input[start + 1] == 'i')
    {
        for (int i = strlen(input); i >= start + 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[start] = '3';
        input[start + 1] = '.';
        input[start + 2] = '1';
        input[start + 3] = '4';
    }
}
void ReplacePI(char input[])
{
    helper(input, 0);
}

void removeX(char str[])
{
    if (strlen(str) <= 0)
    {
        return;
    }
    removeX(str + 1);
    if (str[0] == 'x')
    {
        for (int i = 1; i <= strlen(str); i++)
        {
            str[i - 1] = str[i];
        }
    }
}

// m-1
int helper1(char input[], int last)
{
    if (last == 0)
    {
        return input[last] - '0';
    }
    int smallAns = helper1(input, last - 1);
    int a = input[last] - '0';
    return smallAns * 10 + a;
}
int StringToNum_2(char input[])
{
    int len = strlen(input);
    return helper1(input, len - 1);
}

// m-2
int StringToNumber(char input[])
{
    int n = strlen(input);
    if (n == 1)
    {
        int a = input[0] - '0';
        return a;
    }
    int y = StringToNumber(input + 1);
    int x = input[0] - '0';
    x = x * pow(10, n - 1) + y;
    return x;
}

void pairStar(char str[])
{
    if (strlen(str) <= 0)
    {
        return;
    }
    if (str[0] == str[1])
    {
        for (int i = strlen(str); i >= 1; i--)
        {
            str[i + 1] = str[i];
        }
        str[1] = '*';
        pairStar(str + 3);
    }
    else
    {
        pairStar(str + 1);
    }
}

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << source << " " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

void replaceCharRecur(char str[], char c1, char c2)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == c1)
    {
        str[0] = c2;
    }
    replaceCharRecur(str + 1, c1, c2);
}

void removeConseDup(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == str[1])
    {
        for (int i = 1; i <= strlen(str); i++)
        {
            str[i - 1] = str[i];
        }
        removeConseDup(str);
    }
    else
    {
        removeConseDup(str + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
}