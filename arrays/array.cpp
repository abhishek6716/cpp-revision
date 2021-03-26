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

void sort01(int arr[], int n)
{
    int i = 0;
    int nextZero = 0;
    int nextTwo = n - 1;
    while (i <= nextTwo)
    {
        if (arr[i] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[nextZero];
            arr[nextZero] = temp;
            i++;
            nextZero++;
        }
        else if (arr[i] == 2)
        {
            int temp = arr[i];
            arr[i] = arr[nextTwo];
            arr[nextTwo] = temp;
            nextTwo--;
        }
        else
        {
            i++;
        }
    }
}

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    int i = size1 - 1;
    int j = size2 - 1;
    int carry = 0;
    int k = max(size1, size2);

    while (i >= 0 && j >= 0)
    {
        int sum = input1[i] + input2[j] + carry;
        output[k] = sum % 10;
        carry = sum / 10;
        i--;
        j--;
        k--;
    }

    while (i >= 0)
    {
        int sum = input1[i] + carry;
        output[k] = sum % 10;
        carry = sum / 10;
        i--;
        k--;
    }

    while (j >= 0)
    {
        int sum = input2[j] + carry;
        output[k] = sum % 10;
        carry = sum / 10;
        j--;
        k--;
    }
}

void pushZeoresToEnd(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[k] = arr[i];
            k++;
        }
    }
    for (; k < n; k++)
    {
        arr[k] = 0;
    }
}

void rotateArray(int arr[], int n, int d)
{
    int r = 1;
    while (r <= d)
    {
        int temp = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
        r++;
    }
}

int secondLargest(int arr[], int n)
{
    int max1, max2;
    max1 = max2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] > max2 && arr[i] < max1)
        {
            max2 = arr[i];
        }
    }
    return max2;
}

int arrRotation(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return i + 1;
        }
    }
}

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    int i = size1 - 1;
    int j = size2 - 1;
    int carry = 0;
    int k = max(size1, size2);

    while (i >= 0 && j >= 0)
    {
        int sum = input1[i] + input2[j] + carry;
        output[k] = sum % 10;
        carry = sum / 10;
        i--;
        j--;
        k--;
    }

    while (i >= 0)
    {
        int sum = input1[i] + carry;
        output[k] = sum % 10;
        carry = sum / 10;
        i--;
        k--;
    }

    while (j >= 0)
    {
        int sum = input2[j] + carry;
        output[k] = sum % 10;
        carry = sum / 10;
        j--;
        k--;
    }
}

int main()
{
    int arr[] = {0, 1, 1, 0, 0, 1, 1, 0, 0};
    int n = 7;
    sort01(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return EXIT_SUCCESS;
}