#include<iostream>
#include<algorithm>

using namespace std;

void merge_two_arrays_optimized(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0, k = m - 1;

    while(i <= k and j < n)
    {
        if(arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr1[k], arr2[j]);
            k--;
            j++;
        }
    }

    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
}

void merge_two_arrays(int arr1[], int arr2[], int m, int n)
{
    for(int i = n - 1; i >= 0; i--)
    {
        int last = arr1[m-1];
        int j;

        for(j = m - 2; j >= 0 and arr1[j] > arr2[i]; j--)
        {
            arr1[j + 1] = arr1[j];
        }

        if(j != m - 2 || last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
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
    int arr1[] = { 1, 5, 9, 10, 15, 20 };
    int arr2[] = { 2, 3, 8, 13 };

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    
    merge_two_arrays_optimized(arr1, arr2, m, n);

    printArray(arr1, n);
    printArray(arr2, n);

    return 0;
}
