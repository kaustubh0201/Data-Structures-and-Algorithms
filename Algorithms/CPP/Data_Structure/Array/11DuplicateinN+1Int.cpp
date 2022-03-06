#include<iostream>

using namespace std;

// traverse the array and increment arr[arr[i]%n] by n 
// whichever position has arr[i]/n greater than 1, it will be taken account.
// the approach is that all elements are in the range 0 to n-1
// arr[i] would be greater than n only if the value "i" has appeared more than once
void duplicates(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[arr[i] % n] += n;
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        if(arr[i]/n > 1)
            cout << i << " "; 
    }

    cout << endl;
}

int main(void)
{
    int arr[] = {0, 3, 4, 7, 2, 3, 2, 8, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicates(arr, n);

    return 0;
}
