#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int distributeChocolate(int arr[], int n, int m){

    sort(arr, arr + n);
    
    int min = INT_MAX;
    int min_index = 0;

    for(int i = m - 1; i < n; i++){
        
        if(arr[i] - arr[i - m + 1] < min){
            min_index = i;
            min = arr[i] - arr[i - m + 1];
        }
    }

    return arr[min_index] - arr[min_index - m + 1];
}

int main(void){

    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << distributeChocolate(arr, n, m) << endl;

    return 0;
}
