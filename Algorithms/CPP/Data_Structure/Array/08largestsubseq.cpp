#include<iostream>
#include<climits>

using namespace std;

int largest_subsequence_sum(int arr[], int n)
{
    int maxtillnow = 0;
    int lastmax = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        maxtillnow += arr[i];
        if(lastmax < maxtillnow)
            lastmax = maxtillnow;

        if(maxtillnow < 0)
            maxtillnow = 0;
    }

    return lastmax;
}

int main(void)
{
    int arr[] = {-1, -2, -3, -4};
    int n = sizeof(arr)/sizeof(int);

    cout << largest_subsequence_sum(arr, n) << endl; 

    return 0;
}
