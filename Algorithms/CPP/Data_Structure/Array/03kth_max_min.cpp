#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

// using the set data structure available in CPP STL
// O(logn) for average case and O(n) for worst case
int kthsmallest_set(int arr[], int n, int k)
{
    set<int> s(arr, arr + n);
    auto itr = s.begin();

    advance(itr, k-1);

    return *itr;
}

// using sort function which uses O(n logn) time
int kthsmallest_sort(int arr[], int n, int k)
{
    sort(arr, arr + n);

    return arr[k - 1];
}

int main(void)
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;

    cout << kthsmallest_set(arr, n, k) << endl;

    return 0;
}
