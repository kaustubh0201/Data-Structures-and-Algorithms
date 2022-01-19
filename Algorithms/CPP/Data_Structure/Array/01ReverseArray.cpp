#include<iostream>

using namespace std;

// making two pointers from the right and the left
void reverse_recursion(int arr[], int start, int end)
{
    // base case
    if(start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse_recursion(arr, start + 1, end - 1);
}

void reverse_ptrs(int arr[], int n)
{
    int start = 0;
    int end = n-1;

    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main(void)
{
    int arr[] = {2, 5, 1, 9, 4, 3};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);

    reverse_recursion(arr, 0, n - 1);

    printArray(arr, n);
    
    reverse_ptrs(arr, n);

    printArray(arr, n);

    return 0;
}
