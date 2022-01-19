#include<iostream>

using namespace std;

struct Pair
{
    int max;
    int min;
};

Pair min_max_element(int arr[], int n)
{
    Pair minmax;

    if(n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
    }

    if(arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[1];
    }

    for(int i = 2; i < n; i++)
    {
        if(arr[i] > minmax.max)
            minmax.max = arr[i];

        if(arr[i] < minmax.min)
            minmax.min = arr[i];
    }

    return minmax;
}

Pair min_max_recursion(int arr[], int low, int high)
{
    Pair minmax;

    if(high == low)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];

        return minmax;
    }

    if(high == low + 1)
    {
        if(arr[high] > arr[low])
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        else
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }

        return minmax;
    }

    Pair mmr, mml;
    int mid = (low + high) / 2;

    mml = min_max_recursion(arr, low, mid);
    mmr = min_max_recursion(arr, mid + 1, high);

    if(mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;

    if(mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;


    return minmax;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main(void)
{
    int arr[] = {2, 5, 3, 1, 8, 9};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);

    cout << min_max_recursion(arr, 0, n-1).max << endl;


    return 0;
}
