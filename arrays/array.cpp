#include <iostream>
using namespace std;

int findUnique(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                break;
            }
        }
        if (j == n)
        {
            return arr[i];
        }
    }
}

int findDup(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
}

void intersection(int arr1[], int n1, int arr2[], int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
            }
            arr2[j] = INT_MIN;
            break;
        }
    }
}

void pairSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                if (arr[i] < arr[j])
                {
                    cout << arr[i] << " " << arr[j] << endl;
                }
                else
                {
                    cout << arr[j] << " " << arr[i] << endl;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {0, 7, 2, 5, 4, 7, 1, 3, 6};
    int n = 7;
    cout << findDup(arr, n);
}