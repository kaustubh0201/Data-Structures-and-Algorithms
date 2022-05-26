#include<iostream>

using namespace std;

int minSwaps(int arr[], int n, int k){

    int less_val = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] <= k)
            less_val++;
    }

    int more_val = 0;

    for(int i = 0; i < less_val; i++){
        if(arr[i] > k)
            more_val++;
    }


    int min_swaps = more_val;

    for(int i = 0, j = less_val; j < n; i++, j++){

        if(arr[i] > k)
            more_val--;

        if(arr[j] > k)
            more_val++;

        min_swaps = min(min_swaps, more_val);
    }

    return min_swaps;
}

int main(void){

    int arr[] = {2, 1, 3, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << minSwaps(arr, n, k) << endl;

    return 0;
}
