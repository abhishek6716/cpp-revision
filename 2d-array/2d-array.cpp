#include <iostream>
using namespace std;

void print2Darray(int arr[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void columnWiseSum(int arr[][100], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

void findLargest(int arr[][100], int m, int n)
{
    int maxR = INT_MIN;
    int Rno;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxR)
        {
            maxR = sum;
            Rno = i;
        }
    }

    int maxC = INT_MIN;
    int Cno;
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i][j];
        }
        if (sum > maxC)
        {
            maxC = sum;
            Cno = j;
        }
    }

    if (maxR > maxC)
    {
        cout << "Row No:" << Rno + 1 << " "
             << "Sum:" << maxR;
    }
    else
    {
        cout << "Column No:" << Cno + 1 << " "
             << "Sum:" << maxC;
    }
}

void wavePrint(int arr[][100], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

void printSpiral(int arr[][100], int m, int n)
{
    if (m == 0 || n == 0)
    {
        return;
    }
    int i, rowS = 0, colS = 0;
    int noEle = m * n, cnt = 0;

    while (cnt < noEle)
    {
        for (i = colS; cnt < noEle && i < n; i++)
        {
            cout << arr[rowS][i] << " ";
            cnt++;
        }
        rowS++;
        for (i = rowS; cnt < noEle && i < m; i++)
        {
            cout << arr[i][n - 1] << " ";
            cnt++;
        }
        n--;
        for (i = n - 1; cnt << noEle && i >= colS; i--)
        {
            cout << arr[m - 1][i] << " ";
            cnt++;
        }
        m--;
        for (i = m - 1; cnt << noEle && i >= rowS; i--)
        {
            cout << arr[i][colS] << " ";
            cnt++;
        }
        colS++;
    }
}

int main()
{
    int arr[100][100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    print2Darray(arr, m, n);
}