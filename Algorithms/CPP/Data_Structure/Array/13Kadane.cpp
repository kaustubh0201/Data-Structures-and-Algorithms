#include<bits/stdc++.h>

using namespace std;

int Kadane(int arr[], int n){
    int max_val = INT_MIN;
    int max_till_index = 0;

    for(int i = 0; i < n; i++){
        max_till_index = max_till_index + arr[i];

        if(max_till_index > max_val)
            max_val = max_till_index;

        if(max_till_index < 0)
            max_till_index = 0;
    }

    return max_val;
}


int main(void){
    int arr[] = {-1, -2, -3, -4, -2, -1, -8, -2};
    int len = sizeof(arr)/sizeof(int);

    cout << Kadane(arr, len) << endl;


    return 0;
}
