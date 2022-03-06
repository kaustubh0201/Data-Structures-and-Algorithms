#include<iostream>
#include<algorithm>

using namespace std;

// counting the 0s, 1s and 2s 
// this is not a good solution because if the 0s, 1s and 2s were structures then that would have given serious problem
// it also takes two iterations O(n)
void sort012_counting(int arr[], int n)
{
    int zeros = 0, ones = 0, twos = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            zeros++;
        else if(arr[i] == 1)
            ones++;
        else if(arr[i] == 2)
            twos++;
    }

    int i;

    for(i = 0; i < zeros; i++)
        arr[i] = 0;    

    for(i = i; i < (zeros + ones); i++)
        arr[i] = 1;

    for(i = i; i < n; i++)
        arr[i] = 2;
}

// doing it like the dutch flag problem
// there are three conditions according to whicb we swap the mid index
void sort012_dutch(int arr[], int n)
{
    int low = 0, mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

int main(void)
{
    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, n);

    sort012_dutch(arr, n);

    printArray(arr, n);


    return 0;
}
