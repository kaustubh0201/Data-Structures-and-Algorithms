#include<iostream>

using namespace std;

int TrappingRainFindingHeight(int arr[], int n){

    int water = 0;

    for(int i = 1; i < n; i++){
        
        int left = arr[i];
        for(int j = 0; j < i; j++){
            left = max(left, arr[j]);
        }

        int right = arr[i];
        for(int j = i + 1; j < n; j++){
            right = max(right, arr[j]);
        }

        water += (min(left, right) - arr[i]);
    }

    return water;

}

int TrappingRainDP(int arr[], int n){

    int water = 0;

    int left[n];
    int right[n];
    
    left[0] = arr[0];
    for(int i = 1; i < n; i++){
        left[i] = max(left[i - 1], arr[i]);
    }

    right[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        right[i] = max(right[i + 1], arr[i]);
    }

    for(int i = 1; i < n - 1; i++){
        int highest = min(left[i-1], right[i+1]);

        if(highest > arr[i])
            water += (highest - arr[i]);
    }

    return water;

}

int TrappingRainOptimizedDP(int arr[], int n){

    int water = 0;

    int left_max = 0;
    int right_max = 0;

    int lo = 0;
    int hi = n - 1;

    while(lo <= hi){

        if(arr[lo] < arr[hi]){

            if(arr[lo] > left_max){
                left_max = arr[lo];
            }else{
                water += (left_max - arr[lo]);
            }
            lo++;
        }else{

            if(arr[hi] > right_max){
                right_max = arr[hi];
            }else{
                water += (right_max - arr[hi]);
            }
            hi--;
        }
    }

    return water;
}


int main(void){

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << TrappingRainOptimizedDP(arr, n) << endl;

    return 0;
}
